#include "Player.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	effect = 0;
	attackcount = 0;
	attackeffect[0] = false;
	attackeffect[1] = false;
	attackeffect[2] = false;
	attackused = -1;
	burncount = 0;
	poisoncount = 0;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

int Player::GetjustRolledDiceNum() const
{
	return justRolledDiceNum;
}

int Player::Geteffect() const
{
	return effect;
}

void Player::Seteffect(int e)
{
	effect = e;
}

int Player::GetplayerNum() const
{
	return playerNum;
}

void Player::SetTurnCount(int t)
{
	turnCount = t;
}

void Player::Setattackeffect(bool b, int t)
{
	attackeffect[t] = b;
}

void Player::Setburncount(int t)
{
	burncount = t;
}

void Player::Setpoisoncount(int t)
{
	poisoncount += t;
}

void Player::Settozero(Grid* pGrid)
{
	CellPosition StartCell(1);
	pGrid->UpdatePlayerCell(this, StartCell);
	SetWallet(100);
	turnCount = 0;
	effect = 0;
	attackcount = 0;
	attackeffect[0] = false;
	attackeffect[1] = false;
	attackeffect[2] = false;
	attackused = -1;
	burncount = 0;
	poisoncount = 0;

}


// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}

// ====== Game Functions ======



void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	
	turnCount++;

	switch (Geteffect())
	{
	case 0:
		break;
	case 1:
		turnCount--;
		Seteffect(0); //this effect lasts only one roll
		break;
	case 2:
		pOut->PrintMessage("You are denied from playing this turn. Click to continue...");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		diceNumber = 0;
		Seteffect(0); //this effect only lasts 1 turn
	}

	if (attackeffect[0])
	{
		pOut->PrintMessage("You are frozen!!");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		diceNumber = 0;
		Setattackeffect(false, 0);
	}
	if (attackeffect[1])
	{
		pOut->PrintMessage("You are burning!!");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		if (burncount > 0)
		{
			burncount--;
			pGrid->GetCurrentPlayer()->SetWallet(GetWallet()-20);
			if (burncount == 0)
			{
				Setattackeffect(false, 1);
			}
		}

	}
	if (attackeffect[2])
	{
		pOut->PrintMessage("You are poisoned!!");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		if (poisoncount > 0)
		{
			poisoncount--;
			diceNumber -= 1;
			if (poisoncount == 0)
			{
				Setattackeffect(false, 2);
			}
		}
	}


	
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (turnCount == 3)
	{
		turnCount = 0;
		bool attcked = false;
		if (diceNumber != 0 && attackcount<2)
		{
			pOut->PrintMessage("Do you wish to launch a special attack instead of recharging ? y/n");
			string ans = pIn->GetSrting(pOut);
			if (ans == "y" || ans == "Y")
			{
				attcked = true;
				attackcount++;
				pOut->PrintMessage("Choose an attack: Enter 0 for an ice attack, 1 for a fire attack, 2 for a poison attack, 3 for a lightning attack .");
				int atknum = pIn->GetInteger(pOut);
				while (atknum == attackused || atknum < 0 || atknum>3)
				{
					if (atknum == attackused)
					{
						pGrid->PrintErrorMessage("Attack already used, use a different attack");
						pOut->PrintMessage("Choose an attack: Enter 0 for an ice attack, 1 for a fire attack, 2 for a poison attack, 3 for a lightning attack .");
						atknum = pIn->GetInteger(pOut);
					}
					if (atknum < 0 || atknum>3)
					{
						pGrid->PrintErrorMessage("Invalid entry ...");
						pOut->PrintMessage("Choose an attack: Enter 0 for an ice attack, 1 for a fire attack, 2 for a poison attack, 3 for a lightning attack .");
						atknum = pIn->GetInteger(pOut);
					}
				}
				
				attackused = atknum;
				int plyratking = playerNum;
				if(atknum==3)
				{
					for (int i = 0; i < MaxPlayerCount;i++)
					{
						pGrid->AdvanceCurrentPlayer();
						if (pGrid->GetCurrentPlayer()->GetplayerNum() != plyratking)
						{
							pGrid->GetCurrentPlayer()->SetWallet(pGrid->GetCurrentPlayer()->GetWallet() - 20);
						}
					}
					pOut->PrintMessage("You used Lightning !");
					pIn->GetCellClicked();
					pOut->ClearStatusBar();
					return;

				}
				pOut->PrintMessage("Now enter the player number to attack !!!");
				int target = pIn->GetInteger(pOut);
				while (target == playerNum || target<0 || target >3)
				{
					pGrid->PrintErrorMessage("That is not a valid target");
					pOut->PrintMessage("Now enter the player number to attack !!!");
					target = pIn->GetInteger(pOut);
				}
				
				if (atknum!=3)
				{
					for (int i = 0; i < MaxPlayerCount;i++)
					{
						pGrid->AdvanceCurrentPlayer();
						if (pGrid->GetCurrentPlayer()->GetplayerNum() == target)
						{
							pGrid->GetCurrentPlayer()->Setattackeffect(true, atknum);
							if (atknum == 1)
							{
								pGrid->GetCurrentPlayer()->Setburncount(3);
							}
							if (atknum == 2)
							{
								pGrid->GetCurrentPlayer()->Setpoisoncount(5);
							}
							for (int j = 0;j < MaxPlayerCount;j++)
							{
								pGrid->AdvanceCurrentPlayer();
								if (pGrid->GetCurrentPlayer()->GetplayerNum() == plyratking)
								{
									break;
								}
							}
							break;
						}
					}
				}
				else
				{
					for (int i = 0; i < MaxPlayerCount;i++)
					{
						pGrid->AdvanceCurrentPlayer();
						if (pGrid->GetCurrentPlayer()->GetplayerNum() != plyratking)
						{
							pGrid->GetCurrentPlayer()->SetWallet(pGrid->GetCurrentPlayer()->GetWallet() - 20);
						}
					}
				}
				switch (atknum)
				{
				case 0:
					pOut->PrintMessage("You used Ice !");
					pIn->GetCellClicked();
					break;
				case 1:
					pOut->PrintMessage("You used Fire !");
					pIn->GetCellClicked();
					break;
				case 2:
					pOut->PrintMessage("You used Poison !");
					pIn->GetCellClicked();
					break;
				
				}

			}
			
			pOut->ClearStatusBar();
		}
		if (attcked)
		{
			diceNumber = 0;
		}
		wallet += diceNumber * 10;
		return;
		
	}

	if (wallet <= 0)
	{
		return;
	}
	// 3- Set the justRolledDiceNum with the passed diceNumber
	justRolledDiceNum = diceNumber;
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	CellPosition pos((pCell->GetCellPosition()).GetCellNum());
	pos.AddCellNum(justRolledDiceNum);
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	pGrid->UpdatePlayerCell(this,pos);

	// 6- Apply() the game object of the reached cell (if any)
	
	if (GetCell()->GetGameObject())
	{
		GetCell()->GetGameObject()->Apply(pGrid, this);}
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	
	if ((pCell->GetCellPosition()).GetCellNum() == 99)
	{
		pGrid->SetEndGame(true);
	}
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
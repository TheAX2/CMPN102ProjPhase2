#include "CardSix.h"

CardSix::CardSix(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; 
}

CardSix::~CardSix(void)
{
}

void CardSix::ReadCardParameters(Grid * pGrid)
{
	
	
	Input*pIn=pGrid->GetInput();
	Output*pOut=pGrid->GetOutput();

	
	pOut->PrintMessage("New CardSix: ...");
	
	

	
	pOut->ClearStatusBar();
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);	
	int num=pPlayer->GetjustRolledDiceNum();
	//pPlayer->Move(pGrid,-2*num);
	CellPosition pos((pPlayer->GetCell()->GetCellPosition()).GetCellNum());
	pos.AddCellNum(-1*num);
	pGrid->UpdatePlayerCell(pPlayer, pos);

	// 6- Apply() the game object of the reached cell (if any)

	if (pPlayer->GetCell()->GetGameObject())
	{
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
	}
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)

	if ((pPlayer->GetCell()->GetCellPosition()).GetCellNum() == 99)
	{
		pGrid->SetEndGame(true);
	}

}

void CardSix::Save(ofstream& OutFile, int type, int& noofobj)
{
	if (type != 3)
	{
		if (noofobj == 0) {
			OutFile << noofobj << endl;
			noofobj = -1;
		}
	}
	if (type == 3)
	{
		Card::Save(OutFile, 3, noofobj);
		OutFile << endl;
	}
	return;
}

void CardSix::Load(ifstream& InFile, Grid* pGrid)
{


}
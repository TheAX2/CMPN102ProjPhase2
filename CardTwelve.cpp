#include "CardTwelve.h"

bool CardTwelve::Exists12 = 0;
bool CardTwelve::isBought = 0;
int CardTwelve::CardPrice = 0;
int CardTwelve::Fees = 0;
Player* CardTwelve::cardOwner = NULL;


CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	
	cardNumber = 12; // set the inherited cardNumber data member with the card number (12 here)
}

void CardTwelve::ResetBought()
{
	isBought == 0;
}


void CardTwelve::ReadCardParameters(Grid* pGrid)
{
	//Getting a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	//a Static data member to make sure that the parameters of cardTwelve has been entered once
	//The parameters of any Card must be entered only at the first time the user adds this card
	if (Exists12 && !Editing) {
		return;
	}

	//Reading an Integer from the user using the Input class and set the Price and the Fees parameters with it
	pOut->PrintMessage("New CardTwelve: Enter the Card Price to be paid by the cardOwner ...");
	int unValidatedPrice = pIn->GetInteger(pOut);

	//Forcing the User to enter a positive value for CardPrice
	while (unValidatedPrice < 0)
	{
		pOut->PrintMessage("the Card Price must be positive, please Enter again its Card Price ..");
		unValidatedPrice = pIn->GetInteger(pOut);

	}
	CardPrice = unValidatedPrice;


	//Reading an Integer from the user using the Input class and set the Price and the Fees parameters with it
	pOut->PrintMessage("Enter the Card Fees to be paid by the passing player...");
	int unValidatedFees = pIn->GetInteger(pOut);


	//Forcing the User to enter a positive value for CardPrice
	while (unValidatedFees < 0)
	{
		pOut->PrintMessage("the Card Price must be positive, please Enter again its Card Fees ..");
		unValidatedFees = pIn->GetInteger(pOut);

	}
	Fees = unValidatedFees;
	Exists12 = 1;


	//Clearing the status bar
	pOut->ClearStatusBar();

}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	//Calling Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	//Getting a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	if (!isBought)
	{


		//checking if the player have enough money to buy this card

		if (pPlayer->GetWallet() > CardPrice) {
			//Giving the player the option to either buy this card or not
			string temp = "You have reached CardTwelve, card's Price=" + to_string(CardPrice);
			//temp += "Press 'Y' to buy it or 'N' to skip";
			pOut->PrintMessage(temp);
			int x, y;
			pIn->GetPointClicked(x, y);
			temp = "Press 'Y' to buy it or 'N' to skip";
			pOut->PrintMessage(temp);
			string state = pIn->GetSrting(pOut);
			if (state == "Y" || state == "y")
			{
				pPlayer->SetWallet((pPlayer->GetWallet()) - CardPrice);
				isBought = 1;
				cardOwner = pPlayer;
			}
			else
			{
				pOut->PrintMessage("You don't have enough money");
				pIn->GetCellClicked();
				pOut->ClearStatusBar();

			}

		}
	}
	//checking if this card has been bought by a player
	if (isBought)
	{
		if (cardOwner == pPlayer) {
			pOut->PrintMessage("Have a seat In your place");
			pIn->GetCellClicked();
			pOut->ClearStatusBar();

		}
		else
		{
			string temp = "You have reached a bought cell, you should pay to player " + to_string((cardOwner->GetplayerNum()));
			temp += (" " + to_string(Fees));
			temp += " Coins";
			pOut->PrintMessage(temp);
			//taking the fees form the passing player's wallet and adding this fees to the cardOwner's wallet
			pPlayer->SetWallet((pPlayer->GetWallet()) - Fees);
			cardOwner->SetWallet((cardOwner->GetWallet()) + Fees);
			pIn->GetCellClicked();
			pOut->ClearStatusBar();
		}
	}
}



CardTwelve::~CardTwelve()
{
}

void CardTwelve::Save(ofstream& OutFile, int type, int& noofobj)
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
		if (!saved)
		{
			OutFile << " " << CardPrice << " " << Fees ;
			saved = true;
		}
		OutFile << endl;
	}
	return;
}

void CardTwelve::Load(ifstream& InFile, Grid* pGrid)
{
	if (!loaded)
	{
		InFile >> CardPrice >> Fees;
		loaded = true;
	}
}
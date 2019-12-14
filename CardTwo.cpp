#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; 
}

CardTwo::~CardTwo(void)
{
}

void CardTwo::ReadCardParameters(Grid * pGrid)
{
	
	
	Input*pIn=pGrid->GetInput();
	Output*pOut=pGrid->GetOutput();

	
	pOut->PrintMessage("New CardTwo: Enter its wallet amount ...");
	int wallet=pIn->GetInteger(pOut);
	walletAmount=wallet;

	
	pOut->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
		
	
	Card::Apply(pGrid,pPlayer);

	
	int w=pPlayer->GetWallet();
	pPlayer->SetWallet(w+walletAmount);
}

void CardTwo::Save(ofstream& OutFile, int type, int& noofobj)
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
		OutFile << " " << walletAmount << endl;
	}
	return;
}

void CardTwo::Load(ifstream& InFile, Grid* pGrid)
{
	InFile >> walletAmount;

}
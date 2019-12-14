#include "CardSeven.h"
#include <time.h>

CardSeven::CardSeven(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; 
}

CardSeven::~CardSeven(void)
{
}

void CardSeven::ReadCardParameters(Grid * pGrid)
{
	
	
	Input*pIn=pGrid->GetInput();
	Output*pOut=pGrid->GetOutput();

	
	pOut->PrintMessage("New CardSeven: ...");
	
	

	
	pOut->ClearStatusBar();
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);		
	
	

	// 2- Generate a random number from 1 to 6 --> This step is done for you
	srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

	// 3- Get the "current" player from pGrid
	
	
	// 4- Move the currentPlayer using function Move of class player
	pPlayer->Seteffect(1); //Freeze turn count
	pPlayer->Move(pGrid, diceNumber);


	
	
}

void CardSeven::Save(ofstream& OutFile, int type, int& noofobj)
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

void CardSeven::Load(ifstream& InFile, Grid* pGrid)
{


}
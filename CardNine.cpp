#include "CardNine.h"

CardNine ::CardNine (const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 9; 
}

CardNine ::~CardNine (void)
{
}

void CardNine ::ReadCardParameters(Grid * pGrid)
{
	
	
	Input*pIn=pGrid->GetInput();
	Output*pOut=pGrid->GetOutput();

	
	pOut->PrintMessage("New Card Nine: Enter the cell to go to ...");
	celltomoveto=pIn->GetInteger(pOut);

	
	pOut->ClearStatusBar();
}

void CardNine ::Apply(Grid* pGrid, Player* pPlayer)
{
		
	
	Card::Apply(pGrid,pPlayer);


	pGrid->UpdatePlayerCell(pPlayer,celltomoveto);
}

void CardNine::Save(ofstream& OutFile, int type, int& noofobj)
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
		OutFile << " " << celltomoveto << endl;
	}
	return;
}

void CardNine::Load(ifstream& InFile, Grid* pGrid)
{
	InFile >> celltomoveto;
}

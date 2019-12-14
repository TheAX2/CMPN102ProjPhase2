#include "CardThree.h"
#include "Ladder.h"
CardThree::CardThree(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; 
}

CardThree::~CardThree(void)
{
}

void CardThree::ReadCardParameters(Grid * pGrid)
{
	Input*pIn=pGrid->GetInput();
	Output*pOut=pGrid->GetOutput();

	
	pOut->PrintMessage("New CardThree: ...");
	
	

	
	pOut->ClearStatusBar();
	
	
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
		
	
	CellPosition pos;
	Card::Apply(pGrid,pPlayer);
   Ladder*lptr=pGrid->GetNextLadder(GetPosition());
   if (lptr== NULL)
   {
	   return;
   }
   pos=lptr->GetPosition();
	
	pGrid->UpdatePlayerCell(pPlayer,pos);
	if (pPlayer->GetCell()->GetGameObject())
	{
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid,pPlayer);
	}
	
	if ((pPlayer->GetCell()->GetCellPosition()).GetCellNum() == 99)
	{
		pGrid->SetEndGame(true);
	}
}

void CardThree::Save(ofstream& OutFile, int type, int& noofobj)
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

void CardThree::Load(ifstream& InFile, Grid* pGrid)
{
	

}

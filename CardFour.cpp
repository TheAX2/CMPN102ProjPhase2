#include "CardFour.h"
#include "GameObject.h"
#include "Snake.h"
#include "Grid.h"

CardFour::CardFour(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; 
}

CardFour::~CardFour(void)
{
}

void CardFour::ReadCardParameters(Grid * pGrid)
{
	Input*pIn=pGrid->GetInput();
	Output*pOut=pGrid->GetOutput();

	
	pOut->PrintMessage("New CardFour: ...");
	
	

	
	pOut->ClearStatusBar();
	
	
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
		
	CellPosition pos;
	Card::Apply(pGrid, pPlayer);
	Snake* lptr = pGrid->GetNextSnake(GetPosition());
	if (lptr == NULL)
	{
		return;
	}
	pos = lptr->GetPosition();

	pGrid->UpdatePlayerCell(pPlayer, pos);
	if (pPlayer->GetCell()->GetGameObject())
	{
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
	}

	if ((pPlayer->GetCell()->GetCellPosition()).GetCellNum() == 99)
	{
		pGrid->SetEndGame(true);
	}
}

void CardFour::Save(ofstream& OutFile, int type, int& noofobj)
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

void CardFour::Load(ifstream& InFile, Grid* pGrid)
{


}

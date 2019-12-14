#include "Ladder.h"
#include "Grid.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
	
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ...");

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder::Save(ofstream& OutFile, int type, int& noofobj )
{
	if (OutFile.is_open())
	{
		if (noofobj != -1)
		{
			OutFile << noofobj << endl;
			noofobj = -1;
		}
		if (type == 1)
		{

			CellPosition StartCell = GetPosition();
			OutFile << StartCell.GetCellNum() << " " << endCellPos.GetCellNum() << endl;

		}
	}
	return;
}

Ladder::~Ladder()
{
}

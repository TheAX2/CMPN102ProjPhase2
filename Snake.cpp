#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a snake. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a snake. Click to continue ...");

	// 2- Apply the snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

void Snake::Save(ofstream& OutFile, int type, int &noofobj)
{
	if (OutFile.is_open())
	{
		if (noofobj!=-1)
		{
			OutFile << noofobj << endl;
			noofobj = -1;
		}
		if (type == 2) {
			CellPosition StartCell = GetPosition();
			OutFile << StartCell.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
		}
	}
	return;
}

Snake::~Snake()
{
}

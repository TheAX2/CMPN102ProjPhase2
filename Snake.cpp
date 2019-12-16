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
		if (noofobj == 0)
		{
			OutFile << noofobj << endl;
			noofobj = -1;
			return;
		}
		// to make sure no of the objects is only printed once
		if (type == 2)
		{
			if (noofobj != -1)
			{
				OutFile << noofobj << endl;
				noofobj = -1;
			}
			CellPosition StartCell = GetPosition();
			OutFile << StartCell.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
		}
	}
	return;
}

void Snake::Load(ifstream& InFile, Grid* pGrid)
{
	if (InFile.is_open())
	{
		int noofobj;
		InFile >> noofobj;// first we read the number of objects to start the loop
		for (int i = 0;i < noofobj;i++)
		{
			int startCell, endCell;
			InFile >> startCell >> endCell;
			CellPosition startPos(startCell), endPos(endCell);
			Snake* pSnake = new Snake(startPos, endPos);
			pGrid->AddObjectToCell(pSnake);
		}

	}
	return;
}

bool Snake::IsOverlappingsnake(GameObject* pGObj)
{
	if (Snake* flag = dynamic_cast<Snake*>(pGObj))
	{
		if (GetPosition().HCell() == flag->GetPosition().HCell())
		{
			for (int i = endCellPos.GetCellNum(); i < GetPosition().GetCellNum();i++)
			{
				if (i == flag->GetPosition().GetCellNum() || i == flag->GetEndPosition().GetCellNum())
				{
					return true;
				}
			}
		}
	}
	return false;
}

Snake::~Snake()
{
}

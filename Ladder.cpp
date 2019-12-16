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

bool Ladder::IsOverlappingladder(GameObject * pGObj)
{
	if (Ladder * flag = dynamic_cast<Ladder*>(pGObj))
	{
		if (GetPosition().HCell() == flag->GetPosition().HCell())
		{
			for (int i = GetPosition().GetCellNum(); i < endCellPos.GetCellNum();i++)
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

void Ladder::Save(ofstream& OutFile, int type, int& noofobj )
{
	if (OutFile.is_open())
	{
		
		// This condition is added in case no ladders
		if (noofobj == 0)
		{
			OutFile << noofobj << endl;
			noofobj = -1;
			return;
		}
		
		if (type == 1)
		{
			// to make sure no of the objects is only printed once
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

void Ladder::Load(ifstream& InFile,Grid* pGrid)
{
	if (InFile.is_open())
	{
		int noofobj;
		InFile >> noofobj;                  // first we read the number of objects to start the loop
		for (int i = 0;i < noofobj;i++)
		{
			int startCell, endCell;
			InFile >> startCell >> endCell;
			CellPosition startPos(startCell), endPos(endCell);
			Ladder* pLadder = new Ladder(startPos, endPos);
			pGrid->AddObjectToCell(pLadder);
		}
			
	}
	return;
}

Ladder::~Ladder()
{
}

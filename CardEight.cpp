#include "CardEight.h"

CardEight::CardEight(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; 
}

CardEight::~CardEight(void)
{
}

void CardEight::ReadCardParameters(Grid * pGrid)
{
	
	
	Input*pIn=pGrid->GetInput();
	Output*pOut=pGrid->GetOutput();

	
	pOut->PrintMessage("New CardEight ...");
	
	

	
	pOut->ClearStatusBar();
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	int n = 0;
	for (int i = 0; i < MaxPlayerCount;i++)
	{
		if (playert[i] == pPlayer)
			n = 1;
	}
	if ( n==0 )
	{
		playert[pPlayer->GetplayerNum()] = pPlayer;
		Card::Apply(pGrid, pPlayer);
		pPlayer->Seteffect(2); // Effect 2 forces the player to roll a zero
	}
	else {
		playert[pPlayer->GetplayerNum()] = NULL;
	}
	
	
}

void CardEight::Save(ofstream& OutFile, int type, int& noofobj)
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

void CardEight::Load(ifstream& InFile, Grid* pGrid)
{

}
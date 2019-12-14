#pragma once

#include "Card.h"


class CardEight :	public Card
{
	Player* playert[MaxPlayerCount];//player that triggered the effect

public:
	CardEight(const CellPosition & pos); 

	virtual void ReadCardParameters(Grid * pGrid); 
	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	virtual void Save(ofstream& OutFile, int type, int& noofobj);

	virtual void Load(ifstream& InFile, Grid* pGrid);
	virtual ~CardEight(); // A Virtual Destructor
};


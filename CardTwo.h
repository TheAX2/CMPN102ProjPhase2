#pragma once

#include "Card.h"


class CardTwo :	public Card
{
	
	int walletAmount; 

public:
	CardTwo(const CellPosition & pos); 

	virtual void ReadCardParameters(Grid * pGrid); 
	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	virtual void Save(ofstream& OutFile, int type, int& noofobj);

	virtual void Load(ifstream& InFile, Grid* pGrid);
	virtual ~CardTwo(); // A Virtual Destructor
};


#pragma once

#include "Card.h"


class CardFour :	public Card
{
	
	

public:
	CardFour(const CellPosition & pos); 

	virtual void ReadCardParameters(Grid * pGrid); 
	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	virtual void Save(ofstream& OutFile, int type, int& noofobj);

	virtual void Load(ifstream& InFile, Grid* pGrid);
	virtual ~CardFour(); // A Virtual Destructor
};


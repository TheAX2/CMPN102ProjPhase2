#pragma once

#include "Card.h"


class CardThree :	public Card
{
	
	

public:
	CardThree(const CellPosition & pos); 

	virtual void ReadCardParameters(Grid * pGrid); 
	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	virtual void Save(ofstream& OutFile, int type, int& noofobj);

	virtual void Load(ifstream& InFile, Grid* pGrid);
	virtual ~CardThree(); // A Virtual Destructor
};


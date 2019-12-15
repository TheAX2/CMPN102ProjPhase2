#pragma once

#include "Card.h"


class CardNine :	public Card
{
	
	int celltomoveto; 

public:
	CardNine (const CellPosition & pos); 

	virtual void ReadCardParameters(Grid * pGrid); 
	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	virtual void Save(ofstream& OutFile, int type, int& noofobj);
	virtual void Load(ifstream& InFile, Grid* pGrid);
	virtual ~CardNine (); // A Virtual Destructor
};


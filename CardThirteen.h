#pragma once
#include "Card.h"



class CardThirteen : public Card
{
	static int CardPrice;
	static int Fees;
	static bool Exists13;
	static bool isBought;
	static Player* cardOwner;
	static bool saved;
	static bool loaded;
public:
	CardThirteen(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardThirteen which is: 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThirteen on the passed Player

	virtual void Save(ofstream& OutFile, int type, int& noofobj);
	virtual void Load(ifstream& InFile, Grid* pGrid);

	virtual ~CardThirteen(); // A Virtual Destructor

};


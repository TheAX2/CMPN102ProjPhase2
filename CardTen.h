#pragma once
#include "Card.h"


class CardTen : public Card
{
	static int CardPrice;
	static int Fees;
	static bool Exists10;
	static bool isBought;
	static Player* cardOwner;


public:
	CardTen(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTen which is: 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTen on the passed Player
	virtual void ResetBought();
	virtual void Save(ofstream& OutFile, int type, int& noofobj);
	virtual void Load(ifstream& InFile, Grid* pGrid);

	virtual ~CardTen(); // A Virtual Destructor

};


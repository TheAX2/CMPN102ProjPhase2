#pragma once
#include "Card.h"

class CardTwelve : public Card
{
	static int CardPrice;
	static int Fees;
	static bool Exists12;
	static bool isBought;
	static Player* cardOwner;

public:
	CardTwelve(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTwelve which is: 
	virtual void ResetBought();
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwelve on the passed Player
	virtual void Save(ofstream& OutFile, int type, int& noofobj);
	virtual void Load(ifstream& InFile, Grid* pGrid);
	virtual ~CardTwelve(); // A Virtual Destructor

};


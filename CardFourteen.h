#pragma once
#include "Card.h"

class CardFourteen : public Card
{
	static int CardPrice;
	static int Fees;
	static bool Exists14;
	static bool isBought;
	static Player* cardOwner;
	static bool saved;
	static bool loaded;

public:
	CardFourteen(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardFourteen which is: 
	virtual void Setloaded(bool);
	virtual void Setsaved(bool);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFourteen on the passed Player
	virtual void ResetBought();
	virtual void Save(ofstream& OutFile, int type, int& noofobj);
	virtual void Load(ifstream& InFile, Grid* pGrid);

	virtual ~CardFourteen(); // A Virtual Destructor

};



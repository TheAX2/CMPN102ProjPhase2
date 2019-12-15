#pragma once
#include "Card.h"

class CardEleven : public Card
{

	static int CardPrice;
	static int Fees;
	static bool Exists11;
	static bool isBought;
	static Player* cardOwner;
	static bool saved;
	static bool loaded;
public:
	CardEleven(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardEleven which is: 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEleven on the passed Player

	virtual void Save(ofstream& OutFile, int type, int& noofobj);
	virtual void Load(ifstream& InFile, Grid* pGrid);

	virtual ~CardEleven(); // A Virtual Destructor
};


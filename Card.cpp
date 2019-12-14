#include "Card.h"
#include "CardOne.h"


Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	cardNumber = cnum; // needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

void Card::Save(ofstream& OutFile, int type, int& noofobj)
{
	if (OutFile.is_open())
	{
		if (noofobj == 0)
		{
			OutFile << noofobj << endl;
			noofobj = -1;
			return;
		}
		if (type == 3)
		{
			if (noofobj != -1)
			{
				OutFile << noofobj << endl;

				if (noofobj ==0)
				{
					noofobj = -1;
					return;
				}
				noofobj = -1;
			}
			CellPosition CellPos = GetPosition();
			OutFile << cardNumber << " " << CellPos.GetCellNum();

		}
	}
	return;

}

void Card::Load(ifstream& InFile, Grid* pGrid)
{
	if (InFile.is_open())
	{
		int noofobj;
		InFile >> noofobj;
		for (int i = 0;i < noofobj;i++)
		{
			int cardNum, cardPosition;
			InFile >> cardNum >> cardPosition;
			Card* pCard = NULL;
			switch (cardNum)
			{
			case 1:
				pCard = new CardOne(cardPosition);
				pCard->Load(InFile,pGrid);
				break;
			/*case 2:
				pCard = new CardTwo(cardPosition);
				break;
			case 3:
				pCard = new CardThree(cardPosition);
				break;
			case 4:
				pCard = new CardFour(cardPosition);
				break;
			case 5:
				pCard = new CardFive(cardPosition);
				break;
			case 6:
				pCard = new CardSix(cardPosition);
				break;
			case 7:
				pCard = new CardSeven(cardPosition);
				break;
			case 8:
				pCard = new CardEight(cardPosition);
				break;
			case 9:
				pCard = new CardNine(cardPosition);
				break;
			case 10:
				pCard = new CardTenToFourteen(cardPosition);
				break;
			case 11:
				pCard = new CardTenToFourteen(cardPosition);
				break;
			case 12:
				pCard = new CardTenToFourteen(cardPosition);
				break;
			case 13:
				pCard = new CardTenToFourteen(cardPosition);
				break;
			case 14:
				pCard = new CardTenToFourteen(cardPosition);
				break;*/

			}
			if (pCard)
			{
				pGrid->AddObjectToCell(pCard);
			}
		}

	}
	return;
}

Card::~Card()
{
}

#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

bool Card::Editing = false;


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

void Card::Setposition(CellPosition p)
{
	position = p;
}

void Card::SetEditing(bool b)
{
	Editing = b;
}

void Card::Setsaved(bool b)
{
	
}

void Card::Setloaded(bool b)
{
	
}


void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);

}

void Card::ResetBought()
{

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
			case 2:
				pCard = new CardTwo(cardPosition);
				pCard->Load(InFile, pGrid);
				break;
			case 3:
				pCard = new CardThree(cardPosition);
				pCard->Load(InFile,pGrid);
				break;
			case 4:
				pCard = new CardFour(cardPosition);
				pCard->Load(InFile,pGrid);
				break;
			case 5:
				pCard = new CardFive(cardPosition);
				pCard->Load(InFile,pGrid);
				break;
			case 6:
				pCard = new CardSix(cardPosition);
				pCard->Load(InFile,pGrid);
				break;
			case 7:
				pCard = new CardSeven(cardPosition);
				pCard->Load(InFile,pGrid);
				break;
			case 8:
				pCard = new CardEight(cardPosition);
				pCard->Load(InFile,pGrid);
				break;
			case 9:
				pCard = new CardNine(cardPosition);
				pCard->Load(InFile,pGrid);
				break;
			case 10:
				pCard = new CardTen(cardPosition);
				pCard->Load(InFile,pGrid);
				break;
			case 11:
				pCard = new CardEleven(cardPosition);
				pCard->Load(InFile,pGrid);
				break;
			case 12:
				pCard = new CardTwelve(cardPosition);
				pCard->Load(InFile,pGrid);
				break;
			case 13:
				pCard = new CardThirteen(cardPosition);
				pCard->Load(InFile,pGrid);
				break;
			case 14:
				pCard = new CardFourteen(cardPosition);
				pCard->Load(InFile,pGrid);
				break;

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

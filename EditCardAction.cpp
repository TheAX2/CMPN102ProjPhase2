#include "EditCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

EditCardAction::EditCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

EditCardAction::~EditCardAction()
{
}

void EditCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();




	// Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("Click on the source to Edit ...");
	cardPosition = pIn->GetCellClicked();

	// 4- Make the needed validations on the read parameters

	pCard = pGrid->HasCardFromCellPos(cardPosition);
	//Cell* pCell = new Cell(cardPosition);
	//Card* pCard = new Card(cardPosition);
	
	/*if (!pCard || (pCard->GetCardNumber()>=3 && pCard->GetCardNumber()<=8 ))
	{
			pOut->PrintMessage("Nothing to be edited ...");
	}*/
	pOut->ClearStatusBar();
}
void EditCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	if (!pCard || (pCard->GetCardNumber() >= 3 && pCard->GetCardNumber() <= 8))
	{
		pGrid->PrintErrorMessage("Nothing to be edited ...");
		pOut->ClearStatusBar();
		return;
	}
	pCard->SetEditing(true);
	if (pCard->GetCardNumber() == 10)
	{
		
		pCard->ReadCardParameters(pGrid);
	}
	else if (pCard->GetCardNumber() == 11)

	{
		
		pCard->ReadCardParameters(pGrid);
	}
	else if (pCard->GetCardNumber() == 12)

	{
		
		pCard->ReadCardParameters(pGrid);
	}
	else if (pCard->GetCardNumber() == 13)

	{
		
		pCard->ReadCardParameters(pGrid);
	}
	else if (pCard->GetCardNumber() == 14)

	{
		
		pCard->ReadCardParameters(pGrid);
	}
	else if (pCard->GetCardNumber() == 2)

	{
		
		pCard->ReadCardParameters(pGrid);
	
}
	else if (pCard->GetCardNumber() == 1)

	{
		
		pCard->ReadCardParameters(pGrid);
	}
	else if (pCard->GetCardNumber() == 9)

	{

		pCard->ReadCardParameters(pGrid);
	}
	pCard->SetEditing(false);

}

#include "InputDiceValueAction.h"

#include "Grid.h"
#include "Player.h"

InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceValueAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("please enter a dice value between 1-6");
	DiceValue = pIn->GetInteger(pOut);
	
}

void InputDiceValueAction::Execute()
{

	
	Grid* pGrid = pManager->GetGrid();
	if (!pGrid->GetEndGame()) {
		

		Player* PlayerPtr;
		PlayerPtr = pGrid->GetCurrentPlayer();
		PlayerPtr->Move(pGrid, DiceValue);
		pGrid->AdvanceCurrentPlayer();


	}
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

InputDiceValueAction::~InputDiceValueAction()
{
}

#include "SelectAction.h"


#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager *pApp) :Action(pApp)
{}


void SelectAction::ReadActionParameters() 
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a figure: Click a figure");

	//Read clicked point and store in P
	pIn->GetPointClicked(P.x, P.y);

	//Clear the status bar
	pOut->ClearStatusBar();
}

//Execute the action
void SelectAction::Execute()
{
	//Reads the point that the user clicked
	ReadActionParameters();
	


	//Set SelectedFig to the clicked figure (if any)
	SelectedFig = pManager->GetFigure(P.x, P.y);


	if (SelectedFig == NULL)  //If user clicks on an empty spot, unselect the previous figure if it was selected (and not NULL)
	{
		TEMPSelectedFigure = pManager->ReturnSelectedFigureNEW();
		if (TEMPSelectedFigure != NULL)
		{
			if (TEMPSelectedFigure->IsSelected())
				TEMPSelectedFigure->SetSelected(false);
		}
	}

	if (SelectedFig != NULL)
		//check to see if you selected a figure before or not, if so...Select this figure and Unselect the previous
	{
		NewUnselectCond = pManager->ReturnCond_NewUnselect();
		if (NewUnselectCond)
		{
			NewUnselect();
		}
	}

	//Checks if a figure was clicked, and whether the clicked figure is already selected
	if (SelectedFig != NULL)
	{
		if (SelectedFig->IsSelected())
		{
			Unselect();
		}
		else
		{
			Select();
			TEMPSelectedFigure = pManager->ReturnSelectedFigureNEW(); //TEMPSelectedFigure is for temporary returns of selectedfigure stored in applicationmanager
			if (TEMPSelectedFigure != NULL)
			{
				TEMPSelectedFigure->SetSelected(false);
				TEMPSelectedFigure = NULL;
			}
			pManager->SetCond_NewUnselect(true); //The condition for NewUnselect will be true as user has selected a figure and may select another figure
			pManager->AddSelectedFigureNEW(SelectedFig);  //The selected figure stored in ApplicationManager

		}
	}
}



//Selected an unselected figure
void SelectAction::Select() 
{

	SelectedFig->SetSelected(true);              //Sets the figure as "selected"
	Output* pOut = pManager->GetOutput();        //Get a Pointer to the Output Interface
	SelectedFig->PrintInfo(pOut);                //Print the selected figure info on the status bar
}


//Unselect a selected figure
void SelectAction::Unselect() 
{
	SelectedFig->SetSelected(false);
}

void SelectAction::NewUnselect() //NewUnselect is the function called when user selects a new figure and he selected a figure previously
{
	Select();
	TEMPSelectedFigure = SelectedFig;
	pManager->SetCond_NewUnselect(false);  //Cond for NewUnselect will be false after entering NewUnselect
	SelectedFig = pManager->ReturnSelectedFigureNEW();
	Unselect();  //Unselect previous figure that was selected
	pManager->AddSelectedFigureNEW(TEMPSelectedFigure); //Adds the new selected figure to be stored in application manager
	TEMPSelectedFigure = NULL; // reset to NULL
	SelectedFig = NULL; //reset to NULL
}





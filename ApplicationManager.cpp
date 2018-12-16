#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\SelectAction.h"


//Constructor
ApplicationManager::ApplicationManager() : SelectedFigureNEW(NULL), Cond_NewUnselect(false)
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
	{
		FigList[i] = NULL;
	}
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

//==================================================================================//
//							Select Functions										//
//==================================================================================//

//UnSelects all shapes
void ApplicationManager::FigListUnSelector()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected() )
			FigList[i]->SetSelected(false);
	}
}
bool ApplicationManager::ReturnCond_NewUnselect()
{
	return Cond_NewUnselect;
}
void ApplicationManager::SetCond_NewUnselect(bool cond)
{
	Cond_NewUnselect = cond ;
}
void ApplicationManager::AddSelectedFigureNEW(CFigure* selectedfig)
{
		SelectedFigureNEW = selectedfig;
}

//==================================================================================//
//							Save and Load Functions							        //
//==================================================================================//
//Saves all figures in the FigList
void ApplicationManager::SaveAll(ofstream&OutFile)
{
	//Loop on each figure ,then saving it 
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(OutFile);
	}
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			///create AddLineAction here

			break;

		case SELECT:
			pAct = new SelectAction(this);
			break;


		case EXIT:
			///create ExitAction here
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount] = pFig;
		FigList[FigCount]->SetFigureID(FigCount);
		FigCount++;
		
	}

}
CFigure* ApplicationManager::ReturnFigureList()
{
	return FigList[FigCount];
}
int ApplicationManager::ReturnFigureCount()
{
	return FigCount;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	

		for (int i = FigCount - 1; i >= 0; i--) 
		{
				if (FigList[i]->IsOnFigure(x, y))
					return FigList[i];
		}
		return NULL;
	

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}

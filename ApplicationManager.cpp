#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddElliAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddRhomAction.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
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
			pAct = new AddLineAction(this);

			break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;


		case DRAW_RHOMBUS:
				pAct = new AddRhomAction(this);
				break;

		case DRAW_ELLIPSE:
				pAct = new AddElliAction(this);
				break;

		case DRAW_TRI:
				pAct = new AddTriAction(this);
				break;

		case CHNG_DRAW_CLR:
				pOut->PrintMessage("Action: Change Figure's drawing color , Click anywhere");
				pOut->CreateColorToolBar();
				break;

		case CHNG_FILL_CLR:
				pOut->PrintMessage("Action: Change Figure's Fill color , Click anywhere");
				pOut->CreateFillColorToolBar();
				break;
		case DRAWING_AREA:
				pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
				break;

		case EMPTY:
				pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
				break;

		case TO_DRAW:
				pOut->PrintMessage("Action: Switch to Draw Mode, Creating simualtion tool bar");
				pOut->CreateDrawToolBar();
				break;

		case TO_PLAY:
				pOut->PrintMessage("Action: Switch to Play Mode, Creating Design tool bar");
				pOut->CreatePlayToolBar();
				break;
		case DEL:
			pOut->PrintMessage("Action: a click on delete , Click anywhere ");
			break;

		case SAVE:
			pOut->PrintMessage("Action: a click on Save , Click anywhere ");
			break;

		case SAVE_BY_TYPE:
			pOut->PrintMessage("Action: a click on Save By Type , Click anywhere ");
			break;

		case LOAD:
			pOut->PrintMessage("Action: a click on Load , Click anywhere ");
			break;

		case TO_START:
			pOut->PrintMessage("Action: a click on Start Game , Click anywhere ");
			pOut->CreatStartToolBar();
			break;

		case PLAYING_AREA:
			pOut->PrintMessage("Action: a click on Playing Area , Click anywhere ");
			break;

		case SELECT:
			pOut->PrintMessage("Action: a click on Select , Click anywhere ");
			break;

		case COPY:
			pOut->PrintMessage("Action: a click on Copy , Click anywhere ");
			break;

		case PASTE:
			pOut->PrintMessage("Action: a click on Paste , Click anywhere ");
			break;

		case C_BLACK:
			pOut->PrintMessage("Action: a click on Black , Click anywhere ");
			break;

		case C_WHITE:
			pOut->PrintMessage("Action: a click on White , Click anywhere ");
			break;

		case C_RED:
			pOut->PrintMessage("Action: a click on Red , Click anywhere ");
			break;

		case C_GREEN:
			pOut->PrintMessage("Action: a click on Green , Click anywhere ");
			break;

		case C_BLUE:
			pOut->PrintMessage("Action: a click on Blue , Click anywhere ");
			break;

		case FILL_BLACK :
			pOut->PrintMessage("Action: a click on Fill Black , Click anywhere ");
			break;

		case FILL_WHITE:
			pOut->PrintMessage("Action: a click on Fill White , Click anywhere ");
			break;

		case FILL_RED:
			pOut->PrintMessage("Action: a click on Fill Red , Click anywhere ");
			break;

		case FILL_GREEN:
			pOut->PrintMessage("Action: a click on Fill Green , Click anywhere ");
			break;

		case FILL_BLUE:
			pOut->PrintMessage("Action: a click on Fill Blue , Click anywhere ");
			break;

		case BY_TYPE:
			pOut->PrintMessage("Action: a click on Play By Type , Click anywhere ");
			break;

		case BY_COLOR:
			pOut->PrintMessage("Action: a click on Play By Color , Click anywhere ");
			break;

		case RESTART:
			pOut->PrintMessage("Action: a click on Restart The Game , Click anywhere ");
			break;
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
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
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

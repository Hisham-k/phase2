#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#define MaxFigCount 200 //Max no. of figs
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include <fstream>
#include <iostream>
//Main class that manages everything in the application.
class ApplicationManager
{


private:
	int FigCount;   //Actual number of figures
	CFigure*  SelectedFigureNEW;
	bool      Cond_NewUnselect;
		
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it

	// -- Select-Related Functions --//
	void AddSelectedFigureNEW(CFigure* selectedfig); //Add selectedfigure to application manager for storing
	CFigure* ReturnSelectedFigureNEW(); //Return selectedfigure for use
	bool ReturnCond_NewUnselect(); //Return the condition to be used in selectaction
	void SetCond_NewUnselect(bool); //set the condition to true or false for NewUnselect

	// -- Save and Load Related Functions --//
	void SaveAll(ofstream&OutFile);
	void ClearFigList();

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure* ReturnFigureList();
	int ReturnFigureCount();
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif
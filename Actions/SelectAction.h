#include "Action.h"
#include "../Figures/CFigure.h"

class SelectAction : public Action 
{
private:
	Point P;
	CFigure* SelectedFig; 
	CFigure* TEMPSelectedFigure;
	bool NewUnselectCond;
	bool HasEnteredNewUnselect;

	
public:
	SelectAction(ApplicationManager *pApp);

	//Reads select parameters
	virtual void ReadActionParameters();

	//Executes the select action
	virtual void Execute();

	void Select();
	void Unselect();
	void NewUnselect();
};



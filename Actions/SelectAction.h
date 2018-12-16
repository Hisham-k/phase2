#include "Action.h"
#include "../Figures/CFigure.h"

class SelectAction : public Action 
{
private:
	Point P;
	CFigure* SelectedFig; 
	bool NewUnselectCond;

	
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



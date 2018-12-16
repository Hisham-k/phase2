#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_Play: return TO_PLAY;

			case ITM_RECT: return DRAW_RECT;
			
			case ITM_LINE: return DRAW_LINE;
			
			case ITM_TRI: return DRAW_TRI;
			
			case ITM_RHOMBUS: return DRAW_RHOMBUS;
			
			case ITM_ELLIPSE: return DRAW_ELLIPSE;
			
			case ITM_DRAWCLR: return CHNG_DRAW_CLR;
			
			case ITM_FILLCLR: return CHNG_FILL_CLR;

			case ITM_SELECT: return SELECT;

			case ITM_COPY: return COPY;

			case ITM_PASTE:return PASTE;
		
			case ITM_DEL: return DEL;

			case ITM_SAVE: return SAVE;

			case ITM_LOAD: return LOAD;

			case ITM_SAVEBYTYPE: return SAVE_BY_TYPE;
				
			case ITM_EXIT: return EXIT;
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else if(UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{
		///TODO:
		if (y >= 0 && y < UI.ToolBarHeight) {
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_DRAW:return TO_DRAW;
			case ITM_START:return TO_START;
			case ITM_EXIT_PLAY: return EXIT;
			default: return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return PLAYING_AREA;
		}
		return STATUS;
	}	
	else if (UI.InterfaceMode == MODE_FILLCOLOR) {
		if (y >= 0 && y < UI.ToolBarHeight) {
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_DRAW_MODE: return TO_DRAW;
			case ITM_FILL_BLACK:return FILL_BLACK;
			case ITM_FILL_WHITE:return FILL_WHITE;
			case ITM_FILL_RED: return FILL_RED;
			case ITM_FILL_GREEN: return FILL_GREEN;
			case ITM_FILL_BLUE: return FILL_BLUE;
			default: return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_COLORS) {
		if (y >= 0 && y < UI.ToolBarHeight) {
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_DRAW_MODE1: return TO_DRAW;
			case ITM_BLACK:return C_BLACK;
			case ITM_WHITE:return C_WHITE;
			case ITM_RED: return C_RED;
			case ITM_GREEN: return C_GREEN;
			case ITM_BLUE: return C_BLUE;
			default: return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_START) {

	if (y >= 0 && y < UI.ToolBarHeight) {
		int ClickedItemOrder = (x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
		{
		case ITM_PLAY_MODE: return TO_PLAY;
		case ITM_BY_TYPE: return BY_TYPE;
		case ITM_BY_COLOR: return BY_COLOR;
		case ITM_RESTART: return RESTART;
		default: return EMPTY;
		}
	}
	if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
	{
		return PLAYING_AREA;
	}
	return STATUS;
}
}
/////////////////////////////////
	
Input::~Input()
{
}

#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_FILLCOLOR,
	MODE_COLORS,
	MODE_START
};
enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	ITM_Play,
	ITM_RECT,		//Recangle item in menu
	ITM_LINE,
	ITM_TRI,
	ITM_RHOMBUS,
	ITM_ELLIPSE,
	ITM_DRAWCLR,
	ITM_FILLCLR,
	ITM_SELECT,
	ITM_COPY,
	ITM_PASTE,
	ITM_DEL,
	ITM_SAVE,
	ITM_SAVEBYTYPE,
	ITM_LOAD,
	ITM_EXIT,		//Exit item
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};
enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	ITM_DRAW,
	ITM_START,
	ITM_EXIT_PLAY,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};
enum StartMenuItem {
	ITM_PLAY_MODE,
	ITM_BY_TYPE,
	ITM_BY_COLOR,
	ITM_RESTART,
	START_ITM_COUNT
};
enum FillColorMenuItem {
	ITM_DRAW_MODE,
	ITM_FILL_BLACK,
	ITM_FILL_WHITE,
	ITM_FILL_RED,
	ITM_FILL_GREEN,
	ITM_FILL_BLUE,
	FILL_ITM_COUNT
};
enum ColorMenuItem {
	ITM_DRAW_MODE1,
	ITM_BLACK,
	ITM_WHITE,
	ITM_RED,
	ITM_GREEN,
	ITM_BLUE,
	COLOR_ITM_COUNT
};
__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif
#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1350;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	
	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = RED;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = BLUE;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearToolBar()const {
	pWind->SetBrush(WHITE);
	pWind->SetPen(WHITE, 1);
	pWind->DrawRectangle(0, 0, UI.width+500, UI.ToolBarHeight);
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output:: CreateFillColorToolBar()const {
	ClearToolBar();
	UI.InterfaceMode = MODE_FILLCOLOR;
	string MenuItemImages[FILL_ITM_COUNT];
	MenuItemImages[ITM_DRAW_MODE] = "images\\MenuItems\\DRAW_MODE.jpg";
	MenuItemImages[ITM_FILL_BLACK] = "images\\MenuItems\\BLACK.jpg";
	MenuItemImages[ITM_FILL_WHITE] = "images\\MenuItems\\WHITE.jpg";
	MenuItemImages[ITM_FILL_RED] = "images\\MenuItems\\RED.jpg";
	MenuItemImages[ITM_FILL_GREEN] = "images\\MenuItems\\GREEN.jpg";
	MenuItemImages[ITM_FILL_BLUE] = "images\\MenuItems\\BLUE.jpg";
	for (int i = 0; i < FILL_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output:: CreateColorToolBar()const {
	ClearToolBar();
	UI.InterfaceMode = MODE_COLORS;
	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_DRAW_MODE1] = "images\\MenuItems\\DRAW_MODE.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\BLACK.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\WHITE.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\RED.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\GREEN.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\BLUE.jpg";
	for (int i = 0; i < COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output::CreateDrawToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_Play] = "images\\MenuItems\\Menu_Play.jpg";

	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	/**/
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_Line.jpg";
	
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Trig.jpg";
	
	MenuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\Menu_Rhombus.jpg";
	
	MenuItemImages[ITM_ELLIPSE] = "images\\MenuItems\\Menu_Ellipse.jpg";
	
	MenuItemImages[ITM_DRAWCLR] = "images\\MenuItems\\Menu_DrawColor.jpg";
	
	MenuItemImages[ITM_FILLCLR] = "images\\MenuItems\\Menu_FillColor.jpg";

	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\SELECT.jpg";

	MenuItemImages[ITM_COPY] = "images\\MenuItems\\COPY.jpg";

	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\PASTE.jpg";
	
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\Menu_Delete.jpg";
	
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	
	MenuItemImages[ITM_SAVEBYTYPE] = "images\\MenuItems\\Menu_SaveByType.jpg";

	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";

	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreatePlayToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_DRAW] = "images\\MenuItems\\DRAW_MODE.jpg";
	MenuItemImages[ITM_START] = "images\\MenuItems\\Menu_START.jpg";
	MenuItemImages[ITM_EXIT_PLAY] = "images\\MenuItems\\Menu_Exit.jpg";

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
void Output::CreatStartToolBar()const {
	ClearToolBar();
	UI.InterfaceMode = MODE_START;
	string MenuItemImages[START_ITM_COUNT];
	MenuItemImages[ITM_PLAY_MODE] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImages[ITM_BY_TYPE] = "images\\MenuItems\\BY_TYPE.jpg";
	MenuItemImages[ITM_BY_COLOR] = "images\\MenuItems\\BY_COLOR.jpg";
	MenuItemImages[ITM_RESTART] = "images\\MenuItems\\REASTART.jpg";


	for (int i = 0; i < START_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	


	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y);

}

void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TrigGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TrigGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TrigGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TrigGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

#define RHOMBUS_CENTER_POINT_TO_EDGE_X_Axis 50
#define RHOMBUS_CENTER_POINT_TO_EDGE_Y_Axis 80
void Output::DrawRhombus(Point P1, GfxInfo RhombusGfxInfo, bool selected) const
{
	int x[4];
	int y[4];

	x[0] = P1.x;
	y[0] = P1.y + RHOMBUS_CENTER_POINT_TO_EDGE_Y_Axis;
	x[2] = P1.x;
	y[2] = P1.y - RHOMBUS_CENTER_POINT_TO_EDGE_Y_Axis;
	x[1] = P1.x - RHOMBUS_CENTER_POINT_TO_EDGE_X_Axis;
	y[1] = P1.y;
	x[3] = P1.x + RHOMBUS_CENTER_POINT_TO_EDGE_X_Axis;
	y[3] = P1.y;

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RhombusGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RhombusGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RhombusGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawPolygon(x, y, 4, style);
}
void Output::DrawEllipse(Point P1, Point P2, GfxInfo EllipseGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = EllipseGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (EllipseGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(EllipseGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}


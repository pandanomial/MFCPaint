#include "pch.h"
#include "JPanel.h"
#include "GameObject.h"//I added it
#include "Sprite.h"//I added it
#include "GWCMFC.h"//I added it
#include "GWCMFCDlg.h"//I added it
#include "MainLogic.h"// I added it


// JPanel

IMPLEMENT_DYNAMIC(JPanel, CWnd)

JPanel::JPanel()
{
}


JPanel::~JPanel()
{
}


CString JPanel::sWindowName;
void JPanel::RegisterClass()
{
	sWindowName = AfxRegisterWndClass(0);
}


BEGIN_MESSAGE_MAP(JPanel, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// In case you need to get to the Dialog from somewhere
//CBaronPongDlg *tDialog = (CBaronPongDlg*)AfxGetMainWnd();

// And in case you need to get to the app
//CBaronPongApp* app = ( CBaronPongApp *)AfxGetApp();

// A click upon us!  Execute this code and be merry.
/*//work on it later

void JPanel::OnMouseMove(UINT nFlags, CPoint point)
{
	CGWCMFCApp* app = (CGWCMFCApp*)AfxGetApp();    //hey  I need app, where logic is , give me application
	MainLogic* logic = app->GetLogic();            // how to get to logic , hey app, give me logic


	CGWCMFCDlg* tDialog = (CGWCMFCDlg*)AfxGetMainWnd();
	CWnd* textWidth = (*tDialog).GetDlgItem(IDC_EDITwidth);//doesn't work
	CString tW;
	CString tH;
	textWidth->GetWindowText(tW); //only way to get the input text value from user
	//float floatW = _ttof(tW); // convert CString to float
	double doubleW = _wtof(tW); // convert CString to double


	CWnd* textHeight = tDialog->GetDlgItem(IDC_EDITheight);//doesn't work	
	textHeight->GetWindowText(tH);
	//float floatH = _ttof(tW); // convert CString to float
	double doubleH = _wtof(tH); // convert CString to double

	CButton* buttonColorRed = (CButton*)tDialog->GetDlgItem(IDC_RADIOred);
	bool isCheckedColorRed = buttonColorRed->GetCheck();

	CButton* buttonColorBlack = (CButton*)tDialog->GetDlgItem(IDC_RADIOblack);
	bool isCheckedColorBlack = buttonColorBlack->GetCheck();

	CButton* buttonShapeRound = (CButton*)tDialog->GetDlgItem(IDC_RADIOround);
	bool isCheckedShapeRound = buttonShapeRound->GetCheck();

	CButton* buttonShapeRect = (CButton*)tDialog->GetDlgItem(IDC_RADIOrectangle);
	bool isCheckedShapeRect = buttonShapeRect->GetCheck();

	CButton* buttonNone = (CButton*)tDialog->GetDlgItem(IDC_RADIOnone);
	bool isCheckedNone = buttonNone->GetCheck();

	CButton* buttonDraw = (CButton*)tDialog->GetDlgItem(IDC_RADIOdraw);
	bool isCheckedDraw = buttonDraw->GetCheck();

	CButton* buttonClearAll = (CButton*)tDialog->GetDlgItem(IDC_RADIOclearall);
	bool isCheckedClearAll = buttonClearAll->GetCheck();

	CButton* buttonErase = (CButton*)tDialog->GetDlgItem(IDC_RADIOerase);
	bool isCheckedErase = buttonErase->GetCheck();

	CButton* buttonUndo = (CButton*)tDialog->GetDlgItem(IDC_RADIOundo);
	bool isCheckedUndo = buttonUndo->GetCheck();


	int x = point.x; //mouse down position as staring left
	int y = point.y; // mouse down position as starting top
	int moveToX; //mouse up position right
	int moveToY;//mouse up position bottom;
	double w = doubleW; //width
	double h = doubleH; //height
	int c;//color
	int s;//shape

	if (isCheckedColorRed)
	{
		c = 0; //red
	}
	else if (isCheckedColorBlack)
	{
		c = 1; //black
	}
	else
	{
		c = 1;
	}// default//can add more colors

	if (isCheckedShapeRound)
	{
		s = 0; //rounded
	}
	else if (isCheckedShapeRect)
	{
		s = 1; //Rect
	}
	else
	{
		s = 0;//default rounded //can add more shapes
	}

	
	   //if (nFlags & MK_LBUTTON == MK_LBUTTON);

	GameObject* newObj = nullptr;

	int lineToX = 0;
	int lintToY = 0;

	if (lineToX != 0 && lintToY != 0)
	{
		newObj = logic->MakeObject(x, y, lineToX, lintToY, c, s);; //hey logic, make object

	}
	if (nFlags = 0)//=1 on mouse down
	{
		lineToX = point.x;
		lintToY = point.y;
	}
	if (MK_LBUTTON == 0)
	{
		lineToX = point.x;
		lintToY = point.y;
	}
	if (MK_LBUTTON == 0)
	{
		lineToX = point.x;
		lintToY = point.y;
	}

	// Make a new Sprite using that object pointer and keep it in AllSprites
	Sprite* newSprite = new Sprite(newObj);
	mAllSprites.push_back(newSprite);

	//undo function
	if (isCheckedUndo)
	{
		// the object will be draw is already there, to Undo needs to delete the object already been drawn
		if (mAllSprites.size() > 1) //threfore, >1 is very important
		{
			// delect the object which  will be drawn next
			mAllSprites.pop_back();

			//delete the object which previously had been drawn this is the Undo effect
			mAllSprites.pop_back();//delete the object which previously had been drawn this is the Undo effect
			if (mAllSprites.size() == 0)
			{
				//all the objects are deleted , the undo button shpuld not be checked, do nothing button should be set checked in order for the program to create more objects to draw
				buttonNone->SetCheck(true);
				buttonUndo->SetCheck(false);
			}
		}
		else
		{
			//no object is in the vector, can't delete anything anymore
			buttonNone->SetCheck(true); //set the do nothing button checked in order to create more eobjects to draw
			buttonUndo->SetCheck(false); //set the undo button uchecked


		}
	}
	if (isCheckedClearAll)
	{
		//all the objects are deleted , the undo button shpuld not be checked, do nothing button should be set checked in order for the program to create more objects to draw
		mAllSprites.clear();
		buttonNone->SetCheck(true);
		buttonClearAll->SetCheck(false);

	}


	Invalidate();

}
*/
void JPanel::OnLButtonDown(UINT nFlags, CPoint point)
{

	//	CGWCMFCDlg * tDialog = (CGWCMFCDlg*)AfxGetMainWnd();//hey dialog 
						 
	CGWCMFCApp* app = (CGWCMFCApp*)AfxGetApp();    //hey  I need app, where logic is , give me application
	MainLogic* logic = app->GetLogic();            // how to get to logic , hey app, give me logic

	//Tell Logic to make a new Object at this point and return the pointer (they will put it in AllObjects too.)
	//1) Since the object on the left side of the arrow is a MainLogic object, yes that method would go in MainLogic
	//2) MakeObject makes an object.An object exists, and a sprite is in charge of drawing it.Object is in the logicand Sprite is in the client.
	//3) A point is a point on the screen.It's where you clicked.
	//4) The DC in OnPaint has already been made.You just need to pass it to the Sprite so the sprite knows what to draw on.
		 //There are four ways to pass an object to another function.You just need to make the two sides(JPanel and Sprite) match.

	 
	CGWCMFCDlg* tDialog = (CGWCMFCDlg*)AfxGetMainWnd();
	CWnd* textWidth = (*tDialog).GetDlgItem(IDC_EDITwidth);//doesn't work
	CString tW;
	CString tH;
	textWidth->GetWindowText(tW); //only way to get the input text value from user
	//float floatW = _ttof(tW); // convert CString to float
	double doubleW = _wtof(tW); // convert CString to double


	CWnd* textHeight = tDialog->GetDlgItem(IDC_EDITheight);//doesn't work	
	textHeight->GetWindowText(tH);
	//float floatH = _ttof(tW); // convert CString to float
	double doubleH = _wtof(tH); // convert CString to double

	CButton* buttonColorRed = (CButton*)tDialog->GetDlgItem(IDC_RADIOred);
	bool isCheckedColorRed = buttonColorRed->GetCheck();
	
	CButton* buttonColorBlack = (CButton*)tDialog->GetDlgItem(IDC_RADIOblack);
	bool isCheckedColorBlack = buttonColorBlack->GetCheck();

	CButton* buttonShapeRound = (CButton*)tDialog->GetDlgItem(IDC_RADIOround);
	bool isCheckedShapeRound = buttonShapeRound->GetCheck();

	CButton* buttonShapeRect = (CButton*)tDialog->GetDlgItem(IDC_RADIOrectangle);
	bool isCheckedShapeRect = buttonShapeRect->GetCheck();

	CButton* buttonNone = (CButton*)tDialog->GetDlgItem(IDC_RADIOnone);
	bool isCheckedNone = buttonNone->GetCheck();
	
	//work on it later,  draw line when mouse hold
	//CButton* buttonDraw = (CButton*)tDialog->GetDlgItem(IDC_RADIOdraw);
	//bool isCheckedDraw = buttonDraw->GetCheck();
	

	CButton* buttonClearAll = (CButton*)tDialog->GetDlgItem(IDC_RADIOclearall);
	bool isCheckedClearAll = buttonClearAll->GetCheck();

	//work on it later,  erase when mouse hold
	//CButton* buttonErase = (CButton*)tDialog->GetDlgItem(IDC_RADIOerase);
	//bool isCheckedErase = buttonErase->GetCheck();

	CButton* buttonUndo = (CButton*)tDialog->GetDlgItem(IDC_RADIOundo);
	bool isCheckedUndo = buttonUndo->GetCheck();
	 

	int x = point.x; //mouse down position as staring left
	int y = point.y; // mouse down position as starting top
	int moveToX =0; //mouse up position right
	int moveToY =0;//mouse up position bottom;
	double w = doubleW; //width
	double h = doubleH; //height
	int c;//color
	int s;//shape
	
	if (isCheckedColorRed)
	{
		c = 0; //red
	}
	else if (isCheckedColorBlack)
	{
		c = 1; //black
	}
	else
	{
		c = 1;
	}// default//can add more colors later

	if (isCheckedShapeRound)
	{
		s = 0; //rounded
	}
	else if (isCheckedShapeRect)
	{
		s = 1; //Rect
	}
	else
	{
		s = 0;//default rounded //can add more shapes later on
	}

	//for later 
	//if (lineToX != 0 && lintToY != 0)
	//{
		//newObj = logic->MakeObject(x, y, lineToX, lintToY, c, s);; //hey logic, make object
		
	//}
	//if (nFlags = 1)//=1 on mouse down
	//{
	//	lineToX = point.x;
	//	lintToY = point.y;
	//}
	//if (MK_LBUTTON == 1)
	//if (MK_CONTROL == 1)
	//{
	//	lineToX = point.x;
	//	lintToY = point.y;
	//}
	
	//if (WM_MOUSEMOVE)
	//{
		//lineToX = point.x;
		//lintToY = point.y;
		//if (WM_LBUTTONUP)
	//	{
	//		lineToX = point.x;
	//		lintToY = point.y;
	//		c = 0;
	//	}
		
	//}
	// pointer for create new object
	GameObject* newObj = nullptr;

	//if (lineToX != 0 && lintToY != 0)
	//{
	//	newObj = logic->MakeObject(x, y, lineToX, lintToY, c, s);; //hey logic, make object

	//}

		if (int(doubleW) == 0 || int(doubleH) == 0)
		{ //user has not input width , height values yet, default is 100	the mouse dowm (x,y) is center
			newObj = logic->MakeObject(x, y, c, s); //hey logic, make object
		}
		else
		{   //user had input width and height
			newObj = logic->MakeObject(x, y, w, h, c, s); //hey logic, make object
		}

	//I made a default method also, no x, y requirement
	//GameObject* newObj = logic->MakeObject();

	// Make a new Sprite using that object pointer and keep it in AllSprites
	Sprite* newSprite = new Sprite(newObj);
	mAllSprites.push_back(newSprite);

	//undo function
	if (isCheckedUndo)
	{
		// the object will be draw is already there, to Undo needs to delete the object already been drawn
		if (mAllSprites.size() > 1) //threfore, >1 is very important
		{
			// delect the object which  will be drawn next
			mAllSprites.pop_back(); 

			//delete the object which previously had been drawn this is the Undo effect
			mAllSprites.pop_back();//delete the object which previously had been drawn this is the Undo effect
			if (mAllSprites.size() == 0)
			{
				//all the objects are deleted , the undo button shpuld not be checked, do nothing button should be set checked in order for the program to create more objects to draw
				buttonNone->SetCheck(true);
				buttonUndo->SetCheck(false);
			}
		}
		else
		{ 
			//no object is in the vector, can't delete anything anymore
			buttonNone->SetCheck(true); //set the do nothing button checked in order to create more eobjects to draw
			buttonUndo->SetCheck(false); //set the undo button uchecked		
		}
	}
	if (isCheckedClearAll)
	{
		//all the objects are deleted , the undo button shpuld not be checked, do nothing button should be set checked in order for the program to create more objects to draw
		mAllSprites.clear();
		buttonNone->SetCheck(true);
		buttonClearAll->SetCheck(false);
	}
	 
	
	// my first version is to call sprite to draw in here, that's the reason that I asked how to create dc
	//CPaintDC dc(this); 
	//pass address of dc, I changed the Draw function pass pointer of an object, instead of the orgional passing object
	//newSprite->Draw(&dc); //my first version is to call sprite to draw in here, that's the reason that I asked how to create dc
	//above is my first version

	// If you have cool settings, apply them to the OBJECT.  Sprite will see them when it draws



	// Something changed, so tell system to redraw me
	Invalidate();


	//can't kill it  too early, still pointing for later to draw
	//if (!(newSprite == nullptr))
	//{
	//	delete newSprite; // free memory
	//	newSprite = nullptr;// to null
	//}
}



void JPanel::OnPaint()
{
	//https://msdn.microsoft.com/en-us/library/fxhhde73.aspx
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CWnd::OnPaint() for painting messages

	// This code here is just to show you where the JPanel is.  Makes it blue.

	// do not use it because it cover the area, only in the beginning to see if the code works or not

	//but I like it because it makes the background white
	CBrush brushWhite(RGB(255, 255, 255));
	CBrush* pOldBrush = dc.SelectObject(&brushWhite);
	CRect rect;
	GetClientRect(rect);
	dc.Rectangle(rect);
	dc.SelectObject(pOldBrush);

	// Loop through all of our sprites and tell them to draw by passing the dc in..
	// YOU GO HERE


	// My first version to collect user input info so that spite can draw according to the data saved in object
	//CGWCMFCApp* app = (CGWCMFCApp*)AfxGetApp();    //hey  I need app, where logic is , give me application
	//MainLogic* logic = app->GetLogic();            // how to get to logic , hey app, give me logic
	//CGWCMFCDlg* tDialog = (CGWCMFCDlg*)AfxGetMainWnd();
	////Tell Logic to make a new Object at this point and return the pointer (they will put it in AllObjects too.)
	//int color;
	//int shape;
	//int h;
	//int w;
	//shape = (*tDialog).mShape;
	//color = (*tDialog).mColor;
	//h = (*tDialog).mHeight;
	//w = (*tDialog).mWidth;
	//GameObject* newObj = logic->MakeObject(w, h,color,shape); //hey logic, make object
	////Make a new Sprite using that object pointer and keep it in AllSprites
	//Sprite* newSprite = new Sprite(newObj);
	//mAllSprites.push_back(newSprite);
	//newSprite->Draw(&dc);
	//Invalidate();
	//	if (!(newSprite == nullptr))
	//	{
	//		delete newSprite; // free memory
	//		newSprite = nullptr;// to null
	//	}
	// above is my first version

	  //#1)void Draw(CPaintDc tContext);      //copy newSprite->Draw(dc);   value
	  //#2)void Draw(CPaintDc *tContext);     //share newSprite->Draw(&dc); pointer
	  //#3)void Draw(CPaintDc &tContext);     //take  newSprite->Draw(dc);  reference
	  //#4)void Draw(const CPaintDc tContext);//peek  newSprite->Draw(dc);  const reference
	
	  
	  // The DC in OnPaint has already been made.You just need to pass it to the Sprite so the sprite knows what to draw on.There are four ways to pass an object to another function.You just need to make the two sides(JPanel and Sprite) match.

	 //tell each sprite to draw, all the sprites are stored in vector
	if (mAllSprites.size() > 0)
	{	
		for (int i = 0; i < mAllSprites.size(); i++)
		{
		mAllSprites[i]->Draw(&dc);
		}
    }
	else
	{//for later
	}

	// kill it here, still doesn't work 
	//if (!(newSprite == nullptr))
	//{
	//	delete newSprite; // free memory
	//	newSprite = nullptr;// to null
	//}

}
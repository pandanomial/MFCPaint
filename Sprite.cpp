#include "pch.h"
#include "Sprite.h"


//void Sprite::Draw( CPaintDC tContext ) //it was here originally
void Sprite::Draw(CPaintDC* dc)  //I changed it to this
{
	// Just look at our object and draw something to the DC	
	bool amCircle = mMyObject->IsCircle();
	bool amRed = mMyObject->IsRed();
	bool amBlack = mMyObject->IsBlack();
	
	double dblH = mMyObject->GetHeight();
	double dblW = mMyObject->GetWidth();

	double leftMouse = mMyObject->GetXposition();
	double topMouse = mMyObject->GetYposition();
	
	int intH = (int)dblH;
	int intW=(int)dblW;
	long longH = (int)dblH;
	long longW = (int)dblW;

	//mouse click point looks better
	int intLeft = (int)leftMouse - intW/2;  //Rect can takes int as well
	int intTop = (int)topMouse -intH/2;

	CPen aPen;// I like CPen, it's cleaner when drawing
	//brush requires only color, filling area
	//CBrush brushRed(RGB(255, 0, 0));    //red
	//CBrush brushBlue(RGB(0, 0, 255));   //blue
	//CBrush brushBlack(RGB(0, 0, 0));   //black
	//CBrush* pOldBrush = (*dc).SelectObject(&brushBlack);

	if (amRed)  //if (mMyObject->GetColor == 0) //red
	{
		aPen.CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
		//pOldBrush = (*dc).SelectObject(&brushRed);
	}
	else //if (mMyObject->GetColor == 1) //black
	{
		aPen.CreatePen(PS_SOLID, 5, RGB(0, 0, 0)); //black default in GameObject
		//pOldBrush = (*dc).SelectObject(&brushBlack);
	}

	(*dc).SelectObject(aPen);
	//(*dc).SelectObject(pOldBrush);

	//for brush
	//CRect rect;
	//rect.bottom = intH;
	//rect.right = intW;
	//rect.top = longTop; //0
	//rect.left = longLeft;//0
	 
	//for pen
	int intRight = intLeft+ intW;
	int intBottom = intTop+ intH;
	//int intCenterX= (intLeft + intRight)/2;
	//int intCenterY= (intTop+ intBottom)/2;

     CPoint p1(intLeft, intTop), p2(intRight, intBottom);
	 CRect r(p1, p2);
	
	
	//GetClientRect(0,0); // works left conner
	//GetClientRect(rect);///does not work, has to pass left top conner point

	if (amCircle)
	{
		(*dc).Ellipse(r);
		//(*dc).FillSolidRect(rect, RGB(255,0,0));//fill
		//(*dc).Ellipse(rect);//does not draw, only fill
	}
	else  //Rectangle or Square
	{
		(*dc).Rectangle(r);
		//(*dc).FillSolidRect(rect, RGB(255,0,0));//fill
		//(*dc).Rectangle(rect);//does not draw only fill
	}

}

Sprite::Sprite(GameObject* tObjectToDraw)
{
	mMyObject = tObjectToDraw;
}


Sprite::~Sprite()
{
}

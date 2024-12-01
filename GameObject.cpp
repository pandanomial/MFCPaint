#include "pch.h"
#include "GameObject.h"

GameObject::GameObject() //default value
{
	mXPosition = 0;   //previously already set to 0
	mYPosition = 0;   //previously already set to 0
	mShape = 0;       //my new variable
	mColor = 1;       //my new variable default color black
	mWidth = 100;     //my new variable default
	mHeight = 100;    //my new variable default
}

GameObject::GameObject(double xLeft, double yTop)//over load //where the mouse click at (x, y)
{
	mXPosition = xLeft;     //previously already set to 0
	mYPosition = yTop;      //previously already set to 0
	mShape = 0;             //my new variable default as round shape
	mColor = 1;             //my new variable black as default
	mWidth = 100;           //my new variable overload
	mHeight = 100;          //my new variable overload
}

GameObject::GameObject(double xLeft, double yTop, int color, int shape)
{
	mXPosition = xLeft;     //previously already set to 0
	mYPosition = yTop;      //previously already set to 0
	mShape = shape;             //my new variable default as round shape
	mColor = color;             //my new variable black as default
	mWidth = 100;           //my new variable overload
	mHeight = 100;          //my new variable overload
}

GameObject::GameObject(double xLeft, double yTop, double width, double height, int color, int shape) //user input value
{
	mXPosition = xLeft;     //previously already set to 0
	mYPosition = yTop;      //previously already set to 0
	mShape = shape;         //my new variable shape 0 is round 1 is rect
	mColor = color;         //my new variable black as default 1, red is 0
	mWidth = width;         //my new variable overload default 100
	mHeight = height;       //my new variable overload default 100
}

GameObject::~GameObject()
{
}

void GameObject::SetShape(int shape) //round or Rectangle
{
	mShape = shape;
}
int GameObject::GetShape()
{
	return mShape;
}

void GameObject::SetColor(int color)
{
	mColor = color;
}
int GameObject::GetColor()
{
	return mColor;
}

void GameObject::SetWidth(double width)
{
	mWidth = width;
}
double GameObject::GetWidth()
{
	return mWidth;
}

void GameObject::SetHeight(double height)
{
	mHeight = height;
}
double GameObject::GetHeight()
{
	return mHeight;
}

double GameObject::GetXposition() //default (0,0)
{
	return mXPosition;
}
void GameObject::SetXposition(double xLeft) //default (0,0)
{
	mXPosition = xLeft;
}
double GameObject::GetYposition() //default (0,0)
{
	return mYPosition;
}
void GameObject::SetYposition(double yTop) //default (0,0)
{
	mYPosition = yTop;
}
bool GameObject::IsCircle()
{
	if (mShape == 0) //shape 0 is rounded
		return true;
	else
		return false; //else Rectangle
}
bool GameObject::IsRed()
{
	if (mColor == 0)  //0 is red 2 is black
		return true;
	else
		return false; // 1 is blue
}

bool GameObject::IsBlue()
{
	if (mColor == 1)  //0 is red 2 is black
		return true;
	else
		return false; // 1 is blue
}
bool GameObject::IsBlack()
{
	if (mColor == 2)  //0 is red 2 is black 
		return true;
	else
		return false; //  1 is blue 
}
bool GameObject::IsLeftXzero()
{
	if (mXPosition == 0)  //left top corner (0,0)
		return true;
	else
		return false;
}
bool GameObject::IsTopYzero() //left top corner (0,0)
{
	if (mYPosition == 0)
		return true;
	else
		return false;
}


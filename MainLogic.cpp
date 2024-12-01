#include "pch.h"
#include "MainLogic.h"

MainLogic::MainLogic()
{
	mAllObjects.assign(0, mGameObject);
}

MainLogic::~MainLogic()
{
}

GameObject* MainLogic::MakeObject(double xLeft, double yTop)//over load //where the mouse click at (x, y)
{
	GameObject* gameObject = new GameObject(xLeft, yTop);//overload
	gameObject->SetXposition(xLeft);//where the mouse click at x
	gameObject->SetYposition(yTop);//where the mouse click at y
	//gameObject->SetShape(0); //default rounded shape
	//gameObject->SetHeight(100);//defalut
	//gameObject->SetWidth(100); //default
	//gameObject->SetColor(1); //default, not by clicking radio button
	return gameObject;
}

GameObject* MainLogic::MakeObject(double xLeft, double yTop, int color, int shape) //user input value
{
	GameObject* gameObject = new GameObject(xLeft, yTop, color, shape);//overload
	gameObject->SetXposition(xLeft);//where mouse is
	gameObject->SetYposition(yTop); //where mouse is
	//gameObject->SetHeight(100);   //default 100
	//gameObject->SetWidth(100);   //default 100
	gameObject->SetColor(color);     //user clicking radio button
	gameObject->SetShape(shape);     //user clicking radio button
	return gameObject;
}

GameObject* MainLogic::MakeObject(double xLeft, double yTop, double width, double height, int color, int shape) //user input value
{
	GameObject* gameObject = new GameObject(xLeft, yTop, width, height, color, shape);//overload
	gameObject->SetXposition(xLeft);//where mouse is
	gameObject->SetYposition(yTop); //where mouse is
	gameObject->SetHeight(height);   //user input x
	gameObject->SetWidth(width);   //user input y
	gameObject->SetColor(color);     //user clicking radio button
	gameObject->SetShape(shape);     //user clicking radio button
	return gameObject;
}
GameObject* MainLogic::MakeObject()
{
	GameObject* gameObject = new GameObject();

	return gameObject;
}

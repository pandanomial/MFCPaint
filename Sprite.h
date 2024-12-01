#pragma once
class GameObject;
#include "GameObject.h"
#include "MainLogic.h"

class Sprite
{
public:
	Sprite(GameObject* tObjectToDraw);
	~Sprite();

	//void Draw(CPaintDC* tContext); //originally it's this
	void Draw(CPaintDC* tContext);//I changed it to pointer


private:
	float mLastDrawX = 0;// Used for interpolation
	float mLastDrawY = 0;

	GameObject* mMyObject;
};


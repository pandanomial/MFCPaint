#pragma once
#include<vector>// changed from <list> to <vector> beause vector is easier
#include "GameObject.h"
class GameObject;

class MainLogic
{
private:
	GameObject* mGameObject;

public:
	MainLogic();
	~MainLogic();

	GameObject* MakeObject();   //no requirments
	GameObject* MakeObject(double xLeft, double yTop);  //where the mouse click at (x, y);
	GameObject* MakeObject(double xLeft, double yTop,  int color, int shape); //user input value
	GameObject* MakeObject(double xLeft, double yTop, double width, double height, int color, int shape); //user input value

private:
	//std::list<GameObject*> mAllObjects;
	std::vector<GameObject*> mAllObjects; //changed to vector becasue it's easier
};




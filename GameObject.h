#pragma once
class GameObject
{
public:
	GameObject();
	~GameObject();
	GameObject(double xLeft, double yTop);  //default //where the mouse click at (x, y)
	GameObject(double xLeft, double yTop, int color, int shape);
	GameObject(double xLeft, double yTop, double width, double height, int color, int shape); //user input value

	void SetShape(int shape); //rounded or Rect
	int GetShape();

	void SetColor(int color); //red or black
	int GetColor();

	void SetWidth(double width);
	double GetWidth();

	void SetHeight(double height);
	double GetHeight();

	void SetXposition(double xLeft); //default (0,0)
	double GetXposition();  //default (0,0)

	void SetYposition(double xLeft); //default (0,0)
	double GetYposition();   //default (0,0)

	bool IsCircle();
	bool IsRed();
	bool IsBlue();
	bool IsBlack();
	bool IsLeftXzero();
	bool IsTopYzero();

private:
	// Sprite knows NOTHING.  We have all the data, controller sets it, view draws it
	double mXPosition ; //where mouse is
	double mYPosition ; //where mouse is
	int mShape ;       //my new variable 0 is circle/ 1 is Rect
	int mColor ;       //my new variable 0 is red/1 is black default
	double mWidth ;     //my new variable w=100 default
	double mHeight ;    //my new variable h=100 default
};







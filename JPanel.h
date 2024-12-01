#pragma once
#include <vector>
//#include <list> changed to vector , vector is easier
#include "GWCMFCDlg.h"//I added it, I wanted to do onclick to draw

// JPanel
class GWCMFCDlg;// I added it
class Sprite;
class JPanel : public CWnd
{
	DECLARE_DYNAMIC(JPanel)

public:
	JPanel();
	virtual ~JPanel();

	static CString sWindowName;
	static void RegisterClass();

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//afx_msg void OnMouseMove(UINT nFlags, CPoint point);

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();

private:
	std::vector<Sprite*> mAllSprites;//vector works better than list
};




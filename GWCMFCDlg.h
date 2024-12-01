
// GWCMFCDlg.h : header file
//
#pragma once
#include "GameObject.h"
#include "MainLogic.h"
#include <vector>
#pragma once

class JPanel;
class GameObject;
class Sprite;

// CGWCMFCDlg dialog
class CGWCMFCDlg : public CDialogEx
{
// Construction
public:
	CGWCMFCDlg(CWnd* pParent = nullptr);	// standard constructor

	virtual ~CGWCMFCDlg();
	JPanel* mGameView = nullptr;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GWCMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEdit1();
private:
	std::vector<Sprite*> mAllSprites;
public:
	afx_msg void OnBnClickedPaneltarget();
};

 
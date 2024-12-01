
// GWCMFCDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "GWCMFC.h"
#include "GWCMFCDlg.h"
#include "afxdialogex.h"
#include "JPanel.h"
#include "MainLogic.h"//I added it
#include "GameObject.h"//I added it
#include "Sprite.h"//I added it

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGWCMFCDlg dialog

CGWCMFCDlg::~CGWCMFCDlg()
{
	if( mGameView )
		delete mGameView;
	mGameView = nullptr;
}


CGWCMFCDlg::CGWCMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GWCMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGWCMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGWCMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED( IDCANCEL, &CGWCMFCDlg::OnBnClickedCancel )
	ON_EN_CHANGE(IDC_EDIT1, &CGWCMFCDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_PANELTARGET, &CGWCMFCDlg::OnBnClickedPaneltarget)
END_MESSAGE_MAP()


// CGWCMFCDlg message handlers

BOOL CGWCMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	// This trick here is to get around the difficulty of adding a custom panel type to the visual editor
	CWnd* tTarget = GetDlgItem( IDC_PANELTARGET );
	if( tTarget )
	{
		CWnd* tParent = tTarget->GetParent();
		RECT tTargetRect;
		tTarget->GetWindowRect( &tTargetRect );

		tTargetRect.left = 0;
		tTargetRect.top = 0;

		JPanel::RegisterClass();
		mGameView = new JPanel;
		mGameView->Create( JPanel::sWindowName, L"", WS_CHILDWINDOW, tTargetRect, tParent, IDC_GAMEPANEL );
		mGameView->ShowWindow( SW_SHOW );
		tTarget->DestroyWindow();
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGWCMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGWCMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// In case you need to get to the Dialog from somewhere
//CBaronPongDlg *tDialog = (CBaronPongDlg*)AfxGetMainWnd();

// And in case you need to get to the app
//CBaronPongApp* app = ( CBaronPongApp *)AfxGetApp();

///////////////////////////////////////////////////////////////////////////
void CGWCMFCDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CGWCMFCDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGWCMFCDlg::OnBnClickedPaneltarget()
{
	// TODO: Add your control notification handler code here
}

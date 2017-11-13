
// MainFrm.cpp : implementaci�n de la clase CMainFrame
//

#include "stdafx.h"
#include "Breakout.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
END_MESSAGE_MAP()

// Construcci�n y destrucci�n de CMainFrame

CMainFrame::CMainFrame()
{
	// TODO: agregar aqu� el c�digo de inicializaci�n de miembros
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: modificar aqu� la clase Window o los estilos cambiando
	//  CREATESTRUCT cs

	// Cambiando dimensiones y posici�n de la ventana
	cs.cx = 500; // width
	cs.cy = 350; // height
	cs.x = ((::GetSystemMetrics(SM_CXSCREEN) - cs.cx) / 2);
	cs.y = ((::GetSystemMetrics(SM_CYSCREEN) - cs.cy) / 2);

	return TRUE;
}

// Diagn�sticos de CMainFrame

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// Controladores de mensajes de CMainFrame


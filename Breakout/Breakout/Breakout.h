
// Breakout.h: archivo de encabezado principal para la aplicación Breakout
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"       // Símbolos principales


// CBreakoutApp:
// Consulte la sección Breakout.cpp para obtener información sobre la implementación de esta clase
//

class CBreakoutApp : public CWinApp
{
public:
	CBreakoutApp();


// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBreakoutApp theApp;


// MainFrm.h: interfaz de la clase CMainFrame
//

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // Crear s�lo a partir de serializaci�n
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Atributos
public:

// Operaciones
public:

// Reemplazos
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementaci�n
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


// Funciones de asignaci�n de mensajes generadas
protected:
	DECLARE_MESSAGE_MAP()

};



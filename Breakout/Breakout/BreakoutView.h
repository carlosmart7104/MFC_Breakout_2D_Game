
// BreakoutView.h: interfaz de la clase CBreakoutView
//

#pragma once


class CBreakoutView : public CView
{
protected: // Crear sólo a partir de serialización
	CBreakoutView();
	DECLARE_DYNCREATE(CBreakoutView)

// Atributos
public:
	CBreakoutDoc* GetDocument() const;

// Operaciones
public:

// Reemplazos
public:
	virtual void OnDraw(CDC* pDC);  // Reemplazado para dibujar esta vista
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void OnInitialUpdate();
protected:

// Implementación
public:
	virtual ~CBreakoutView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignación de mensajes generadas
protected:
	void reStart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg UINT StartTimer(UINT TimerDuration);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Versión de depuración en BreakoutView.cpp
inline CBreakoutDoc* CBreakoutView::GetDocument() const
   { return reinterpret_cast<CBreakoutDoc*>(m_pDocument); }
#endif


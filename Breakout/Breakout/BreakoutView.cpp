
// BreakoutView.cpp: implementación de la clase CBreakoutView
//

#include "stdafx.h"
// Se pueden definir SHARED_HANDLERS en un proyecto ATL implementando controladores de vista previa, miniatura
// y filtro de búsqueda, y permiten compartir código de documentos con ese proyecto.
#ifndef SHARED_HANDLERS
#include "Breakout.h"
#endif

#include "BreakoutDoc.h"
#include "BreakoutView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "Brick.h"
#include "Ball.h"
#include "Player.h"

#define	IDT_TIMER WM_USER

CString scoreTxt, livesTxt, messageTxt;
CArray<Brick, Brick&> bricksList;
Ball ball = Ball();
Player player = Player();
bool pausa = false;
int score_sum = 0, lives = 3;
int brick_columns = 7;
int brick_files = 4;
int brick_width = 65;
int brick_height = 25;
UINT Timerval;

// CBreakoutView

IMPLEMENT_DYNCREATE(CBreakoutView, CView)

BEGIN_MESSAGE_MAP(CBreakoutView, CView)
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// Construcción o destrucción de CBreakoutView

CBreakoutView::CBreakoutView()
{
	// TODO: agregar aquí el código de construcción
	for (int i = 0; i < brick_files; i++) {
		for (int j = 0; j < brick_columns; j++) {
			bricksList.Add(Brick(15 + brick_width * j, i * brick_height + 25));
		}
	}
}

CBreakoutView::~CBreakoutView()
{
}

BOOL CBreakoutView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modificar aquí la clase Window o los estilos cambiando
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

void CBreakoutView::OnInitialUpdate()
{
	Timerval = StartTimer(50);
}

// Dibujo de CBreakoutView

void CBreakoutView::OnDraw(CDC* pDC)
{
	CBreakoutDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: agregar aquí el código de dibujo para datos nativos
	COLORREF color = RGB(0, 0, 0);
	CPen generalPen;
	generalPen.CreatePen(PS_SOLID, 1, color);
	pDC->SelectObject(&generalPen);

	// Límite del tablero
	pDC->Rectangle(5, 13, 475, 280);

	// Puntaje
	scoreTxt.Format(_T("Score: %d"), score_sum);
	livesTxt.Format(_T("Lives: %d"), lives);
	pDC->SetTextColor(color);
	pDC->TextOut(15, 5, scoreTxt);
	pDC->TextOut(412, 5, livesTxt);

	// Ladrillos
	for (int i = 0; i < bricksList.GetSize(); i++) {
		pDC->Rectangle(bricksList[i].x1, bricksList[i].y1, bricksList[i].x2, bricksList[i].y2);
	}

	// Jugador
	pDC->Rectangle(player.x1, player.y1, player.x2, player.y2);

	// Pelota
	pDC->Ellipse(ball.x1, ball.y1, ball.x2, ball.y2);
}


// Diagnósticos de CBreakoutView

#ifdef _DEBUG
void CBreakoutView::AssertValid() const
{
	CView::AssertValid();
}

void CBreakoutView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

void CBreakoutView::reStart()
{
	player.moveToCenter();
	ball.setPoint(230, 160);
	ball.stepX = 2;
	ball.stepY = 8;
	bricksList.RemoveAll();
	for (int i = 0; i < brick_files; i++) {
		for (int j = 0; j < brick_columns; j++) {
			bricksList.Add(Brick(15 + brick_width * j, i * brick_height + 25));
		}
	}
	score_sum = 0;
	lives = 3;
}

void CBreakoutView::OnTimer(UINT_PTR nIDEvent)
{
	CBreakoutDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// Mover pelota
	if (pausa == false)
	{
		ball.setPoint(ball.x1 + ball.stepX, ball.y1 + ball.stepY);

		// Verificar si el juego ha sido completado
		if (bricksList.GetSize() == 0)
		{
			pausa = true;
			messageTxt.Format(L"You Win! :)\nScore: %d", score_sum);
			AfxMessageBox(messageTxt);
			pausa = false;
			reStart();
		}

		// Verificar si el juego ha terminado
		if (lives == 0)
		{
			pausa = true;
			AfxMessageBox(L"Game Over :C");
			pausa = false;
			reStart();
		}

		// Calcular colisiones
		// ball & frontera - rectangulo de frontera: 5,13,475,280
		if (ball.x1 < 5 || ball.x2 > 475)
		{
			ball.stepX = -ball.stepX;
		}
		if (ball.y1 < 13 || ball.y2 > 280) // colisión y cambio de sentido en Y
		{
			ball.stepY = -ball.stepY;
		}
		if (ball.y2 > 280) // colisión en Y max, descontar una vida.
		{
			lives--;
		}

		// player & ball
		if (((ball.x1 >= player.x1 && ball.x1 <= player.x2) || (ball.x2 >= player.x1 && ball.x2 <= player.x2)) &&
			((ball.y1 >= player.y1 && ball.y1 <= player.y2) || (ball.y2 >= player.y1 && ball.y2 <= player.y2)))
		{
			ball.stepY = -ball.stepY;
			if (ball.x2 == player.x1 || ball.x1 == player.x2)
			{
				ball.stepX = -ball.stepX;
			}
		}

		// ball & blocks
		for (int i = 0; i < bricksList.GetSize(); i++) {
			if (((ball.x1 >= bricksList[i].x1 && ball.x1 <= bricksList[i].x2) || (ball.x2 >= bricksList[i].x1 && ball.x2 <= bricksList[i].x2)) &&
				((ball.y1 >= bricksList[i].y1 && ball.y1 <= bricksList[i].y2) || (ball.y2 >= bricksList[i].y1 && ball.y2 <= bricksList[i].y2)))
			{
				ball.stepY = -ball.stepY;
				if (ball.x2 == bricksList[i].x1 || ball.x1 == bricksList[i].x2)
				{
					ball.stepX = -ball.stepX;
				}
				bricksList.RemoveAt(i);
				score_sum += 100;
				break;
			}
		}

		// Aquí los métodos de actualización
		RedrawWindow();
	}
}

UINT CBreakoutView::StartTimer(UINT TimerDuration)
{
	UINT TimerVal;
	TimerVal = SetTimer(IDT_TIMER, TimerDuration, NULL);  // Starting the Timer
	if (TimerVal == 0)
	{
		AfxMessageBox(L"Unable to obtain timer");
	}
	return TimerVal;
}

void CBreakoutView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar)
	{
	case VK_LEFT:
		player.moveToLeft();
		break;
	case VK_RIGHT:
		player.moveToRight();
		break;
	}
}

CBreakoutDoc* CBreakoutView::GetDocument() const // La versión de no depuración está alineada
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBreakoutDoc)));
	return (CBreakoutDoc*)m_pDocument;
}
#endif //_DEBUG


// Controladores de mensaje de CBreakoutView

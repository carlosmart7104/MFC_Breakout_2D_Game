
// BreakoutDoc.h: interfaz de la clase CBreakoutDoc
//


#pragma once


class CBreakoutDoc : public CDocument
{
protected: // Crear sólo a partir de serialización
	CBreakoutDoc();
	DECLARE_DYNCREATE(CBreakoutDoc)

// Atributos
public:

// Operaciones
public:

// Reemplazos
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementación
public:
	virtual ~CBreakoutDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignación de mensajes generadas
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Función auxiliar que establece contenido de búsqueda para un controlador de búsqueda
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};

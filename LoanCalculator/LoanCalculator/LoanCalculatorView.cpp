
// LoanCalculatorView.cpp : implementation of the CLoanCalculatorView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "LoanCalculator.h"
#endif

#include "LoanCalculatorDoc.h"
#include "LoanCalculatorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLoanCalculatorView

IMPLEMENT_DYNCREATE(CLoanCalculatorView, CView)

BEGIN_MESSAGE_MAP(CLoanCalculatorView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CLoanCalculatorView construction/destruction

CLoanCalculatorView::CLoanCalculatorView()
{
	// TODO: add construction code here

}

CLoanCalculatorView::~CLoanCalculatorView()
{
}

BOOL CLoanCalculatorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CLoanCalculatorView drawing

void CLoanCalculatorView::OnDraw(CDC* /*pDC*/)
{
	CLoanCalculatorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CLoanCalculatorView printing

BOOL CLoanCalculatorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLoanCalculatorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLoanCalculatorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CLoanCalculatorView diagnostics

#ifdef _DEBUG
void CLoanCalculatorView::AssertValid() const
{
	CView::AssertValid();
}

void CLoanCalculatorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLoanCalculatorDoc* CLoanCalculatorView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLoanCalculatorDoc)));
	return (CLoanCalculatorDoc*)m_pDocument;
}
#endif //_DEBUG


// CLoanCalculatorView message handlers

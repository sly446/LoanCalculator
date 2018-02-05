
// LoanCalculatorView.h : interface of the CLoanCalculatorView class
//

#pragma once


class CLoanCalculatorView : public CView
{
protected: // create from serialization only
	CLoanCalculatorView();
	DECLARE_DYNCREATE(CLoanCalculatorView)

// Attributes
public:
	CLoanCalculatorDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CLoanCalculatorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LoanCalculatorView.cpp
inline CLoanCalculatorDoc* CLoanCalculatorView::GetDocument() const
   { return reinterpret_cast<CLoanCalculatorDoc*>(m_pDocument); }
#endif


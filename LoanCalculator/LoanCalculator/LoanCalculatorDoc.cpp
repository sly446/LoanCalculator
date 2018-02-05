
// LoanCalculatorDoc.cpp : implementation of the CLoanCalculatorDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "LoanCalculator.h"
#endif

#include "LoanCalculatorDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CLoanCalculatorDoc

IMPLEMENT_DYNCREATE(CLoanCalculatorDoc, CDocument)

BEGIN_MESSAGE_MAP(CLoanCalculatorDoc, CDocument)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CLoanCalculatorDoc, CDocument)
END_DISPATCH_MAP()

// Note: we add support for IID_ILoanCalculator to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .IDL file.

// {342F9FA7-8D51-47F6-99B9-415EFC876F29}
static const IID IID_ILoanCalculator =
{ 0x342F9FA7, 0x8D51, 0x47F6, { 0x99, 0xB9, 0x41, 0x5E, 0xFC, 0x87, 0x6F, 0x29 } };

BEGIN_INTERFACE_MAP(CLoanCalculatorDoc, CDocument)
	INTERFACE_PART(CLoanCalculatorDoc, IID_ILoanCalculator, Dispatch)
END_INTERFACE_MAP()


// CLoanCalculatorDoc construction/destruction

CLoanCalculatorDoc::CLoanCalculatorDoc()
{
	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();
}

CLoanCalculatorDoc::~CLoanCalculatorDoc()
{
	AfxOleUnlockApp();
}

BOOL CLoanCalculatorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CLoanCalculatorDoc serialization

void CLoanCalculatorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CLoanCalculatorDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CLoanCalculatorDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CLoanCalculatorDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CLoanCalculatorDoc diagnostics

#ifdef _DEBUG
void CLoanCalculatorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLoanCalculatorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CLoanCalculatorDoc commands

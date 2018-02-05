
// LoanCalculator.h : main header file for the LoanCalculator application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CLoanCalculatorApp:
// See LoanCalculator.cpp for the implementation of this class
//

class CLoanCalculatorApp : public CWinApp
{
public:
	CLoanCalculatorApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLoanCalculatorApp theApp;

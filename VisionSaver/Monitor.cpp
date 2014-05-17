// Monitor.cpp : implementation file
//

#include "stdafx.h"
#include "Saver.h"
#include "Monitor.h"


// CMonitor

CMonitor::CMonitor()
{
	m_hMonitor = NULL;
	m_rect.SetRect(0,0,0,0);
	m_pSWnd = NULL;
}

CMonitor::~CMonitor()
{
	if (m_pSWnd)
	{
		delete m_pSWnd;
		m_pSWnd = NULL;
	}	
}


// CMonitor member functions

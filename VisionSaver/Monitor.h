#pragma once



// CMonitor command target

class CMonitor : public CObject
{
public:
	CMonitor();
	virtual ~CMonitor();

	HMONITOR	m_hMonitor;
	CRect		m_rect;
	CSaverWnd*  m_pSWnd;
};



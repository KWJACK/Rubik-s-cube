
// assignment4_10_2012722081.h : assignment4_10_2012722081 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cassignment4_10_2012722081App:
// �� Ŭ������ ������ ���ؼ��� assignment4_10_2012722081.cpp�� �����Ͻʽÿ�.
//

class Cassignment4_10_2012722081App : public CWinAppEx
{
public:
	Cassignment4_10_2012722081App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cassignment4_10_2012722081App theApp;


// assignment4_10_2012722081Doc.h : Cassignment4_10_2012722081Doc Ŭ������ �������̽�
//

#include "Face_list.h"
#include "loglist.h"
#pragma once


class Cassignment4_10_2012722081Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	Cassignment4_10_2012722081Doc();
	DECLARE_DYNCREATE(Cassignment4_10_2012722081Doc)

// Ư���Դϴ�.
public:
	Face_list mylist;
	loglist mylog;
	Face *pCur;//�ӽ�
	POINT front[9][4];//�ո���ǥ��---->�������� Ondraw���� ����
	POINT top[9][4];//������ǥ��
	POINT next[9][4];//������ǥ��
	void setPoint();
	COLORREF setColor(int number);//face�� �����ִ� �迭�� ���� ���� ���� ������, number�� 0~8������ ��. �迭012)(345)(678)
	COLORREF setColor_up(int number);//face_up�� �����ִ� �迭�� ���� ���� ���� ������, number�� 0~8������ ��. �迭012)(345)(678)
	COLORREF setColor_next(int number);//face_next�� �����ִ� �迭�� ���� ���� ���� ������, number�� 0~8������ ��. �迭012)(345)(678)
	
	key_Log *pLog;//�ӽ�
	mouse_Log *pLog_m;
	bool colorWithNumber;//true�̸� Į��+����, false�̸� ���ڰ� �������ʵ���
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~Cassignment4_10_2012722081Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void On32779();
	afx_msg void On32780();
};


// assignment4_10_2012722081View.h : Cassignment4_10_2012722081View Ŭ������ �������̽�
//

#pragma once
//�巡�� ���ۿ���, ������, ����, �귯�� ���� ����

class Cassignment4_10_2012722081View : public CView
{
protected: // serialization������ ��������ϴ�.
	Cassignment4_10_2012722081View();
	DECLARE_DYNCREATE(Cassignment4_10_2012722081View)

// Ư���Դϴ�.
public:
	Cassignment4_10_2012722081Doc* GetDocument() const;

// �۾��Դϴ�.
public:
	COLORREF m_BrushColor;//���� ������
	bool m_bDragFlag;//�巡�� ���ۿ���(true: on, false: off)
	CPoint m_StartPos, m_EndPos;
	

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~Cassignment4_10_2012722081View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnColorRed();
	afx_msg void OnColorBlack();
	afx_msg void OnColorBlue();
	afx_msg void OnColorYellow();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void On32777();
	afx_msg void On32778();
	afx_msg void On32779();
	afx_msg void On32780();
//	afx_msg void OnAppCommand(CWnd* pWnd, UINT nCmd, UINT nDevice, UINT nKey);
};

#ifndef _DEBUG  // assignment4_10_2012722081View.cpp�� ����� ����
inline Cassignment4_10_2012722081Doc* Cassignment4_10_2012722081View::GetDocument() const
   { return reinterpret_cast<Cassignment4_10_2012722081Doc*>(m_pDocument); }
#endif


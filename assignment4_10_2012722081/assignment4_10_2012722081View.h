
// assignment4_10_2012722081View.h : Cassignment4_10_2012722081View 클래스의 인터페이스
//

#pragma once
//드래그 시작여부, 시작점, 끝점, 브러쉬 색을 선언

class Cassignment4_10_2012722081View : public CView
{
protected: // serialization에서만 만들어집니다.
	Cassignment4_10_2012722081View();
	DECLARE_DYNCREATE(Cassignment4_10_2012722081View)

// 특성입니다.
public:
	Cassignment4_10_2012722081Doc* GetDocument() const;

// 작업입니다.
public:
	COLORREF m_BrushColor;//색을 저장함
	bool m_bDragFlag;//드래그 시작여부(true: on, false: off)
	CPoint m_StartPos, m_EndPos;
	

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~Cassignment4_10_2012722081View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
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

#ifndef _DEBUG  // assignment4_10_2012722081View.cpp의 디버그 버전
inline Cassignment4_10_2012722081Doc* Cassignment4_10_2012722081View::GetDocument() const
   { return reinterpret_cast<Cassignment4_10_2012722081Doc*>(m_pDocument); }
#endif


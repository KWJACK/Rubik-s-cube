
// assignment4_10_2012722081Doc.h : Cassignment4_10_2012722081Doc 클래스의 인터페이스
//

#include "Face_list.h"
#include "loglist.h"
#pragma once


class Cassignment4_10_2012722081Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	Cassignment4_10_2012722081Doc();
	DECLARE_DYNCREATE(Cassignment4_10_2012722081Doc)

// 특성입니다.
public:
	Face_list mylist;
	loglist mylog;
	Face *pCur;//임시
	POINT front[9][4];//앞면좌표값---->값설정은 Ondraw에서 햇음
	POINT top[9][4];//윗면좌표값
	POINT next[9][4];//옆면좌표값
	void setPoint();
	COLORREF setColor(int number);//face가 갖고있는 배열의 값에 따라 색을 리턴함, number는 0~8까지의 값. 배열012)(345)(678)
	COLORREF setColor_up(int number);//face_up가 갖고있는 배열의 값에 따라 색을 리턴함, number는 0~8까지의 값. 배열012)(345)(678)
	COLORREF setColor_next(int number);//face_next가 갖고있는 배열의 값에 따라 색을 리턴함, number는 0~8까지의 값. 배열012)(345)(678)
	
	key_Log *pLog;//임시
	mouse_Log *pLog_m;
	bool colorWithNumber;//true이면 칼라+숫자, false이면 숫자가 나오지않도록
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~Cassignment4_10_2012722081Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void On32779();
	afx_msg void On32780();
};

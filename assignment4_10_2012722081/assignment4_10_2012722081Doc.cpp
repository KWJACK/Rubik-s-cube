
// assignment4_10_2012722081Doc.cpp : Cassignment4_10_2012722081Doc 클래스의 구현
//

#include "stdafx.h"

// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "assignment4_10_2012722081.h"
#endif

#include "assignment4_10_2012722081Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cassignment4_10_2012722081Doc

IMPLEMENT_DYNCREATE(Cassignment4_10_2012722081Doc, CDocument)

BEGIN_MESSAGE_MAP(Cassignment4_10_2012722081Doc, CDocument)
	ON_COMMAND(ID_32779, &Cassignment4_10_2012722081Doc::On32779)
	ON_COMMAND(ID_32780, &Cassignment4_10_2012722081Doc::On32780)
END_MESSAGE_MAP()


// Cassignment4_10_2012722081Doc 생성/소멸

Cassignment4_10_2012722081Doc::Cassignment4_10_2012722081Doc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
	
}

Cassignment4_10_2012722081Doc::~Cassignment4_10_2012722081Doc()
{
}

BOOL Cassignment4_10_2012722081Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.
	
	return TRUE;
}
//면의 칼라를 바꿔주는 함수. 순서대로 정면 윗면, 옆면
COLORREF Cassignment4_10_2012722081Doc::setColor(int number){
	int value = 0;
	COLORREF Color;
	value = mylist.getHead()->getNum(1 + number / 3, 1 + number % 3);
	if (value >= 1 && value <= 9)
		Color = RGB(255, 0, 0);//red
	else if (value >= 10 && value <= 18)
		Color = RGB(0, 255, 0);//green
	else if (value >= 19 && value <= 27)
		Color = RGB(255, 127, 0);//orange
	else if (value >= 28 && value <= 36)
		Color = RGB(0, 0, 255);//blue
	else if (value >= 37 && value <= 45)
		Color = RGB(255, 255, 0);//yellow
	else if (value >= 46 && value <= 54)
		Color = RGB(255, 255, 255);//white
	return Color;
}
COLORREF Cassignment4_10_2012722081Doc::setColor_up(int number){
	int value = 0;
	COLORREF Color;
	value = mylist.getHead()->getUp()->getNum(1 + number / 3, 1 + number % 3);
	if (value >= 1 && value <= 9)
		Color = RGB(255, 0, 0);//red
	else if (value >= 10 && value <= 18)
		Color = RGB(0, 255, 0);//green
	else if (value >= 19 && value <= 27)
		Color = RGB(255, 127, 0);//orange
	else if (value >= 28 && value <= 36)
		Color = RGB(0, 0, 255);//blue
	else if (value >= 37 && value <= 45)
		Color = RGB(255, 255, 0);//yellow
	else if (value >= 46 && value <= 54)
		Color = RGB(255, 255, 255);//white
	return Color;
}
COLORREF Cassignment4_10_2012722081Doc::setColor_next(int number){
	int value = 0;
	COLORREF Color;
	value = mylist.getHead()->getNext()->getNum(1 + number / 3, 1 + number % 3);
	if (value >= 1 && value <= 9)
		Color = RGB(255, 0, 0);//red
	else if (value >= 10 && value <= 18)
		Color = RGB(0, 255, 0);//green
	else if (value >= 19 && value <= 27)
		Color = RGB(255, 127, 0);//orange
	else if (value >= 28 && value <= 36)
		Color = RGB(0, 0, 255);//blue
	else if (value >= 37 && value <= 45)
		Color = RGB(255, 255, 0);//yellow
	else if (value >= 46 && value <= 54)
		Color = RGB(255, 255, 255);//white
	return Color;
}

// Cassignment4_10_2012722081Doc serialization

void Cassignment4_10_2012722081Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void Cassignment4_10_2012722081Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
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

// 검색 처리기를 지원합니다.
void Cassignment4_10_2012722081Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void Cassignment4_10_2012722081Doc::SetSearchContent(const CString& value)
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

// Cassignment4_10_2012722081Doc 진단

#ifdef _DEBUG
void Cassignment4_10_2012722081Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cassignment4_10_2012722081Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cassignment4_10_2012722081Doc 명령


void Cassignment4_10_2012722081Doc::On32779()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// 출력면 변경기록
}


void Cassignment4_10_2012722081Doc::On32780()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// 슬라이스 변경면 기록
}


// assignment4_10_2012722081Doc.cpp : Cassignment4_10_2012722081Doc Ŭ������ ����
//

#include "stdafx.h"

// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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


// Cassignment4_10_2012722081Doc ����/�Ҹ�

Cassignment4_10_2012722081Doc::Cassignment4_10_2012722081Doc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
	
}

Cassignment4_10_2012722081Doc::~Cassignment4_10_2012722081Doc()
{
}

BOOL Cassignment4_10_2012722081Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.
	
	return TRUE;
}
//���� Į�� �ٲ��ִ� �Լ�. ������� ���� ����, ����
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
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void Cassignment4_10_2012722081Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
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

// �˻� ó���⸦ �����մϴ�.
void Cassignment4_10_2012722081Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
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

// Cassignment4_10_2012722081Doc ����

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


// Cassignment4_10_2012722081Doc ���


void Cassignment4_10_2012722081Doc::On32779()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	// ��¸� ������
}


void Cassignment4_10_2012722081Doc::On32780()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	// �����̽� ����� ���
}


// assignment4_10_2012722081View.cpp : Cassignment4_10_2012722081View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "assignment4_10_2012722081.h"
#endif

#include "assignment4_10_2012722081Doc.h"
#include "assignment4_10_2012722081View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
/*����Ȯ��
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
*/
// Cassignment4_10_2012722081View

IMPLEMENT_DYNCREATE(Cassignment4_10_2012722081View, CView)

BEGIN_MESSAGE_MAP(Cassignment4_10_2012722081View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_32777, &Cassignment4_10_2012722081View::On32777)
	ON_COMMAND(ID_32778, &Cassignment4_10_2012722081View::On32778)
	ON_COMMAND(ID_32779, &Cassignment4_10_2012722081View::On32779)
	ON_COMMAND(ID_32780, &Cassignment4_10_2012722081View::On32780)
//	ON_WM_APPCOMMAND()
END_MESSAGE_MAP()

// Cassignment4_10_2012722081View ����/�Ҹ�

Cassignment4_10_2012722081View::Cassignment4_10_2012722081View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_BrushColor = RGB(255,255,0);
	m_bDragFlag = false;//false�� �ʱ�ȭ. �巡�� ���ϱ���������
}

Cassignment4_10_2012722081View::~Cassignment4_10_2012722081View()
{
}

BOOL Cassignment4_10_2012722081View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// Cassignment4_10_2012722081View �׸���

void Cassignment4_10_2012722081View::OnDraw(CDC* pDC)
{
	Cassignment4_10_2012722081Doc* pDoc = GetDocument();//pDoc�� Doc�� view���� ������ ������
														//Doc���� loglist, Face_list�� ���� ���� + ���⼭ �׸��� ��ǥ�� �ִ�
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int i = 0; i < 3; i++){//face�� ��ǥ(������Ʈ ���� 64X64 )
		for (int j = 0; j < 3; j++){
			pDoc->front[i*3+j][0].x = 300+64*j;
			pDoc->front[i * 3 + j][0].y = 300+64*i;

			pDoc->front[i * 3 + j][1].x = 300 + 64 + 64 * j;
			pDoc->front[i * 3 + j][1].y = 300 + 64 * i;

			pDoc->front[i * 3 + j][2].x = 300 + 64 + 64 * j;
			pDoc->front[i * 3 + j][2].y = 300 + 64 + 64 * i;

			pDoc->front[i * 3 + j][3].x = 300 + 64 * j;
			pDoc->front[i * 3 + j][3].y = 300 + 64 + 64 * i;
		}
	}
	for (int i = 0; i < 3; i++){//face ���ʸ� ��ǥ, ������ ��� ���Ƿ�..����纯�� ���� 50, Ƣ��ºκ� 30
		for (int j = 0; j < 3; j++){
			pDoc->top[i * 3 + j][0].x = 390 + j * 64- 30 * i;
			pDoc->top[i * 3 + j][0].y = 150 + 50 * i;

			pDoc->top[i * 3 + j][1].x = 390 + 64 + j * 64 - 30 * i;
			pDoc->top[i * 3 + j][1].y = 150 + 50 * i;

			pDoc->top[i * 3 + j][2].x = 390 + 64 - 30 + j * 64 - 30 * i;
			pDoc->top[i * 3 + j][2].y = 150 + 50 + 50 * i;

			pDoc->top[i * 3 + j][3].x = 390 - 30 + j * 64 - 30 * i;
			pDoc->top[i * 3 + j][3].y = 150 + 50 + 50 * i;
		}
	}
	for (int i = 0; i < 3; i++){//face �����ʸ� ��ǥ
		for (int j = 0; j < 3; j++){
			pDoc->next[i * 3 + j][0].x = 492 + j * 30;
			pDoc->next[i * 3 + j][0].y = 300 - j * 50 + i * 64;

			pDoc->next[i * 3 + j][1].x = 522 + j * 30;
			pDoc->next[i * 3 + j][1].y = 250 - j * 50 + i * 64;

			pDoc->next[i * 3 + j][2].x = 522 + j * 30;
			pDoc->next[i * 3 + j][2].y = 314 - j * 50 + i * 64;

			pDoc->next[i * 3 + j][3].x = 492 + j * 30;
			pDoc->next[i * 3 + j][3].y = 364 - j * 50 + i * 64;
		}
	}
	
	pDC->SetTextColor(RGB(0, 0, 0));//������
	

	for (int i = 0; i < 9;i++){//���� ���̽� �׸���
		m_BrushColor = pDoc->setColor(i);
		CBrush solidBrush(m_BrushColor);
		CBrush* p01dBrush = pDC->SelectObject(&solidBrush);		
		pDC->Polygon(pDoc->front[i], 4);		
		solidBrush.DeleteObject();//������Ʈ ����
		p01dBrush->DeleteObject();//������Ʈ ����
	}
	for (int i = 0; i < 9; i++){//���� ���̽� �׸���
		m_BrushColor = pDoc->setColor_up(i);
		CBrush solidBrush(m_BrushColor);
		CBrush* p01dBrush = pDC->SelectObject(&solidBrush);			
		pDC->Polygon(pDoc->top[i], 4);
		solidBrush.DeleteObject();
		p01dBrush->DeleteObject();
	}
	for (int i = 0; i < 9; i++){//���� ���̽� �׸���
		m_BrushColor = pDoc->setColor_next(i);
		CBrush solidBrush(m_BrushColor);
		CBrush* p01dBrush = pDC->SelectObject(&solidBrush);			
		pDC->Polygon(pDoc->next[i], 4);
		solidBrush.DeleteObject();
		p01dBrush->DeleteObject();
	}
	if (pDoc->colorWithNumber == true){//���̽� ���� �������
		
		CString buff_front;
		CString buff_top;
		CString buff_next;
		pDC->SetBkMode(TRANSPARENT);//���ڹ�� ����
		for (int i = 0; i < 9; i++){
			buff_front.Format(_T("%d"), pDoc->mylist.getHead()->getNum(1 + i / 3, 1 + i % 3));//for���� 0~8������ 3x3����� ǥ���ϱ�����
			//�����ġ�� i�� ������ ��, i�� �������� ��. ����1�� �����ִ°� ��� �Ǿձ����� 1,1�� �ޱ⶧�� 
			buff_top.Format(_T("%d"), pDoc->mylist.getHead()->getUp()->getNum(1 + i / 3, 1 + i % 3));
			buff_next.Format(_T("%d"), pDoc->mylist.getHead()->getNext()->getNum(1 + i / 3, 1 + i % 3));
			pDC->DrawText(buff_front, CRect(320 + 64 * (i % 3), 325 + 64 * (i / 3), 340 + 64 * (i % 3), 345 + 64 * (i / 3)), TA_CENTER);
			
			pDC->DrawText(buff_top, CRect(390 + 64 * (i % 3) - 30 * (i/3), 170 + 50 * (i / 3),
				410 + 64 * (i % 3) - 30 * (i / 3), 190 + 50 * (i / 3)), TA_CENTER);

			pDC->DrawText(buff_next, CRect(500 + 30 * (i % 3), 305 + 64 * (i / 3)-55 * (i % 3)
				, 515 + 30 * (i % 3), 335 + 64 * (i / 3)-55 * (i % 3)), TA_CENTER);
		}		
	}//DT_VCENTER

	
}


// Cassignment4_10_2012722081View �μ�

BOOL Cassignment4_10_2012722081View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void Cassignment4_10_2012722081View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void Cassignment4_10_2012722081View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// Cassignment4_10_2012722081View ����

#ifdef _DEBUG
void Cassignment4_10_2012722081View::AssertValid() const
{
	CView::AssertValid();
}

void Cassignment4_10_2012722081View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cassignment4_10_2012722081Doc* Cassignment4_10_2012722081View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cassignment4_10_2012722081Doc)));
	return (Cassignment4_10_2012722081Doc*)m_pDocument;
}
#endif //_DEBUG


// Cassignment4_10_2012722081View �޽��� ó����


int Cassignment4_10_2012722081View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return 0;
}


void Cassignment4_10_2012722081View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	Cassignment4_10_2012722081Doc* pDoc = GetDocument();//pDoc����
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->pCur = pDoc->mylist.getHead();//Face�� pCur�� ����� �޵���
	switch (nChar){
	case VK_UP:
		pDoc->mylist.key_up();
		pDoc->pLog = new key_Log;
		pDoc->pLog->set_keylog("Key_Up");//�αװ� ���, �޸� ������ keylist����
		pDoc->mylog.insert_keylog(pDoc->pLog);
		break;
	case VK_DOWN:
		pDoc->mylist.key_down();
		pDoc->pLog = new key_Log;
		pDoc->pLog->set_keylog("Key_Down");
		pDoc->mylog.insert_keylog(pDoc->pLog);
		break;
	case VK_LEFT:	
		pDoc->mylist.key_left();
		pDoc->pLog = new key_Log;
		pDoc->pLog->set_keylog("Key_Left");
		pDoc->mylog.insert_keylog(pDoc->pLog);
		break;
	case VK_RIGHT:
		pDoc->mylist.key_right();
		pDoc->pLog = new key_Log;
		pDoc->pLog->set_keylog("Key_Right");
		pDoc->mylog.insert_keylog(pDoc->pLog);
		break;
	default:
		break;
	}
	Invalidate(TRUE);
	
}


void Cassignment4_10_2012722081View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	//���콺 �̺�Ʈ�� �̵���δ� buttondown->mousemove->buttonup �̴�.
	m_StartPos = point;//��ư�� ���� ������ǥ�ֱ�
	m_bDragFlag = true; //���콺 Ŭ�� ����
	SetCapture();
	CView::OnLButtonDown(nFlags, point);
}


void Cassignment4_10_2012722081View::OnMouseMove(UINT nFlags, CPoint point)
{
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_bDragFlag){
		m_EndPos = point;//���콺�� �� ������ �� ��ǥ�� ��ӹٲ��.
		CPoint pos = m_EndPos - m_StartPos;		
	}
	
	CView::OnMouseMove(nFlags, point);
}

void Cassignment4_10_2012722081View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	Cassignment4_10_2012722081Doc* pDoc = GetDocument();//pDoc����
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (m_bDragFlag == true){
		m_EndPos = point;
		Invalidate();
	}	
	//Ŭ���� ������ ���� �����̼��Լ��� ����
	/////////����, ����, ������ ���� 1~12�������� �����̼��� ����
	//////////////////////////////////////////����
	string temp, temp_up, temp_next;//���� ����. (A,B,C,D,E,F)
	char head = pDoc->mylist.getHead()->getface();//��ť��Ʈ�� ���� �ִ� ���� ������ char
	char head_up = pDoc->mylist.getHead()->getUp()->getface();
	char head_next = pDoc->mylist.getHead()->getNext()->getface();
	temp = head;//string ������ �Ű���, txt�� ��ϵɶ� string�ϳ��� �������Բ� �س��� ������
	temp_up = head_up;
	temp_next = head_next;
	string mouselog;
	///����, ����, ������ ��ǥ���� ���� rotation�Լ��� �����ϱ� ���� 36���� ���ǹ�=����(12),����(12),����(12) 
	if (m_EndPos.x <= 364 && m_EndPos.x >= 300 && m_EndPos.y >= 300 && m_EndPos.y <= 364
		&& m_StartPos.y >= 428 && m_StartPos.y <= 492 && m_StartPos.x >= 300 && m_StartPos.x <= 364){
		pDoc->mylist.Rotation_1();//�����̼�1����
		pDoc->pLog_m = new mouse_Log;
		mouselog = "Face: / Col: 1 / Up";
		mouselog.insert(5, temp);//5�� Face:(5�ڸ�) ������ temp(��)�ڰ� ���� ���ؼ�
		pDoc->pLog_m->set_mouselog(mouselog);//���콺 �̺�Ʈ ������ ���� ��带 ����
		pDoc->mylog.insert_mouselog(pDoc->pLog_m);// �α׸� �����ϴ� ����Ʈ�� ����
		}
		else if (m_EndPos.x <= 428 && m_EndPos.x >= 364 && m_EndPos.y >= 300 && m_EndPos.y <= 364
			&& m_StartPos.y >= 428 && m_StartPos.y <= 492 && m_StartPos.x >= 364 && m_StartPos.x <= 428){
			pDoc->mylist.Rotation_2();
			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 2 / Up";
			mouselog.insert(5, temp);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);
		}
		else if (m_EndPos.x <= 492 && m_EndPos.x >= 428 && m_EndPos.y >= 300 && m_EndPos.y <= 364
			&& m_StartPos.y >= 428 && m_StartPos.y <= 492 && m_StartPos.x >= 428 && m_StartPos.x <= 492){
			pDoc->mylist.Rotation_3();
			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 3 / Up";
			mouselog.insert(5, temp);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);
		}
		else if (m_EndPos.x <= 492 && m_EndPos.x >= 428 && m_EndPos.y >= 300 && m_EndPos.y <= 364
			&& m_StartPos.y >= 300 && m_StartPos.y <= 364 && m_StartPos.x >= 300 && m_StartPos.x <= 364){
			pDoc->mylist.Rotation_4();
			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 1 / Right";
			mouselog.insert(5, temp);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);
		}
		else if (m_EndPos.x <= 492 && m_EndPos.x >= 428 && m_EndPos.y >= 364 && m_EndPos.y <= 428
			&& m_StartPos.y >= 364 && m_StartPos.y <= 428 && m_StartPos.x >= 300 && m_StartPos.x <= 364){
			pDoc->mylist.Rotation_5();
			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 2 / Right";
			mouselog.insert(5, temp);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);
		}
		else if (m_EndPos.x <= 492 && m_EndPos.x >= 428 && m_EndPos.y >= 428 && m_EndPos.y <= 492
			&& m_StartPos.y >= 428 && m_StartPos.y <= 492 && m_StartPos.x >= 300 && m_StartPos.x <= 364){
			pDoc->mylist.Rotation_6();
			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 3 / Right";
			mouselog.insert(5, temp);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);
		} 
		else if (m_EndPos.x <= 364 && m_EndPos.x >= 300 && m_EndPos.y >= 428 && m_EndPos.y <= 492
			&& m_StartPos.y >= 300 && m_StartPos.y <= 364 && m_StartPos.x >= 300 && m_StartPos.x <= 364){
			pDoc->mylist.Rotation_7();
			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 1 / Down";
			mouselog.insert(5, temp);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);
		}
		else if (m_EndPos.x <= 428 && m_EndPos.x >= 364 && m_EndPos.y >= 428 && m_EndPos.y <= 492
			&& m_StartPos.y >= 300 && m_StartPos.y <= 364 && m_StartPos.x >= 364 && m_StartPos.x <= 428){
			pDoc->mylist.Rotation_8();
			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 2 / Down";
			mouselog.insert(5, temp);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);
		}
		else if (m_EndPos.x <= 492 && m_EndPos.x >= 428 && m_EndPos.y >= 428 && m_EndPos.y <= 492
			&& m_StartPos.y >= 300 && m_StartPos.y <= 364 && m_StartPos.x >= 428 && m_StartPos.x <= 492){
			pDoc->mylist.Rotation_9();
			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 3 / Down";
			mouselog.insert(5, temp);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);
		}

		else if (m_EndPos.x <= 364 && m_EndPos.x >= 300 && m_EndPos.y >= 428 && m_EndPos.y <= 492
			&& m_StartPos.y >= 428 && m_StartPos.y <= 492 && m_StartPos.x >= 428 && m_StartPos.x <= 492){
			pDoc->mylist.Rotation_10();
			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 3 / Left";
			mouselog.insert(5, temp);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);
		}
		else if (m_EndPos.x <= 364 && m_EndPos.x >= 300 && m_EndPos.y >= 364 && m_EndPos.y <= 428
			&& m_StartPos.y >= 364 && m_StartPos.y <= 428 && m_StartPos.x >= 428 && m_StartPos.x <= 492){
			pDoc->mylist.Rotation_11();
			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 2 / Left";
			mouselog.insert(5, temp);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

		}
		else if (m_EndPos.x <= 364 && m_EndPos.x >= 300 && m_EndPos.y >= 300 && m_EndPos.y <= 364
			&& m_StartPos.y >= 300 && m_StartPos.y <= 492 && m_StartPos.x >= 428 && m_StartPos.x <= 492){
			pDoc->mylist.Rotation_12();
			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 1/ Left";
			mouselog.insert(5, temp);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);
		}

	////////////////////////////////////////////����
		else if (m_EndPos.x <= 424 && m_EndPos.x >= 360 && m_EndPos.y >= 150 && m_EndPos.y <= 200
			&& m_StartPos.y >=250 && m_StartPos.y <= 300 && m_StartPos.x >= 300 && m_StartPos.x <= 394){
		pDoc->mylist.key_down();//key_down�� ť�������� ������ �ǵ��� �ϹǷ�, ���鿡 ���� �����̼��ϱ� ���ؼ� key_down����
		
		pDoc->pLog_m = new mouse_Log;
		mouselog = "Face: / Col: 1/ Up";
		mouselog.insert(5, temp_up);
		pDoc->pLog_m->set_mouselog(mouselog);
		pDoc->mylog.insert_mouselog(pDoc->pLog_m);

		pDoc->mylist.Rotation_1();//������
		pDoc->mylist.key_down();
		pDoc->mylist.key_down();
		pDoc->mylist.key_down();//���� ����� ���ƿ�
		}
		else if (m_EndPos.x <= 488 && m_EndPos.x >= 424 && m_EndPos.y >= 150 && m_EndPos.y <= 200
			&& m_StartPos.y >= 250 && m_StartPos.y <= 300 && m_StartPos.x >= 364 && m_StartPos.x <= 468){
			pDoc->mylist.key_down();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 2/ Up";
			mouselog.insert(5, temp_up);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_2();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
		}
		else if (m_EndPos.x <= 552 && m_EndPos.x >= 488 && m_EndPos.y >= 150 && m_EndPos.y <= 200
			&& m_StartPos.y >= 250 && m_StartPos.y <= 300 && m_StartPos.x >= 428 && m_StartPos.x <= 532){
			pDoc->mylist.key_down();
	
			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 3/ Up";
			mouselog.insert(5, temp_up);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_3();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
		}
		else if (m_EndPos.x <= 582 && m_EndPos.x >= 488 && m_EndPos.y >= 150 && m_EndPos.y <= 200
			&& m_StartPos.y >= 150 && m_StartPos.y <= 200 && m_StartPos.x >= 300 && m_StartPos.x <= 454){
			pDoc->mylist.key_down();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 1/ Right";
			mouselog.insert(5, temp_up);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_4();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
		}
		else if (m_EndPos.x <= 552 && m_EndPos.x >= 468 && m_EndPos.y >= 200 && m_EndPos.y <= 250
			&& m_StartPos.y >= 200 && m_StartPos.y <= 250 && m_StartPos.x >= 300 && m_StartPos.x <= 454){
			pDoc->mylist.key_down();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 2/ Right";
			mouselog.insert(5, temp_up);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_5();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
		}
		else if (m_EndPos.x <= 532 && m_EndPos.x >= 428 && m_EndPos.y >= 250 && m_EndPos.y <= 300
			&& m_StartPos.y >= 250 && m_StartPos.y <= 300 && m_StartPos.x >= 300 && m_StartPos.x <= 454){
			pDoc->mylist.key_down();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 3/ Right";
			mouselog.insert(5, temp_up);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_6();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
		}
		else if (m_EndPos.x <= 394 && m_EndPos.x >= 300 && m_EndPos.y >= 250 && m_EndPos.y <= 300
			&& m_StartPos.y >= 150 && m_StartPos.y <= 200 && m_StartPos.x >= 360 && m_StartPos.x <= 454){
			pDoc->mylist.key_down();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 1 / Down";
			mouselog.insert(5, temp_up);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_7();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
		}
		else if (m_EndPos.x <= 468 && m_EndPos.x >= 364 && m_EndPos.y >= 250 && m_EndPos.y <= 300
			&& m_StartPos.y >= 150 && m_StartPos.y <= 200 && m_StartPos.x >= 424 && m_StartPos.x <= 518){
			pDoc->mylist.key_down();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 2 / Down";
			mouselog.insert(5, temp_up);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_8();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
		}
		else if (m_EndPos.x <= 532 && m_EndPos.x >= 428 && m_EndPos.y >= 250 && m_EndPos.y <= 300
			&& m_StartPos.y >= 150 && m_StartPos.y <= 200 && m_StartPos.x >= 488 && m_StartPos.x <= 582){
			pDoc->mylist.key_down();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 3 / Down";
			mouselog.insert(5, temp_up);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_9();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
		}
		else if (m_EndPos.x <= 394 && m_EndPos.x >= 300 && m_EndPos.y >= 250 && m_EndPos.y <= 300
			&& m_StartPos.y >= 250 && m_StartPos.y <= 300 && m_StartPos.x >= 428 && m_StartPos.x <= 582){
			pDoc->mylist.key_down();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 3 / Left";
			mouselog.insert(5, temp_up);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_10();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
		}
		else if (m_EndPos.x <= 424 && m_EndPos.x >= 330 && m_EndPos.y >= 200 && m_EndPos.y <= 250
			&& m_StartPos.y >= 200 && m_StartPos.y <= 250 && m_StartPos.x >= 428 && m_StartPos.x <= 582){
			pDoc->mylist.key_down();//����� ���� �ű���

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 2 / Left";
			mouselog.insert(5, temp_up);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_11();//������
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
		}
		else if (m_EndPos.x <= 454 && m_EndPos.x >= 360 && m_EndPos.y >= 150 && m_EndPos.y <= 200
			&& m_StartPos.y >= 150 && m_StartPos.y <= 200 && m_StartPos.x >= 428 && m_StartPos.x <= 582){
			pDoc->mylist.key_down();//����� ���� �ű���

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 1 / Left";
			mouselog.insert(5, temp_up);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_12();//������
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
		}

		/////////////////////////////////////����
		else if (m_EndPos.x <= 552 && m_EndPos.x >= 492 && m_EndPos.y >= 250 && m_EndPos.y <= 364
			&& m_StartPos.y >= 378 && m_StartPos.y <= 492 && m_StartPos.x >= 492 && m_StartPos.x <= 522){
			pDoc->mylist.key_left();//����� ���� �ű���, key_left�� ť������ʸ��� ������ �ǵ��� �Ű��ش�
									//�츮�� �����̼� �ϰ���� ���� �����ʸ��̹Ƿ�, �����ʸ��� �������� �Űܼ� �����̼� ����
			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 1 / Up";
			mouselog.insert(5, temp_next);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_1();//������
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();//���� ����� ���ƿ�
		}
		else if (m_EndPos.x <= 552 && m_EndPos.x >= 522 && m_EndPos.y >= 200 && m_EndPos.y <= 314
			&& m_StartPos.y >= 328 && m_StartPos.y <= 442 && m_StartPos.x >= 522 && m_StartPos.x <= 552){
			pDoc->mylist.key_left();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 2 / Up";
			mouselog.insert(5, temp_next);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_2();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
		}
		else if (m_EndPos.x <= 582 && m_EndPos.x >= 552 && m_EndPos.y >= 150 && m_EndPos.y <= 264
			&& m_StartPos.y >= 278 && m_StartPos.y <= 392 && m_StartPos.x >= 552 && m_StartPos.x <= 582){
			pDoc->mylist.key_left();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 3 / Up";
			mouselog.insert(5, temp_next);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_3();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
		}
		else if (m_EndPos.x <= 582 && m_EndPos.x >= 552 && m_EndPos.y >= 150 && m_EndPos.y <= 264
			&& m_StartPos.y >= 250 && m_StartPos.y <= 364 && m_StartPos.x >= 492 && m_StartPos.x <= 522){
			pDoc->mylist.key_left();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 1 / RIght";
			mouselog.insert(5, temp_next);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_4();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
		}
		else if (m_EndPos.x <= 582 && m_EndPos.x >= 552 && m_EndPos.y >= 214 && m_EndPos.y <= 328
			&& m_StartPos.y >= 314 && m_StartPos.y <= 428 && m_StartPos.x >= 492 && m_StartPos.x <= 522){
			pDoc->mylist.key_left();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 2 / RIght";
			mouselog.insert(5, temp_next);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_5();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
		}
		else if (m_EndPos.x <= 582 && m_EndPos.x >= 552 && m_EndPos.y >= 278 && m_EndPos.y <= 392
			&& m_StartPos.y >= 378 && m_StartPos.y <= 492 && m_StartPos.x >= 492 && m_StartPos.x <= 522){
			pDoc->mylist.key_left();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 3 / RIght";
			mouselog.insert(5, temp_next);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_6();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
		}
		else if (m_EndPos.x <= 522 && m_EndPos.x >= 492 && m_EndPos.y >= 378 && m_EndPos.y <= 492
			&& m_StartPos.y >= 250 && m_StartPos.y <= 364 && m_StartPos.x >= 492 && m_StartPos.x <= 522){
			pDoc->mylist.key_left();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 1 / Down";
			mouselog.insert(5, temp_next);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_7();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
		}
		else if (m_EndPos.x <= 552 && m_EndPos.x >= 522 && m_EndPos.y >= 328 && m_EndPos.y <= 442
			&& m_StartPos.y >= 200 && m_StartPos.y <= 314 && m_StartPos.x >= 522 && m_StartPos.x <= 552){
			pDoc->mylist.key_left();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 2 / Down";
			mouselog.insert(5, temp_next);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_8();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
		}
		else if (m_EndPos.x <= 582 && m_EndPos.x >= 552 && m_EndPos.y >= 278 && m_EndPos.y <= 392
			&& m_StartPos.y >= 150 && m_StartPos.y <= 264 && m_StartPos.x >= 552 && m_StartPos.x <= 582){
			pDoc->mylist.key_left();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 3 / Down";
			mouselog.insert(5, temp_next);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_9();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
		}
		else if (m_EndPos.x <= 522 && m_EndPos.x >= 492 && m_EndPos.y >= 378 && m_EndPos.y <= 492
			&& m_StartPos.y >= 278 && m_StartPos.y <= 392 && m_StartPos.x >= 552 && m_StartPos.x <= 582){
			pDoc->mylist.key_left();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 3 / Left";
			mouselog.insert(5, temp_next);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_10();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
		}
		else if (m_EndPos.x <= 522 && m_EndPos.x >= 492 && m_EndPos.y >= 314 && m_EndPos.y <= 428
			&& m_StartPos.y >= 214 && m_StartPos.y <= 328 && m_StartPos.x >= 552 && m_StartPos.x <= 582){
			pDoc->mylist.key_left();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 2 / Left";
			mouselog.insert(5, temp_next);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_11();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
		}
		else if (m_EndPos.x <= 522 && m_EndPos.x >= 492 && m_EndPos.y >= 250 && m_EndPos.y <= 364
			&& m_StartPos.y >= 150 && m_StartPos.y <= 264 && m_StartPos.x >= 552 && m_StartPos.x <= 582){
			pDoc->mylist.key_left();

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 1 / Left";
			mouselog.insert(5, temp_next);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_12();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
		}
	ReleaseCapture();
	m_StartPos = false;//���콺���� �� ��
	CView::OnLButtonUp(nFlags, point);
	
}


void Cassignment4_10_2012722081View::On32777()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	// �޴�-����
	Cassignment4_10_2012722081Doc* pDoc = GetDocument();//pDoc����
	ASSERT_VALID(pDoc);
	pDoc->colorWithNumber = false;//false�� �Ǹ� ���� ���X
	Invalidate(TRUE);
}


void Cassignment4_10_2012722081View::On32778()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	//�޴�-����+����
	Cassignment4_10_2012722081Doc* pDoc = GetDocument();//pDoc����
	ASSERT_VALID(pDoc);
	pDoc->colorWithNumber = true;//true�� �Ǹ� ���� ���
	Invalidate(TRUE);
	
}


void Cassignment4_10_2012722081View::On32779()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	// ��¸� ���
	Cassignment4_10_2012722081Doc* pDoc = GetDocument();//pDoc����
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->mylog.writelogfile_k();//Ű���� �Է� �α� ���
}


void Cassignment4_10_2012722081View::On32780()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	//�����̽� ��¸� ���
	Cassignment4_10_2012722081Doc* pDoc = GetDocument();//pDoc����
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->mylog.writelogfile_m();//���콺 �Է� �α� ���
}


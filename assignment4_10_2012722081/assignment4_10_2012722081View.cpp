
// assignment4_10_2012722081View.cpp : Cassignment4_10_2012722081View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "assignment4_10_2012722081.h"
#endif

#include "assignment4_10_2012722081Doc.h"
#include "assignment4_10_2012722081View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
/*누수확인
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
*/
// Cassignment4_10_2012722081View

IMPLEMENT_DYNCREATE(Cassignment4_10_2012722081View, CView)

BEGIN_MESSAGE_MAP(Cassignment4_10_2012722081View, CView)
	// 표준 인쇄 명령입니다.
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

// Cassignment4_10_2012722081View 생성/소멸

Cassignment4_10_2012722081View::Cassignment4_10_2012722081View()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_BrushColor = RGB(255,255,0);
	m_bDragFlag = false;//false로 초기화. 드래그 온하기전까지는
}

Cassignment4_10_2012722081View::~Cassignment4_10_2012722081View()
{
}

BOOL Cassignment4_10_2012722081View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cassignment4_10_2012722081View 그리기

void Cassignment4_10_2012722081View::OnDraw(CDC* pDC)
{
	Cassignment4_10_2012722081Doc* pDoc = GetDocument();//pDoc은 Doc과 view간을 오가는 포인터
														//Doc에는 loglist, Face_list에 관한 정보 + 여기서 그리는 좌표가 있다
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int i = 0; i < 3; i++){//face면 좌표(프로젝트 조건 64X64 )
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
	for (int i = 0; i < 3; i++){//face 위쪽면 좌표, 조건이 없어서 임의로..평행사변형 높이 50, 튀어나온부분 30
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
	for (int i = 0; i < 3; i++){//face 오른쪽면 좌표
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
	
	pDC->SetTextColor(RGB(0, 0, 0));//검은색
	

	for (int i = 0; i < 9;i++){//정면 페이스 그리기
		m_BrushColor = pDoc->setColor(i);
		CBrush solidBrush(m_BrushColor);
		CBrush* p01dBrush = pDC->SelectObject(&solidBrush);		
		pDC->Polygon(pDoc->front[i], 4);		
		solidBrush.DeleteObject();//오브젝트 해제
		p01dBrush->DeleteObject();//오브젝트 해제
	}
	for (int i = 0; i < 9; i++){//윗면 페이스 그리기
		m_BrushColor = pDoc->setColor_up(i);
		CBrush solidBrush(m_BrushColor);
		CBrush* p01dBrush = pDC->SelectObject(&solidBrush);			
		pDC->Polygon(pDoc->top[i], 4);
		solidBrush.DeleteObject();
		p01dBrush->DeleteObject();
	}
	for (int i = 0; i < 9; i++){//옆면 페이스 그리기
		m_BrushColor = pDoc->setColor_next(i);
		CBrush solidBrush(m_BrushColor);
		CBrush* p01dBrush = pDC->SelectObject(&solidBrush);			
		pDC->Polygon(pDoc->next[i], 4);
		solidBrush.DeleteObject();
		p01dBrush->DeleteObject();
	}
	if (pDoc->colorWithNumber == true){//페이스 내에 숫자출력
		
		CString buff_front;
		CString buff_top;
		CString buff_next;
		pDC->SetBkMode(TRANSPARENT);//글자배경 투명
		for (int i = 0; i < 9; i++){
			buff_front.Format(_T("%d"), pDoc->mylist.getHead()->getNum(1 + i / 3, 1 + i % 3));//for문이 0~8까지라 3x3행렬을 표기하기위해
			//행렬위치를 i를 나눈게 행, i의 나머지는 열. 각각1을 더해주는건 행렬 맨앞기준을 1,1로 햇기때문 
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


// Cassignment4_10_2012722081View 인쇄

BOOL Cassignment4_10_2012722081View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cassignment4_10_2012722081View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cassignment4_10_2012722081View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// Cassignment4_10_2012722081View 진단

#ifdef _DEBUG
void Cassignment4_10_2012722081View::AssertValid() const
{
	CView::AssertValid();
}

void Cassignment4_10_2012722081View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cassignment4_10_2012722081Doc* Cassignment4_10_2012722081View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cassignment4_10_2012722081Doc)));
	return (Cassignment4_10_2012722081Doc*)m_pDocument;
}
#endif //_DEBUG


// Cassignment4_10_2012722081View 메시지 처리기


int Cassignment4_10_2012722081View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}


void Cassignment4_10_2012722081View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	Cassignment4_10_2012722081Doc* pDoc = GetDocument();//pDoc생성
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->pCur = pDoc->mylist.getHead();//Face의 pCur가 헤더를 받도록
	switch (nChar){
	case VK_UP:
		pDoc->mylist.key_up();
		pDoc->pLog = new key_Log;
		pDoc->pLog->set_keylog("Key_Up");//로그값 기록, 메모리 해제는 keylist에서
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//마우스 이벤트의 이동경로는 buttondown->mousemove->buttonup 이다.
	m_StartPos = point;//버튼이 눌린 시작좌표넣기
	m_bDragFlag = true; //마우스 클릭 상태
	SetCapture();
	CView::OnLButtonDown(nFlags, point);
}


void Cassignment4_10_2012722081View::OnMouseMove(UINT nFlags, CPoint point)
{
	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDragFlag){
		m_EndPos = point;//마우스를 뗄 때까지 끝 좌표는 계속바뀐다.
		CPoint pos = m_EndPos - m_StartPos;		
	}
	
	CView::OnMouseMove(nFlags, point);
}

void Cassignment4_10_2012722081View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	Cassignment4_10_2012722081Doc* pDoc = GetDocument();//pDoc생성
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (m_bDragFlag == true){
		m_EndPos = point;
		Invalidate();
	}	
	//클릭이 떨어진 순간 로테이션함수를 적용
	/////////정면, 윗면, 옆면이 각각 1~12번까지의 로테이션이 적용
	//////////////////////////////////////////정면
	string temp, temp_up, temp_next;//면의 정보. (A,B,C,D,E,F)
	char head = pDoc->mylist.getHead()->getface();//다큐먼트가 갖고 있는 면의 정보는 char
	char head_up = pDoc->mylist.getHead()->getUp()->getface();
	char head_next = pDoc->mylist.getHead()->getNext()->getface();
	temp = head;//string 변수로 옮겨줌, txt에 기록될때 string하나로 씌여지게끔 해놨기 때문에
	temp_up = head_up;
	temp_next = head_next;
	string mouselog;
	///정면, 윗면, 옆면의 좌표값에 따른 rotation함수를 적용하기 위해 36개의 조건문=정면(12),윗면(12),옆면(12) 
	if (m_EndPos.x <= 364 && m_EndPos.x >= 300 && m_EndPos.y >= 300 && m_EndPos.y <= 364
		&& m_StartPos.y >= 428 && m_StartPos.y <= 492 && m_StartPos.x >= 300 && m_StartPos.x <= 364){
		pDoc->mylist.Rotation_1();//로테이션1적용
		pDoc->pLog_m = new mouse_Log;
		mouselog = "Face: / Col: 1 / Up";
		mouselog.insert(5, temp);//5는 Face:(5자리) 다음에 temp(면)자가 들어가기 위해서
		pDoc->pLog_m->set_mouselog(mouselog);//마우스 이벤트 정보를 토대로 노드를 생성
		pDoc->mylog.insert_mouselog(pDoc->pLog_m);// 로그를 관리하는 리스트에 삽입
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

	////////////////////////////////////////////윗면
		else if (m_EndPos.x <= 424 && m_EndPos.x >= 360 && m_EndPos.y >= 150 && m_EndPos.y <= 200
			&& m_StartPos.y >=250 && m_StartPos.y <= 300 && m_StartPos.x >= 300 && m_StartPos.x <= 394){
		pDoc->mylist.key_down();//key_down은 큐브윗면이 정면이 되도록 하므로, 윗면에 대해 로테이션하기 위해선 key_down을함
		
		pDoc->pLog_m = new mouse_Log;
		mouselog = "Face: / Col: 1/ Up";
		mouselog.insert(5, temp_up);
		pDoc->pLog_m->set_mouselog(mouselog);
		pDoc->mylog.insert_mouselog(pDoc->pLog_m);

		pDoc->mylist.Rotation_1();//돌린다
		pDoc->mylist.key_down();
		pDoc->mylist.key_down();
		pDoc->mylist.key_down();//원래 헤더로 돌아옴
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
			pDoc->mylist.key_down();//헤더를 위로 옮긴후

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 2 / Left";
			mouselog.insert(5, temp_up);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_11();//돌린다
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
		}
		else if (m_EndPos.x <= 454 && m_EndPos.x >= 360 && m_EndPos.y >= 150 && m_EndPos.y <= 200
			&& m_StartPos.y >= 150 && m_StartPos.y <= 200 && m_StartPos.x >= 428 && m_StartPos.x <= 582){
			pDoc->mylist.key_down();//헤더를 위로 옮긴후

			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Row: 1 / Left";
			mouselog.insert(5, temp_up);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_12();//돌린다
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
			pDoc->mylist.key_down();
		}

		/////////////////////////////////////옆면
		else if (m_EndPos.x <= 552 && m_EndPos.x >= 492 && m_EndPos.y >= 250 && m_EndPos.y <= 364
			&& m_StartPos.y >= 378 && m_StartPos.y <= 492 && m_StartPos.x >= 492 && m_StartPos.x <= 522){
			pDoc->mylist.key_left();//헤더를 옆로 옮긴후, key_left는 큐브오른쪽면이 정면이 되도록 옮겨준다
									//우리가 로테이션 하고싶은 면이 오른쪽면이므로, 오른쪽면을 정면으로 옮겨서 로테이션 적용
			pDoc->pLog_m = new mouse_Log;
			mouselog = "Face: / Col: 1 / Up";
			mouselog.insert(5, temp_next);
			pDoc->pLog_m->set_mouselog(mouselog);
			pDoc->mylog.insert_mouselog(pDoc->pLog_m);

			pDoc->mylist.Rotation_1();//돌린다
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();
			pDoc->mylist.key_left();//원래 헤더로 돌아옴
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
	m_StartPos = false;//마우스에서 손 뗌
	CView::OnLButtonUp(nFlags, point);
	
}


void Cassignment4_10_2012722081View::On32777()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// 메뉴-색상
	Cassignment4_10_2012722081Doc* pDoc = GetDocument();//pDoc생성
	ASSERT_VALID(pDoc);
	pDoc->colorWithNumber = false;//false가 되면 숫자 기록X
	Invalidate(TRUE);
}


void Cassignment4_10_2012722081View::On32778()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	//메뉴-색상+숫자
	Cassignment4_10_2012722081Doc* pDoc = GetDocument();//pDoc생성
	ASSERT_VALID(pDoc);
	pDoc->colorWithNumber = true;//true가 되면 숫자 기록
	Invalidate(TRUE);
	
}


void Cassignment4_10_2012722081View::On32779()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// 출력면 기록
	Cassignment4_10_2012722081Doc* pDoc = GetDocument();//pDoc생성
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->mylog.writelogfile_k();//키보드 입력 로그 기록
}


void Cassignment4_10_2012722081View::On32780()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	//슬라이스 출력면 기록
	Cassignment4_10_2012722081Doc* pDoc = GetDocument();//pDoc생성
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->mylog.writelogfile_m();//마우스 입력 로그 기록
}


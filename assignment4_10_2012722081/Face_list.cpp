#include "stdafx.h"
#include "Face_list.h"


Face_list::Face_list()//생성자에서 바로 큐브생성
{
	Face *A = new Face();
	A->setNum_Face(0);
	Face *B = new Face();
	B->setNum_Face(1);
	Face *C = new Face();
	C->setNum_Face(2);
	Face *D = new Face();
	D->setNum_Face(3);
	Face *E = new Face();
	E->setNum_Face(4);
	Face *F = new Face();
	F->setNum_Face(5);
	A->setNext(B);
	B->setNext(C);
	C->setNext(D);
	D->setNext(A);

	A->setUp(E);
	E->setUp(C);
	C->setUp(F);
	F->setUp(A);

	setHead(A);
}

Face_list::~Face_list()
{
	Face *temp1, *temp2, *temp3;
	temp1 = getHead();
	temp2 = getHead()->getUp();
	temp3 = getHead()->getUp()->getUp()->getUp();
	for (int i = 0; i < 3; i++){//옆면 3면해제
		Face *deletespace = temp1;
		temp1 = temp1->getNext();
		delete deletespace;
	}
	delete temp1;//옆면 마지막 해제
	delete temp2;//윗면 해제
	delete temp3;//아랫면 해제
	


}
////keydown과 key up은 돌릴때마다 윗면 혹은 아랫면과 정면의 반댓면을 반시계방향 180도를 회전해야 올바른 숫자값이 나옴////
///큐브 전개도는 프로젝트 관계도 참고///
void Face_list::key_left(){//좌측으로 회전, 정면에서 바라본 오른쪽면이 정면이 된다.
	Face *pCur = getHead();
	Face *temp_up = pCur->getUp();
	Face *temp_down = pCur->getUp()->getUp()->getUp();
	Face *temp_right = pCur->getNext()->getNext()->getNext();

	pCur->getNext()->getNext()->setUp(NULL);//C에서 F로 가는 길을 없앰
	setHead(getHead()->getNext());
	pCur = getHead();
	pCur->setUp(temp_up);
	pCur = pCur->getUp();
	pCur->clockwise();//헤드윗면 값이 반시계방향회전
	pCur->setUp(temp_right);
	pCur = pCur->getUp();
	pCur->setUp(temp_down);
	pCur = pCur->getUp();
	pCur->clockwise_c();//헤드 아랫면 값이 시계방향회전
	pCur->setUp(getHead());
}
void Face_list::key_right(){
	Face *pCur = getHead();
	Face *temp_up = pCur->getUp();
	Face *temp_down = pCur->getUp()->getUp()->getUp();
	Face *temp_right = pCur->getNext();

	pCur->getNext()->getNext()->setUp(NULL);//C에서 F로 가는 길을 없앰
	setHead(getHead()->getNext()->getNext()->getNext());
	pCur = getHead();
	pCur->setUp(temp_up);
	pCur = pCur->getUp();
	pCur->clockwise_c();//헤드윗면 값이 시계방향회전
	pCur->setUp(temp_right);
	pCur = pCur->getUp();
	pCur->setUp(temp_down);
	pCur = pCur->getUp();
	pCur->clockwise();//헤드 아랫면 값이 시계방향회전
	pCur->setUp(getHead());
}
void Face_list::key_up(){
	Face *pCur = getHead();
	Face *temp_B = pCur->getNext();
	Face *temp_E = pCur->getUp();
	Face *temp_D = pCur->getNext()->getNext()->getNext();

	pCur = getHead();
	pCur = pCur->getUp();//헤더의 윗면을 반시계방향으로 180도 돌림
	pCur->clockwise_c();
	pCur->clockwise_c();
	pCur = pCur->getUp();//헤더의 반댓면도 반시계방향으로 180도 돌림
	pCur->clockwise_c();
	pCur->clockwise_c();
	pCur = getHead();

	pCur->setNext(NULL);
	setHead(getHead()->getUp()->getUp()->getUp());
	pCur = getHead();
	pCur->setNext(temp_B);
	pCur = pCur->getNext();
	pCur->clockwise();//헤드윗면 값이 시계방향회전
	pCur->setNext(temp_E);
	pCur = pCur->getNext();
	pCur->setNext(temp_D);
	pCur = pCur->getNext();
	pCur->clockwise_c();//헤드 아랫면 값이 시계방향회전
	pCur->setNext(getHead());
}
void Face_list::key_down(){
	Face *pCur = getHead();
	Face *temp_B = pCur->getNext();
	Face *temp_F = pCur->getUp()->getUp()->getUp();
	Face *temp_D = pCur->getNext()->getNext()->getNext();

	pCur = getHead();
	pCur = pCur->getUp()->getUp();///////////////////////////////뒷면이 시계반대방향으로 두번 돌아야댐
	pCur->clockwise_c();
	pCur->clockwise_c();
	pCur = pCur->getUp();
	pCur->clockwise_c();
	pCur->clockwise_c();//////////밑면도 마찬가지
	pCur = getHead();

	pCur->setNext(NULL);
	setHead(getHead()->getUp());
	pCur = getHead();
	pCur->setNext(temp_B);
	pCur = pCur->getNext();
	pCur->clockwise_c();//헤드윗면 값이 시계방향회전
	pCur->setNext(temp_F);
	pCur = pCur->getNext();
	pCur->setNext(temp_D);
	pCur = pCur->getNext();
	pCur->clockwise();//헤드 아랫면 값이 시계방향회전
	pCur->setNext(getHead());
}
//Rotation 1,2,3, 7,8,9 는 전면의 한 슬라이드를 돌릴시에 반댓면의 반대편 슬라이드가 돌아가므로 주의한다!!
void Face_list::Rotation_1(){
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(1, 1);
	prevalue[1] = pCur->getNum(2, 1);
	prevalue[2] = pCur->getNum(3, 1);
	pCur = pCur->getUp();
	for (int i = 0; i < 4; i++){
		
		if (i == 1){//정면의 반대면은 정면1열을 위로 회전시 반대면3열이 돌아가므로
			char swap_t[2] = { NULL };//그 다음에서 쓰일 때 1열 3,2,1행이 1,2,3행으로 들어가야하므로
			swap_t[0] = prevalue[2];//swap_t의 크기를 2로 잡아줘야 Run time 오류가 나지않는다*************
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 3);//현재값을 저장하고
				pCur->setNum(j, 3, prevalue[j - 1]);//이전값을 3행부터 1행까지 3열로 넣는다!!!!!
				prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
			}
			swap_t[1] = { 0 };//그 다음에서 쓰일 때 1열 3,2,1행이 1,2,3행으로 들어가야하므로
			swap_t[0] = prevalue[2];
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
		}
		else{
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 1);//현재값을 저장하고
				pCur->setNum(j, 1, prevalue[j - 1]);//이전값을 새로 덧씌우고
				prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
			}
		}
		pCur = pCur->getUp();//다음 페이스로 넘어감
	}
	pCur = getHead()->getNext()->getNext()->getNext();//윗쪽 face로 한 칸 이동
	pCur->clockwise_c();//시계방향으로 값이 바뀐다.
}
void Face_list::Rotation_2(){//중간회전은 면 자체의 값이 바뀌는 경우가 없다
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(1, 2);
	prevalue[1] = pCur->getNum(2, 2);
	prevalue[2] = pCur->getNum(3, 2);
	pCur = pCur->getUp();
	for (int i = 0; i < 4; i++){
		if (i == 1){//정면의 반대면은 정면1열을 위로 회전시 반대면3열이 돌아가므로
			char swap_t[2] = { NULL };//그 다음에서 쓰일 때 1열 3,2,1행이 1,2,3행으로 들어가야하므로
			swap_t[0] = prevalue[2];//swap_t의 크기를 2로 잡아줘야 Run time 오류가 나지않는다*************
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 2);//현재값을 저장하고
				pCur->setNum(j, 2, prevalue[j - 1]);//이전값을 3행부터 1행까지 3열로 넣는다!!!!!
				prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
			}
			swap_t[1] = { 0 };//그 다음에서 쓰일 때 1열 3,2,1행이 1,2,3행으로 들어가야하므로
			swap_t[0] = prevalue[2];
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
		}
		else{
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 2);//현재값을 저장하고
				pCur->setNum(j, 2, prevalue[j - 1]);//이전값을 새로 덧씌우고
				prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
			}
		}
		pCur = pCur->getUp();//다음 페이스로 넘어감
	}
}
void Face_list::Rotation_3(){//중간회전은 면 자체의 값이 바뀌는 경우가 없다
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(1, 3);
	prevalue[1] = pCur->getNum(2, 3);
	prevalue[2] = pCur->getNum(3, 3);
	pCur = pCur->getUp();
	for (int i = 0; i < 4; i++){
		if (i == 1){//정면의 반대면은 정면3열을 위로 회전시 반대면1열이 돌아가므로
			char swap_t[2] = { NULL };//그 다음에서 쓰일 때 1열 3,2,1행이 1,2,3행으로 들어가야하므로
			swap_t[0] = prevalue[2];//swap_t의 크기를 2로 잡아줘야 Run time 오류가 나지않는다*************
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 1);//현재값을 저장하고
				pCur->setNum(j, 1, prevalue[j - 1]);
				prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
			}
			swap_t[1] = { 0 };//그 다음에서 쓰일 때 1열 3,2,1행이 1,2,3행으로 들어가야하므로
			swap_t[0] = prevalue[2];
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
		}
		else{
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 3);//현재값을 저장하고
				pCur->setNum(j, 3, prevalue[j - 1]);//이전값을 새로 덧씌우고
				prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
			}
		}
		pCur = pCur->getUp();//다음 페이스로 넘어감
	}
	pCur = getHead()->getNext();//윗쪽 face로 한 칸 이동
	pCur->clockwise();//시계방향으로 값이 바뀐다.
}
void Face_list::Rotation_4(){
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(1, 1);
	prevalue[1] = pCur->getNum(1, 2);
	prevalue[2] = pCur->getNum(1, 3);
	pCur = pCur->getNext();
	for (int i = 0; i < 4; i++){
		for (int j = 1; j < 4; j++){
			curvalue[j - 1] = pCur->getNum(1, j);//현재값을 저장하고
			pCur->setNum(1, j, prevalue[j - 1]);//이전값을 새로 덧씌우고
			prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
		}
		pCur = pCur->getNext();//다음 페이스로 넘어감
	}
	pCur = getHead()->getUp();//윗쪽 face로 한 칸 이동
	pCur->clockwise_c();//반시계방향으로 값이 바뀐다.
}
void Face_list::Rotation_5(){//중간회전은 면 자체의 값이 바뀌는 경우가 없다
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(2, 1);
	prevalue[1] = pCur->getNum(2, 2);
	prevalue[2] = pCur->getNum(2, 3);
	pCur = pCur->getNext();
	for (int i = 0; i < 4; i++){
		for (int j = 1; j < 4; j++){
			curvalue[j - 1] = pCur->getNum(2, j);//현재값을 저장하고
			pCur->setNum(2, j, prevalue[j - 1]);//이전값을 새로 덧씌우고
			prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
		}
		pCur = pCur->getNext();//다음 페이스로 넘어감
	}
}
void Face_list::Rotation_6(){
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(3, 1);
	prevalue[1] = pCur->getNum(3, 2);
	prevalue[2] = pCur->getNum(3, 3);
	pCur = pCur->getNext();
	for (int i = 0; i < 4; i++){
		for (int j = 1; j < 4; j++){
			curvalue[j - 1] = pCur->getNum(3, j);//현재값을 저장하고
			pCur->setNum(3, j, prevalue[j - 1]);//이전값을 새로 덧씌우고
			prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
		}
		pCur = pCur->getNext();//다음 페이스로 넘어감
	}
	pCur = getHead()->getUp()->getUp()->getUp();//윗쪽 face로 세 칸 이동
	pCur->clockwise();//시계방향으로 값이 바뀐다.
}
void Face_list::Rotation_7(){//중간회전은 면 자체의 값이 바뀌는 경우가 없다
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(1, 1);
	prevalue[1] = pCur->getNum(2, 1);
	prevalue[2] = pCur->getNum(3, 1);
	pCur = pCur->getUp()->getUp()->getUp();
	for (int i = 0; i < 4; i++){

		if (i == 1){//정면의 반대면은 정면1열을 위로 회전시 반대면3열이 돌아가므로
			char swap_t[2] = { NULL };//그 다음에서 쓰일 때 1열 3,2,1행이 1,2,3행으로 들어가야하므로
			swap_t[0] = prevalue[2];//swap_t의 크기를 2로 잡아줘야 Run time 오류가 나지않는다*************
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 3);//현재값을 저장하고
				pCur->setNum(j, 3, prevalue[j - 1]);//이전값을 3행부터 1행까지 3열로 넣는다!!!!!
				prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
			}
			swap_t[1] = { 0 };//그 다음에서 쓰일 때 1열 3,2,1행이 1,2,3행으로 들어가야하므로
			swap_t[0] = prevalue[2];
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
		}
		else{
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 1);//현재값을 저장하고
				pCur->setNum(j, 1, prevalue[j - 1]);//이전값을 새로 덧씌우고
				prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
			}
		}
		pCur = pCur->getUp()->getUp()->getUp();//다음 페이스로 넘어감
	}
	pCur = getHead()->getNext()->getNext()->getNext();//윗쪽 face로 한 칸 이동
	pCur->clockwise();
}
void Face_list::Rotation_8(){//중간회전은 면 자체의 값이 바뀌는 경우가 없다
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(1, 2);
	prevalue[1] = pCur->getNum(2, 2);
	prevalue[2] = pCur->getNum(3, 2);
	pCur = pCur->getUp()->getUp()->getUp();
	for (int i = 0; i < 4; i++){

		if (i == 1){//정면의 반대면은 정면1열을 위로 회전시 반대면3열이 돌아가므로
			char swap_t[2] = { NULL };//그 다음에서 쓰일 때 1열 3,2,1행이 1,2,3행으로 들어가야하므로
			swap_t[0] = prevalue[2];//swap_t의 크기를 2로 잡아줘야 Run time 오류가 나지않는다*************
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 2);//현재값을 저장하고
				pCur->setNum(j, 2, prevalue[j - 1]);//이전값을 3행부터 1행까지 3열로 넣는다!!!!!
				prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
			}
			swap_t[1] = { 0 };//그 다음에서 쓰일 때 1열 3,2,1행이 1,2,3행으로 들어가야하므로
			swap_t[0] = prevalue[2];
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
		}
		else{
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 2);//현재값을 저장하고
				pCur->setNum(j, 2, prevalue[j - 1]);//이전값을 새로 덧씌우고
				prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
			}
		}
		pCur = pCur->getUp()->getUp()->getUp();//다음 페이스로 넘어감
	}
}
void Face_list::Rotation_9(){//중간회전은 면 자체의 값이 바뀌는 경우가 없다
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(1, 3);
	prevalue[1] = pCur->getNum(2, 3);
	prevalue[2] = pCur->getNum(3, 3);
	pCur = pCur->getUp()->getUp()->getUp();
	for (int i = 0; i < 4; i++){

		if (i == 1){//정면의 반대면은 정면1열을 위로 회전시 반대면3열이 돌아가므로
			char swap_t[2] = { NULL };//그 다음에서 쓰일 때 1열 3,2,1행이 1,2,3행으로 들어가야하므로
			swap_t[0] = prevalue[2];//swap_t의 크기를 2로 잡아줘야 Run time 오류가 나지않는다*************
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 1);//현재값을 저장하고
				pCur->setNum(j, 1, prevalue[j - 1]);//이전값을 3행부터 1행까지 3열로 넣는다!!!!!
				prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
			}
			swap_t[1] = { 0 };//그 다음에서 쓰일 때 1열 3,2,1행이 1,2,3행으로 들어가야하므로
			swap_t[0] = prevalue[2];
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
		}
		else{
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 3);//현재값을 저장하고
				pCur->setNum(j, 3, prevalue[j - 1]);//이전값을 새로 덧씌우고
				prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
			}
		}
		pCur = pCur->getUp()->getUp()->getUp();//다음 페이스로 넘어감
	}
	pCur = getHead()->getNext();//윗쪽 face로 한 칸 이동
	pCur->clockwise_c();
}
void Face_list::Rotation_10(){
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(3, 1);
	prevalue[1] = pCur->getNum(3, 2);
	prevalue[2] = pCur->getNum(3, 3);
	pCur = pCur->getNext()->getNext()->getNext();
	for (int i = 0; i < 4; i++){
		for (int j = 1; j < 4; j++){
			curvalue[j - 1] = pCur->getNum(3, j);//현재값을 저장하고
			pCur->setNum(3, j, prevalue[j - 1]);//이전값을 새로 덧씌우고
			prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
		}
		pCur = pCur->getNext()->getNext()->getNext();//다음 페이스로 넘어감
	}
	pCur = getHead()->getUp()->getUp()->getUp();//윗쪽 face로 세칸 이동
	pCur->clockwise_c();
}
void Face_list::Rotation_11(){
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(2, 1);
	prevalue[1] = pCur->getNum(2, 2);
	prevalue[2] = pCur->getNum(2, 3);
	pCur = pCur->getNext()->getNext()->getNext();
	for (int i = 0; i < 4; i++){
		for (int j = 1; j < 4; j++){
			curvalue[j - 1] = pCur->getNum(2, j);//현재값을 저장하고
			pCur->setNum(2, j, prevalue[j - 1]);//이전값을 새로 덧씌우고
			prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
		}
		pCur = pCur->getNext()->getNext()->getNext();//다음 페이스로 넘어감
	}
}
void Face_list::Rotation_12(){
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(1, 1);
	prevalue[1] = pCur->getNum(1, 2);
	prevalue[2] = pCur->getNum(1, 3);
	pCur = pCur->getNext()->getNext()->getNext();
	for (int i = 0; i < 4; i++){
		for (int j = 1; j < 4; j++){
			curvalue[j - 1] = pCur->getNum(1, j);//현재값을 저장하고
			pCur->setNum(1, j, prevalue[j - 1]);//이전값을 새로 덧씌우고
			prevalue[j - 1] = curvalue[j - 1];//현재값이 다음 노드에 쓰일 이전값이된다
		}
		pCur = pCur->getNext()->getNext()->getNext();//다음 페이스로 넘어감
	}
	pCur = getHead()->getUp();//윗쪽 face로 한 칸 이동
	pCur->clockwise();//시계방향으로 값이 바뀐다.
}

#include "stdafx.h"
#include "Face_list.h"


Face_list::Face_list()//�����ڿ��� �ٷ� ť�����
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
	for (int i = 0; i < 3; i++){//���� 3������
		Face *deletespace = temp1;
		temp1 = temp1->getNext();
		delete deletespace;
	}
	delete temp1;//���� ������ ����
	delete temp2;//���� ����
	delete temp3;//�Ʒ��� ����
	


}
////keydown�� key up�� ���������� ���� Ȥ�� �Ʒ���� ������ �ݴ���� �ݽð���� 180���� ȸ���ؾ� �ùٸ� ���ڰ��� ����////
///ť�� �������� ������Ʈ ���赵 ����///
void Face_list::key_left(){//�������� ȸ��, ���鿡�� �ٶ� �����ʸ��� ������ �ȴ�.
	Face *pCur = getHead();
	Face *temp_up = pCur->getUp();
	Face *temp_down = pCur->getUp()->getUp()->getUp();
	Face *temp_right = pCur->getNext()->getNext()->getNext();

	pCur->getNext()->getNext()->setUp(NULL);//C���� F�� ���� ���� ����
	setHead(getHead()->getNext());
	pCur = getHead();
	pCur->setUp(temp_up);
	pCur = pCur->getUp();
	pCur->clockwise();//������� ���� �ݽð����ȸ��
	pCur->setUp(temp_right);
	pCur = pCur->getUp();
	pCur->setUp(temp_down);
	pCur = pCur->getUp();
	pCur->clockwise_c();//��� �Ʒ��� ���� �ð����ȸ��
	pCur->setUp(getHead());
}
void Face_list::key_right(){
	Face *pCur = getHead();
	Face *temp_up = pCur->getUp();
	Face *temp_down = pCur->getUp()->getUp()->getUp();
	Face *temp_right = pCur->getNext();

	pCur->getNext()->getNext()->setUp(NULL);//C���� F�� ���� ���� ����
	setHead(getHead()->getNext()->getNext()->getNext());
	pCur = getHead();
	pCur->setUp(temp_up);
	pCur = pCur->getUp();
	pCur->clockwise_c();//������� ���� �ð����ȸ��
	pCur->setUp(temp_right);
	pCur = pCur->getUp();
	pCur->setUp(temp_down);
	pCur = pCur->getUp();
	pCur->clockwise();//��� �Ʒ��� ���� �ð����ȸ��
	pCur->setUp(getHead());
}
void Face_list::key_up(){
	Face *pCur = getHead();
	Face *temp_B = pCur->getNext();
	Face *temp_E = pCur->getUp();
	Face *temp_D = pCur->getNext()->getNext()->getNext();

	pCur = getHead();
	pCur = pCur->getUp();//����� ������ �ݽð�������� 180�� ����
	pCur->clockwise_c();
	pCur->clockwise_c();
	pCur = pCur->getUp();//����� �ݴ�鵵 �ݽð�������� 180�� ����
	pCur->clockwise_c();
	pCur->clockwise_c();
	pCur = getHead();

	pCur->setNext(NULL);
	setHead(getHead()->getUp()->getUp()->getUp());
	pCur = getHead();
	pCur->setNext(temp_B);
	pCur = pCur->getNext();
	pCur->clockwise();//������� ���� �ð����ȸ��
	pCur->setNext(temp_E);
	pCur = pCur->getNext();
	pCur->setNext(temp_D);
	pCur = pCur->getNext();
	pCur->clockwise_c();//��� �Ʒ��� ���� �ð����ȸ��
	pCur->setNext(getHead());
}
void Face_list::key_down(){
	Face *pCur = getHead();
	Face *temp_B = pCur->getNext();
	Face *temp_F = pCur->getUp()->getUp()->getUp();
	Face *temp_D = pCur->getNext()->getNext()->getNext();

	pCur = getHead();
	pCur = pCur->getUp()->getUp();///////////////////////////////�޸��� �ð�ݴ�������� �ι� ���ƾߴ�
	pCur->clockwise_c();
	pCur->clockwise_c();
	pCur = pCur->getUp();
	pCur->clockwise_c();
	pCur->clockwise_c();//////////�ظ鵵 ��������
	pCur = getHead();

	pCur->setNext(NULL);
	setHead(getHead()->getUp());
	pCur = getHead();
	pCur->setNext(temp_B);
	pCur = pCur->getNext();
	pCur->clockwise_c();//������� ���� �ð����ȸ��
	pCur->setNext(temp_F);
	pCur = pCur->getNext();
	pCur->setNext(temp_D);
	pCur = pCur->getNext();
	pCur->clockwise();//��� �Ʒ��� ���� �ð����ȸ��
	pCur->setNext(getHead());
}
//Rotation 1,2,3, 7,8,9 �� ������ �� �����̵带 �����ÿ� �ݴ���� �ݴ��� �����̵尡 ���ư��Ƿ� �����Ѵ�!!
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
		
		if (i == 1){//������ �ݴ���� ����1���� ���� ȸ���� �ݴ��3���� ���ư��Ƿ�
			char swap_t[2] = { NULL };//�� �������� ���� �� 1�� 3,2,1���� 1,2,3������ �����ϹǷ�
			swap_t[0] = prevalue[2];//swap_t�� ũ�⸦ 2�� ������ Run time ������ �����ʴ´�*************
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 3);//���簪�� �����ϰ�
				pCur->setNum(j, 3, prevalue[j - 1]);//�������� 3����� 1����� 3���� �ִ´�!!!!!
				prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
			}
			swap_t[1] = { 0 };//�� �������� ���� �� 1�� 3,2,1���� 1,2,3������ �����ϹǷ�
			swap_t[0] = prevalue[2];
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
		}
		else{
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 1);//���簪�� �����ϰ�
				pCur->setNum(j, 1, prevalue[j - 1]);//�������� ���� �������
				prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
			}
		}
		pCur = pCur->getUp();//���� ���̽��� �Ѿ
	}
	pCur = getHead()->getNext()->getNext()->getNext();//���� face�� �� ĭ �̵�
	pCur->clockwise_c();//�ð�������� ���� �ٲ��.
}
void Face_list::Rotation_2(){//�߰�ȸ���� �� ��ü�� ���� �ٲ�� ��찡 ����
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(1, 2);
	prevalue[1] = pCur->getNum(2, 2);
	prevalue[2] = pCur->getNum(3, 2);
	pCur = pCur->getUp();
	for (int i = 0; i < 4; i++){
		if (i == 1){//������ �ݴ���� ����1���� ���� ȸ���� �ݴ��3���� ���ư��Ƿ�
			char swap_t[2] = { NULL };//�� �������� ���� �� 1�� 3,2,1���� 1,2,3������ �����ϹǷ�
			swap_t[0] = prevalue[2];//swap_t�� ũ�⸦ 2�� ������ Run time ������ �����ʴ´�*************
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 2);//���簪�� �����ϰ�
				pCur->setNum(j, 2, prevalue[j - 1]);//�������� 3����� 1����� 3���� �ִ´�!!!!!
				prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
			}
			swap_t[1] = { 0 };//�� �������� ���� �� 1�� 3,2,1���� 1,2,3������ �����ϹǷ�
			swap_t[0] = prevalue[2];
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
		}
		else{
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 2);//���簪�� �����ϰ�
				pCur->setNum(j, 2, prevalue[j - 1]);//�������� ���� �������
				prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
			}
		}
		pCur = pCur->getUp();//���� ���̽��� �Ѿ
	}
}
void Face_list::Rotation_3(){//�߰�ȸ���� �� ��ü�� ���� �ٲ�� ��찡 ����
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(1, 3);
	prevalue[1] = pCur->getNum(2, 3);
	prevalue[2] = pCur->getNum(3, 3);
	pCur = pCur->getUp();
	for (int i = 0; i < 4; i++){
		if (i == 1){//������ �ݴ���� ����3���� ���� ȸ���� �ݴ��1���� ���ư��Ƿ�
			char swap_t[2] = { NULL };//�� �������� ���� �� 1�� 3,2,1���� 1,2,3������ �����ϹǷ�
			swap_t[0] = prevalue[2];//swap_t�� ũ�⸦ 2�� ������ Run time ������ �����ʴ´�*************
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 1);//���簪�� �����ϰ�
				pCur->setNum(j, 1, prevalue[j - 1]);
				prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
			}
			swap_t[1] = { 0 };//�� �������� ���� �� 1�� 3,2,1���� 1,2,3������ �����ϹǷ�
			swap_t[0] = prevalue[2];
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
		}
		else{
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 3);//���簪�� �����ϰ�
				pCur->setNum(j, 3, prevalue[j - 1]);//�������� ���� �������
				prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
			}
		}
		pCur = pCur->getUp();//���� ���̽��� �Ѿ
	}
	pCur = getHead()->getNext();//���� face�� �� ĭ �̵�
	pCur->clockwise();//�ð�������� ���� �ٲ��.
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
			curvalue[j - 1] = pCur->getNum(1, j);//���簪�� �����ϰ�
			pCur->setNum(1, j, prevalue[j - 1]);//�������� ���� �������
			prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
		}
		pCur = pCur->getNext();//���� ���̽��� �Ѿ
	}
	pCur = getHead()->getUp();//���� face�� �� ĭ �̵�
	pCur->clockwise_c();//�ݽð�������� ���� �ٲ��.
}
void Face_list::Rotation_5(){//�߰�ȸ���� �� ��ü�� ���� �ٲ�� ��찡 ����
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
			curvalue[j - 1] = pCur->getNum(2, j);//���簪�� �����ϰ�
			pCur->setNum(2, j, prevalue[j - 1]);//�������� ���� �������
			prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
		}
		pCur = pCur->getNext();//���� ���̽��� �Ѿ
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
			curvalue[j - 1] = pCur->getNum(3, j);//���簪�� �����ϰ�
			pCur->setNum(3, j, prevalue[j - 1]);//�������� ���� �������
			prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
		}
		pCur = pCur->getNext();//���� ���̽��� �Ѿ
	}
	pCur = getHead()->getUp()->getUp()->getUp();//���� face�� �� ĭ �̵�
	pCur->clockwise();//�ð�������� ���� �ٲ��.
}
void Face_list::Rotation_7(){//�߰�ȸ���� �� ��ü�� ���� �ٲ�� ��찡 ����
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(1, 1);
	prevalue[1] = pCur->getNum(2, 1);
	prevalue[2] = pCur->getNum(3, 1);
	pCur = pCur->getUp()->getUp()->getUp();
	for (int i = 0; i < 4; i++){

		if (i == 1){//������ �ݴ���� ����1���� ���� ȸ���� �ݴ��3���� ���ư��Ƿ�
			char swap_t[2] = { NULL };//�� �������� ���� �� 1�� 3,2,1���� 1,2,3������ �����ϹǷ�
			swap_t[0] = prevalue[2];//swap_t�� ũ�⸦ 2�� ������ Run time ������ �����ʴ´�*************
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 3);//���簪�� �����ϰ�
				pCur->setNum(j, 3, prevalue[j - 1]);//�������� 3����� 1����� 3���� �ִ´�!!!!!
				prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
			}
			swap_t[1] = { 0 };//�� �������� ���� �� 1�� 3,2,1���� 1,2,3������ �����ϹǷ�
			swap_t[0] = prevalue[2];
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
		}
		else{
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 1);//���簪�� �����ϰ�
				pCur->setNum(j, 1, prevalue[j - 1]);//�������� ���� �������
				prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
			}
		}
		pCur = pCur->getUp()->getUp()->getUp();//���� ���̽��� �Ѿ
	}
	pCur = getHead()->getNext()->getNext()->getNext();//���� face�� �� ĭ �̵�
	pCur->clockwise();
}
void Face_list::Rotation_8(){//�߰�ȸ���� �� ��ü�� ���� �ٲ�� ��찡 ����
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(1, 2);
	prevalue[1] = pCur->getNum(2, 2);
	prevalue[2] = pCur->getNum(3, 2);
	pCur = pCur->getUp()->getUp()->getUp();
	for (int i = 0; i < 4; i++){

		if (i == 1){//������ �ݴ���� ����1���� ���� ȸ���� �ݴ��3���� ���ư��Ƿ�
			char swap_t[2] = { NULL };//�� �������� ���� �� 1�� 3,2,1���� 1,2,3������ �����ϹǷ�
			swap_t[0] = prevalue[2];//swap_t�� ũ�⸦ 2�� ������ Run time ������ �����ʴ´�*************
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 2);//���簪�� �����ϰ�
				pCur->setNum(j, 2, prevalue[j - 1]);//�������� 3����� 1����� 3���� �ִ´�!!!!!
				prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
			}
			swap_t[1] = { 0 };//�� �������� ���� �� 1�� 3,2,1���� 1,2,3������ �����ϹǷ�
			swap_t[0] = prevalue[2];
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
		}
		else{
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 2);//���簪�� �����ϰ�
				pCur->setNum(j, 2, prevalue[j - 1]);//�������� ���� �������
				prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
			}
		}
		pCur = pCur->getUp()->getUp()->getUp();//���� ���̽��� �Ѿ
	}
}
void Face_list::Rotation_9(){//�߰�ȸ���� �� ��ü�� ���� �ٲ�� ��찡 ����
	Face *pCur = getHead();
	Face *Return_state = pCur;
	int prevalue[3];
	int curvalue[3];
	prevalue[0] = pCur->getNum(1, 3);
	prevalue[1] = pCur->getNum(2, 3);
	prevalue[2] = pCur->getNum(3, 3);
	pCur = pCur->getUp()->getUp()->getUp();
	for (int i = 0; i < 4; i++){

		if (i == 1){//������ �ݴ���� ����1���� ���� ȸ���� �ݴ��3���� ���ư��Ƿ�
			char swap_t[2] = { NULL };//�� �������� ���� �� 1�� 3,2,1���� 1,2,3������ �����ϹǷ�
			swap_t[0] = prevalue[2];//swap_t�� ũ�⸦ 2�� ������ Run time ������ �����ʴ´�*************
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 1);//���簪�� �����ϰ�
				pCur->setNum(j, 1, prevalue[j - 1]);//�������� 3����� 1����� 3���� �ִ´�!!!!!
				prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
			}
			swap_t[1] = { 0 };//�� �������� ���� �� 1�� 3,2,1���� 1,2,3������ �����ϹǷ�
			swap_t[0] = prevalue[2];
			prevalue[2] = prevalue[0];
			prevalue[0] = swap_t[0];
		}
		else{
			for (int j = 1; j < 4; j++){
				curvalue[j - 1] = pCur->getNum(j, 3);//���簪�� �����ϰ�
				pCur->setNum(j, 3, prevalue[j - 1]);//�������� ���� �������
				prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
			}
		}
		pCur = pCur->getUp()->getUp()->getUp();//���� ���̽��� �Ѿ
	}
	pCur = getHead()->getNext();//���� face�� �� ĭ �̵�
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
			curvalue[j - 1] = pCur->getNum(3, j);//���簪�� �����ϰ�
			pCur->setNum(3, j, prevalue[j - 1]);//�������� ���� �������
			prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
		}
		pCur = pCur->getNext()->getNext()->getNext();//���� ���̽��� �Ѿ
	}
	pCur = getHead()->getUp()->getUp()->getUp();//���� face�� ��ĭ �̵�
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
			curvalue[j - 1] = pCur->getNum(2, j);//���簪�� �����ϰ�
			pCur->setNum(2, j, prevalue[j - 1]);//�������� ���� �������
			prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
		}
		pCur = pCur->getNext()->getNext()->getNext();//���� ���̽��� �Ѿ
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
			curvalue[j - 1] = pCur->getNum(1, j);//���簪�� �����ϰ�
			pCur->setNum(1, j, prevalue[j - 1]);//�������� ���� �������
			prevalue[j - 1] = curvalue[j - 1];//���簪�� ���� ��忡 ���� �������̵ȴ�
		}
		pCur = pCur->getNext()->getNext()->getNext();//���� ���̽��� �Ѿ
	}
	pCur = getHead()->getUp();//���� face�� �� ĭ �̵�
	pCur->clockwise();//�ð�������� ���� �ٲ��.
}

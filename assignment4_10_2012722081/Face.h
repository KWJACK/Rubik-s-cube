#pragma once
#include <iostream>
//ť�� ����� ����, ���鿡 ���� ���迡 ���� ������ ������ ���
class Face
{
private:
	char m_face_name;
	int m_unique_values[3][3];
	Face* p_Next;
	Face* p_Up;

public:
	Face();
	~Face();
	void setNum_Face(int a);

	void setNext(Face* next);
	void setUp(Face* up);
	void setNum(int god, int duf, int value);//getNum�� ����, �ش� ��� ��ġ�� ���� �������
	Face* getNext();
	Face* getUp();
	char getface();
	int getNum(int god, int duf);//(1,1)�Է½� 3X3����� (1,1)�� ������ ����
	
	void clockwise_c();//3X3����� ���� �ݽð�� ȸ��
	void clockwise();//3X3����� ���� �ð�������� ȸ��
};


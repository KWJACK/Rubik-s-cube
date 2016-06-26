#pragma once
#include <iostream>
//큐브 각면과 숫자, 각면에 대한 관계에 대한 정보를 정의한 헤더
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
	void setNum(int god, int duf, int value);//getNum과 동일, 해당 행렬 위치에 값을 집어넣음
	Face* getNext();
	Face* getUp();
	char getface();
	int getNum(int god, int duf);//(1,1)입력시 3X3행렬의 (1,1)을 얻을수 잇음
	
	void clockwise_c();//3X3행렬의 값을 반시계로 회전
	void clockwise();//3X3행렬의 값을 시계방향으로 회전
};


#include "stdafx.h"
#include "Face.h"


Face::Face()
{
}


Face::~Face()
{
}
int Face::getNum(int god, int duf){ return m_unique_values[god - 1][duf - 1]; }//god행,duf열
void Face::setNum(int god, int duf, int value){ m_unique_values[god - 1][duf - 1] = value; }
void Face::setNum_Face(int a){//a=0~5까지 6개의 면, 97='a'
	for (int i = 0; i < 3; i++){
		for (int j = 1; j < 4; j++){
			m_unique_values[i][j - 1] = a * 9 + j + 3 * i;
		}
	}
	m_face_name = (char)(a + 65);
}

Face* Face::getNext(){ return p_Next; }
Face* Face::getUp(){ return p_Up; }
void Face::setNext(Face* next){ p_Next = next; }
void Face::setUp(Face* up){ p_Up = up; }
char Face::getface(){ return m_face_name; }
void Face::clockwise_c(){//_c= counter반시계방향으로 3X3행열의 값을 바꾸는함수
	int reverse[3][3];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			reverse[i][j] = m_unique_values[j][i];//기존의 행렬을 대각선 기준으로 반전한 다음
		}
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
			m_unique_values[i][j] = reverse[i][j];//반전된 reverse행렬을 다시 기존행렬에 덮어 씌우고
	}
	for (int i = 0; i < 3; i++){
		m_unique_values[0][i] = reverse[2][i];//맨 상단 행과 맨 하단 행을 바꾸면 반시계방향이됨
		m_unique_values[2][i] = reverse[0][i];
	}
}
void Face::clockwise(){//시계방향으로 3X3행열의 값을 바꾸는함수, clokwise와 비슷하나 마지막에서 제일 좌측열과 우측열을 바꾸는게다름
	int reverse[3][3];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			reverse[i][j] = m_unique_values[j][i];
		}
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
			m_unique_values[i][j] = reverse[i][j];
	}
	for (int i = 0; i < 3; i++){
		m_unique_values[i][0] = reverse[i][2];
		m_unique_values[i][2] = reverse[i][0];
	}
}
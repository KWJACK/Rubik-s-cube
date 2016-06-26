#include "stdafx.h"
#include "Face.h"


Face::Face()
{
}


Face::~Face()
{
}
int Face::getNum(int god, int duf){ return m_unique_values[god - 1][duf - 1]; }//god��,duf��
void Face::setNum(int god, int duf, int value){ m_unique_values[god - 1][duf - 1] = value; }
void Face::setNum_Face(int a){//a=0~5���� 6���� ��, 97='a'
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
void Face::clockwise_c(){//_c= counter�ݽð�������� 3X3�࿭�� ���� �ٲٴ��Լ�
	int reverse[3][3];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			reverse[i][j] = m_unique_values[j][i];//������ ����� �밢�� �������� ������ ����
		}
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
			m_unique_values[i][j] = reverse[i][j];//������ reverse����� �ٽ� ������Ŀ� ���� �����
	}
	for (int i = 0; i < 3; i++){
		m_unique_values[0][i] = reverse[2][i];//�� ��� ��� �� �ϴ� ���� �ٲٸ� �ݽð�����̵�
		m_unique_values[2][i] = reverse[0][i];
	}
}
void Face::clockwise(){//�ð�������� 3X3�࿭�� ���� �ٲٴ��Լ�, clokwise�� ����ϳ� ���������� ���� �������� �������� �ٲٴ°Դٸ�
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
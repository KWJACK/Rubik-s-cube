#pragma once//face_list.h�� Doc.h�� ��Ŭ���
#include "Face.h"
class Face_list
{
private:
	Face* Face_Header;

public:
	Face_list();
	~Face_list();

	void setHead(Face* head){ Face_Header = head; }
	Face* getHead(){ return Face_Header; }
	void key_down();
	void key_up();
	void key_right();
	void key_left();
	// �����̼� ������ ����3�� ������ ����
	void Rotation_1();
	void Rotation_2();
	void Rotation_3();
	void Rotation_4();
	void Rotation_5();
	void Rotation_6();
	void Rotation_7();
	void Rotation_8();
	void Rotation_9();
	void Rotation_10();
	void Rotation_11();
	void Rotation_12();
};

#pragma once
#include <iostream>
using namespace std;
//���콺 �Է� �̺�Ʈ�� ���� �α� ����� �����ϰ� ���� loglist�� element�� ������ ���
class mouse_Log
{
private:
	string m_mouselog;
	mouse_Log *m_next;
public:
	mouse_Log();
	~mouse_Log();
	void set_mouselog(string log){ m_mouselog = log; }
	void setNext(mouse_Log* newlog){ m_next = newlog; }
	string get_mouselog(){ return m_mouselog; }
	mouse_Log* getNext(){ return m_next; }
};
	
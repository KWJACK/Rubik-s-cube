#pragma once
#include <iostream>
using namespace std;
//Ű���� �Է� �̺�Ʈ�� ���� �α� ����� �����ϰ� ���� loglist�� element�� ������ ���
class key_Log
{
private:
	string m_keylog;
	key_Log *m_next;
public:
	key_Log();
	~key_Log();
	void set_keylog(string log){ m_keylog = log; }
	void setNext(key_Log* newlog){ m_next = newlog; }
	string get_keylog(){ return m_keylog; }
	key_Log* getNext(){ return m_next; }
};


#pragma once
#include <iostream>
using namespace std;
//키보드 입력 이벤트에 따른 로그 기록을 저장하고 쓰는 loglist의 element를 정의한 헤더
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


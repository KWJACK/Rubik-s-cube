#pragma once
#include <iostream>
using namespace std;
//마우스 입력 이벤트에 따른 로그 기록을 저장하고 쓰는 loglist의 element를 정의한 헤더
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
	
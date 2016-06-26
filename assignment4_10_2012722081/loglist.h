#pragma once//log_list.h는 Doc.h에 인클루드
#include "key_Log.h"
#include "mouse_Log.h"
class loglist
{
private:
	key_Log* m_headKeylog;
	mouse_Log* m_headMouselog;
public:
	loglist();
	~loglist();
	void insert_keylog(key_Log* newlog);
	void insert_mouselog(mouse_Log* newlog);
	void writelogfile_k();//출력면log기록
	void writelogfile_m();//슬라이스log기록
};


#pragma once//log_list.h�� Doc.h�� ��Ŭ���
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
	void writelogfile_k();//��¸�log���
	void writelogfile_m();//�����̽�log���
};


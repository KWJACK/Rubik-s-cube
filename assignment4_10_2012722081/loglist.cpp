#include "stdafx.h"
#include "loglist.h"
#include <fstream>

loglist::loglist()
{
	m_headKeylog = NULL;
	m_headMouselog = NULL;
}


loglist::~loglist()
{
	if (m_headKeylog){//입력이 안된상태로 종료될수 있으므로 지울게 있는지 확인!
		key_Log *pCur_key = m_headKeylog;
		while (pCur_key->getNext()){
			key_Log *temp = pCur_key;
			pCur_key = pCur_key->getNext();
			delete temp;
		}
		delete pCur_key;//맨 마지막 키까지 할당영역해제
	}
	if (m_headMouselog){//입력이 안된상태로 종료될수 있으므로 지울게 있는지 확인!
		mouse_Log *pCur_mou = m_headMouselog;
		while (pCur_mou->getNext()){
			mouse_Log *temp2 = pCur_mou;
			pCur_mou = pCur_mou->getNext();
			delete temp2;
		}
		delete pCur_mou;
	}
}
void loglist::insert_keylog(key_Log* newlog){//키로그 노드 삽입, 더미 사용X
	if (!m_headKeylog)
		m_headKeylog = newlog;
	else{
		key_Log* pCur = m_headKeylog;
		while (pCur->getNext() != NULL)
			pCur = pCur->getNext();
		pCur->setNext(newlog);
	}
}
void loglist::insert_mouselog(mouse_Log* newlog){//마우스 로그 노드 삽입
	if (!m_headMouselog)
		m_headMouselog = newlog;
	else{
		mouse_Log* pCur = m_headMouselog;
		while (pCur->getNext() != NULL)
			pCur = pCur->getNext();
		pCur->setNext(newlog);
	}
}
void loglist::writelogfile_k(){
	FILE *fp;	
	fopen_s(&fp, "keyboard_log.txt", "wt");	//wt모드로 항상 새로운 txt를 쓸수있도록 한다.
	char *ch=NULL;
	key_Log* pCur = m_headKeylog;	
	while (pCur){
		
		fputs(pCur->get_keylog().c_str(), fp);//string변수를 char *로 바꿔주기위해 c_str()사용
		fputs("\n",fp);//각각의 로그가 기록되면 한줄씩 띄어서 나타내기위해서
		pCur = pCur->getNext();
	}
	fclose(fp);	//파일닫음

}
void loglist::writelogfile_m(){//위와동일
	FILE *fp2;
	fopen_s(&fp2, "mouse_log.txt", "wt");
	char *ch = NULL;
	mouse_Log* pCur = m_headMouselog;
	while (pCur){
		fputs(pCur->get_mouselog().c_str(), fp2);
		fputs("\n", fp2);
		pCur = pCur->getNext();
	}
	fclose(fp2);
}
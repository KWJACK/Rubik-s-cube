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
	if (m_headKeylog){//�Է��� �ȵȻ��·� ����ɼ� �����Ƿ� ����� �ִ��� Ȯ��!
		key_Log *pCur_key = m_headKeylog;
		while (pCur_key->getNext()){
			key_Log *temp = pCur_key;
			pCur_key = pCur_key->getNext();
			delete temp;
		}
		delete pCur_key;//�� ������ Ű���� �Ҵ翵������
	}
	if (m_headMouselog){//�Է��� �ȵȻ��·� ����ɼ� �����Ƿ� ����� �ִ��� Ȯ��!
		mouse_Log *pCur_mou = m_headMouselog;
		while (pCur_mou->getNext()){
			mouse_Log *temp2 = pCur_mou;
			pCur_mou = pCur_mou->getNext();
			delete temp2;
		}
		delete pCur_mou;
	}
}
void loglist::insert_keylog(key_Log* newlog){//Ű�α� ��� ����, ���� ���X
	if (!m_headKeylog)
		m_headKeylog = newlog;
	else{
		key_Log* pCur = m_headKeylog;
		while (pCur->getNext() != NULL)
			pCur = pCur->getNext();
		pCur->setNext(newlog);
	}
}
void loglist::insert_mouselog(mouse_Log* newlog){//���콺 �α� ��� ����
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
	fopen_s(&fp, "keyboard_log.txt", "wt");	//wt���� �׻� ���ο� txt�� �����ֵ��� �Ѵ�.
	char *ch=NULL;
	key_Log* pCur = m_headKeylog;	
	while (pCur){
		
		fputs(pCur->get_keylog().c_str(), fp);//string������ char *�� �ٲ��ֱ����� c_str()���
		fputs("\n",fp);//������ �αװ� ��ϵǸ� ���پ� �� ��Ÿ�������ؼ�
		pCur = pCur->getNext();
	}
	fclose(fp);	//���ϴ���

}
void loglist::writelogfile_m(){//���͵���
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
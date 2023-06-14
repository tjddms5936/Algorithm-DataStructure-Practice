#pragma once

class C_LINKEDLIST;

class C_NODE
{
	friend C_LINKEDLIST;
private:
	int m_Data;
	C_NODE* m_pPrev;
	C_NODE* m_pNext;
private:
	C_NODE() = default; // �����ڰ� private���� �ִٴ� ���� ��3�ڰ� NODE�� �������� �� �� ���Ե�

public:
	C_NODE* getNext();
	int getData();
};
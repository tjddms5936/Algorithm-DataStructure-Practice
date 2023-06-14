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
	C_NODE() = default; // 생성자가 private에게 있다는 것은 제3자가 NODE를 선언조차 할 수 없게됨

public:
	C_NODE* getNext();
	int getData();
};
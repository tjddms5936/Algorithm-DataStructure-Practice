#pragma once

#include "node.h"
#include <stdio.h>

class C_LINKEDLIST
{
private:
	C_NODE m_cBeginDummy;
	C_NODE m_cEndDummy;
	C_NODE* m_pBegin;
	C_NODE* m_pEnd;

private:
	C_NODE* createNode(int nData);
	void linkNode(C_NODE* pPrev, C_NODE* pNext);
	void insertNode(C_NODE* pPrev, C_NODE* pNewNode, C_NODE* pNext);
	void eraseNode(C_NODE* pNode);

public:
	C_LINKEDLIST();
	C_NODE* getBegin();
	C_NODE* getEnd();
	void pushBack(int nData); // ���� �ڿ� ������ �߰�
	void pushFront(int nData); // ���� �տ� ������ �߰�
	void remove(int nData);
	void printList();
};
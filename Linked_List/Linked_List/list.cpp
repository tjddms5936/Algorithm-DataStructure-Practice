#include "list.h"

C_NODE* C_LINKEDLIST::createNode(int nData)
{
	C_NODE* pNewNode = new C_NODE{};
	pNewNode->m_Data = nData;
	return pNewNode;
}

void C_LINKEDLIST::linkNode(C_NODE* pPrev, C_NODE* pNext)
{
	pPrev->m_pNext = pNext;
	pNext->m_pPrev = pPrev;
}

void C_LINKEDLIST::insertNode(C_NODE* pPrev, C_NODE* pNewNode, C_NODE* pNext)
{
	linkNode(pPrev, pNewNode);
	linkNode(pNewNode, pNext);
}

void C_LINKEDLIST::eraseNode(C_NODE* pNode)
{
	linkNode(pNode->m_pPrev, pNode->m_pNext);
	delete pNode;
}

void C_LINKEDLIST::printList()
{
	C_NODE* pNode = getBegin();
	while (pNode != &m_cEndDummy)
	{
		printf("%d ", pNode->getData());
		pNode = pNode->getNext();
	}
	printf("\n");
}

C_LINKEDLIST::C_LINKEDLIST() :
	m_cBeginDummy{},
	m_cEndDummy{},
	m_pBegin{},
	m_pEnd{}
{
	m_pBegin = &m_cBeginDummy;
	m_pEnd = &m_cEndDummy;

	linkNode(m_pBegin, m_pEnd);
}

C_NODE* C_LINKEDLIST::getBegin()
{
	return m_pBegin->m_pNext;
}

C_NODE* C_LINKEDLIST::getEnd()
{
	return m_pEnd;
}

void C_LINKEDLIST::pushBack(int nData)
{
	// End의 앞에 만들어준다. 
	insertNode(m_pEnd->m_pPrev, createNode(nData), m_pEnd);
}

void C_LINKEDLIST::pushFront(int nData)
{
	// Front 뒤에 만들어준다. 
	insertNode(m_pBegin, createNode(nData), m_pBegin->m_pNext);
}

void C_LINKEDLIST::remove(int nData)
{
	C_NODE* pFind = getBegin(); // BeginDummy노드의 다음 노드
	C_NODE* pEnd = getEnd(); // EndDummy노드

	while (pFind != pEnd)
	{
		C_NODE* pNext = pFind->getNext();
		if (pFind->getData() == nData)
		{
			C_NODE* pDel = pFind;
			eraseNode(pDel);
		}
		pFind = pNext;
	}
}
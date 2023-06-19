#include "queue.h"

C_QUEUE::S_NODE* C_QUEUE::createNode(int nData)
{
	S_NODE* pNewNode{};
	pNewNode = new S_NODE{};

	pNewNode->nData = nData;
	pNewNode->pAfter = nullptr;
	pNewNode->pBefore = nullptr;

	return pNewNode;
}

void C_QUEUE::printNode(S_NODE* pNode)
{
	if (pNode == m_pBack)
		return;

	printf("%d ", pNode->nData);
	S_NODE* pNext = pNode->pAfter;
	printNode(pNext);
}

void C_QUEUE::linkNode(S_NODE* pPivotNode, S_NODE* pNewNode)
{
	S_NODE* pBeforeNode = pPivotNode->pBefore;

	pBeforeNode->pAfter = pNewNode;
	pNewNode->pBefore = pBeforeNode;
	pPivotNode->pBefore = pNewNode;
	pNewNode->pAfter = pPivotNode;
}

C_QUEUE::C_QUEUE() :
	m_pFrontDummy{},
	m_pBackDummy{},
	m_pFront{},
	m_pBack{},
	m_nSize{}
{
	m_pFront = &m_pFrontDummy;
	m_pBack = &m_pBackDummy;

	m_pFront->pAfter = m_pBack;
	m_pBack->pBefore = m_pFront;
}

void C_QUEUE::push(int nData)
{
	S_NODE* pNewNode = createNode(nData);

	linkNode(m_pBack, pNewNode);
	m_nSize++;
}

int C_QUEUE::pop()
{
	if (m_pBack->pBefore == m_pFront)
		return -1;

	int nResult{};
	nResult = m_pBack->pBefore->nData;
	
	S_NODE* pEraseNode = m_pBack->pBefore;
	linkNode(m_pBack, m_pBack->pBefore->pBefore);

	delete pEraseNode;
	pEraseNode = nullptr;

	m_nSize--;
	return nResult;
}

int C_QUEUE::size()
{
	return m_nSize;
}

bool C_QUEUE::empty()
{
	if (m_nSize > 0)
		return false;
	return true;
}

bool C_QUEUE::front(int& nResult)
{
	if(m_nSize <= 0)
		return false;

	nResult = m_pFront->pAfter->nData;
	return true;
}

bool C_QUEUE::back(int& nResult)
{
	if (m_nSize <= 0)
		return false;

	nResult = m_pBack->pBefore->nData;
	return true;
}

void C_QUEUE::printQueue()
{
	printNode(m_pFront->pAfter);
	printf("\n");
}

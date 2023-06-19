#include "deque.h"

C_DEQUE::S_NODE* C_DEQUE::createNode(int nData)
{
	S_NODE* pNewNode = new S_NODE{};
	pNewNode->nData = nData;
	return pNewNode;
}

void C_DEQUE::linkNode(S_NODE* pLeft, S_NODE* pRight)
{
	pLeft->pR = pRight;
	pRight->pL = pLeft;
}

void C_DEQUE::printNode(S_NODE* pNode)
{
	if (!pNode->pR)
		return;

	printf("%d ", pNode->nData);
	printNode(pNode->pR);
}



C_DEQUE::C_DEQUE() :
	m_BeginDummy{},
	m_EndDummy{},
	m_pBegin{},
	m_pEnd{},
	m_nSize{}
{
	m_pBegin = &m_BeginDummy;
	m_pEnd = &m_EndDummy;

	m_pBegin->pR = m_pEnd;
	m_pEnd->pL = m_pBegin;
}

void C_DEQUE::push_front(int nData)
{
	S_NODE* pNewNode = createNode(nData);

	S_NODE* pNextNode = m_pBegin->pR;

	linkNode(m_pBegin, pNewNode);
	linkNode(pNewNode, pNextNode);

	m_nSize++;
}

void C_DEQUE::push_back(int nData)
{
	S_NODE* pNewNode = createNode(nData);

	S_NODE* pBeforeNode = m_pEnd->pL;

	linkNode(pBeforeNode, pNewNode);
	linkNode(pNewNode, m_pEnd);

	m_nSize++;
}

bool C_DEQUE::pop_front(int& popData)
{
	if (m_nSize <= 0)
		return false;

	popData = m_pBegin->pR->nData;
	S_NODE* pEraseNode = m_pBegin->pR;
	linkNode(m_pBegin, m_pBegin->pR->pR);

	delete pEraseNode;
	pEraseNode = nullptr;

	m_nSize--;

	return true;
}

bool C_DEQUE::pop_back(int& popData)
{
	if (m_nSize <= 0)
		return false;

	popData = m_pEnd->pL->nData;
	S_NODE* pEraseNode = m_pEnd->pL;
	linkNode(m_pEnd->pL->pL, m_pEnd);

	delete pEraseNode;
	pEraseNode = nullptr;

	m_nSize--;

	return true;
}

int C_DEQUE::size()
{
	return m_nSize;
}

bool C_DEQUE::empty()
{
	if(m_nSize > 0)
		return false;

	return true;
}

bool C_DEQUE::front(int& nResult)
{
	if(m_nSize <= 0)
		return false;

	nResult = m_pBegin->pR->nData;
	return true;
}

bool C_DEQUE::back(int& nResult)
{
	if (m_nSize <= 0)
		return false;

	nResult = m_pEnd->pL->nData;
	return true;
}

void C_DEQUE::printData()
{
	printNode(m_pBegin->pR);
	printf("\n");
}

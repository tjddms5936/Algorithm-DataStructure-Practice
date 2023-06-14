#include "BTS.h"

C_BST::S_NODE* C_BST::createNode(int nData)
{
    S_NODE* pNode = new S_NODE{};
    pNode->nData = nData;
    pNode->pL = nullptr;
    pNode->pR = nullptr;
    return pNode;
}

void C_BST::printNode(S_NODE* pNode)
{
    if (!pNode)
        return;

    printf("%d ", pNode->nData);
    printNode(pNode->pL);
    printNode(pNode->pR);
}

bool C_BST::add(int nData)
{
    if (!m_pRoot)
    {
        m_pRoot = createNode(nData);
        return true;
    }

    S_NODE* pFind = m_pRoot;
    S_NODE* pAddParent = pFind;

    // 끝까지 가거나, 이미 데이터 있으면.. 멈춤
    while (pFind && pFind->nData != nData)
    {
        pAddParent = pFind;
        if (pFind->nData < nData)
            pFind = pFind->pR;
        else
            pFind = pFind->pL;
    }

    if (!pAddParent->pR && pAddParent->nData < nData)
    {
        pAddParent->pR = createNode(nData);
        printf("%d의 오른쪽 자식으로 %d추가됨\n", pAddParent->nData, nData);
    }
    else if (!pAddParent->pL && pAddParent->nData > nData)
    {
        pAddParent->pL = createNode(nData);
        printf("%d의 왼쪽 자식으로 %d추가됨\n", pAddParent->nData, nData);
    }
    else
    {
        printf("이미 존재하는 데이터입니다.\n");
        return false;
    }

    return true;
}

void C_BST::erase(int nData)
{
    S_NODE* pFind = m_pRoot;
    S_NODE* pUp{};

    // 끝까지 가거나, 찾는 데이터 있으면 멈춤
    while (pFind && pFind->nData != nData)
    {
        pUp = pFind;
        if (pFind->nData < nData)
            pFind = pFind->pR;
        else
            pFind = pFind->pL;
    }

    if (!pFind) // 찾는 데이터가 없는 경우
        return;

    if (pFind->pL && pFind->pR)
    {
        // 하위 노드가 둘 다 있는 경우
        if (pUp == nullptr)
            m_pRoot = pFind->pR;
        else if (pUp->pL == pFind)
            pUp->pL = pFind->pR;
        else if (pUp->pR == pFind)
            pUp->pR = pFind->pR;

        S_NODE* pLastLeft = pFind->pR;
        while (pLastLeft->pL)
        {
            pLastLeft = pLastLeft->pL;
        }
        pLastLeft->pL = pFind->pL;
    }

    S_NODE* pNext = pFind->pL;

    if(pFind->pR)
        pNext = pFind->pR;

    if (!pUp)
        m_pRoot = pNext;
    else if (pUp->pL == pFind)
        pUp->pL = pNext;
    else if (pUp->pR == pFind)
        pUp->pR = pNext;

    delete pFind;
    pFind = nullptr;
}

bool C_BST::find(int nData)
{
    return false;
}

void C_BST::printBST()
{
    printNode(m_pRoot);
    printf("\n");

}

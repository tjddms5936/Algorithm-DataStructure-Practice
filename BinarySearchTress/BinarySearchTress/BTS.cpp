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

    // ������ ���ų�, �̹� ������ ������.. ����
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
        printf("%d�� ������ �ڽ����� %d�߰���\n", pAddParent->nData, nData);
    }
    else if (!pAddParent->pL && pAddParent->nData > nData)
    {
        pAddParent->pL = createNode(nData);
        printf("%d�� ���� �ڽ����� %d�߰���\n", pAddParent->nData, nData);
    }
    else
    {
        printf("�̹� �����ϴ� �������Դϴ�.\n");
        return false;
    }

    return true;
}

void C_BST::erase(int nData)
{
    S_NODE* pFind = m_pRoot;
    S_NODE* pUp{};

    // ������ ���ų�, ã�� ������ ������ ����
    while (pFind && pFind->nData != nData)
    {
        pUp = pFind;
        if (pFind->nData < nData)
            pFind = pFind->pR;
        else
            pFind = pFind->pL;
    }

    if (!pFind) // ã�� �����Ͱ� ���� ���
        return;

    if (pFind->pL && pFind->pR)
    {
        // ���� ��尡 �� �� �ִ� ���
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

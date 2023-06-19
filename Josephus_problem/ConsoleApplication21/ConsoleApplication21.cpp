// ConsoleApplication21.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

struct S_NODE
{
    int nMyNum;
    S_NODE* pL;
    S_NODE* pR;
};

S_NODE* createNode(int nData);
void linkNode(S_NODE* pBeforeNode, S_NODE* pNewNode);
void printData(S_NODE* pStartNode);
void eraseNode(S_NODE* pEraseNode);

int main()
{
    int nN{};
    scanf_s("%d", &nN);
    int nK{};
    scanf_s("%d", &nK);

    S_NODE BeginDummy{};
    S_NODE EndDummy{};
    S_NODE* pBegin = &BeginDummy;
    S_NODE* pEnd = &EndDummy;

    pBegin->pL = pEnd;
    pBegin->pR = pEnd;
    pEnd->pR = pBegin;
    pEnd->pL = pBegin;
    
    S_NODE* pBeforeNode = pBegin;
    for (int i = 1; i <= nN; i++)
    {
        S_NODE* pNewNode = createNode(i);
        linkNode(pBeforeNode, pNewNode);
        pBeforeNode = pNewNode;
    }
    
    int nSize = nN;
    int nTurn = 1;
    S_NODE* pFindNode = pBegin->pR;
    
    printf("<");
    while (nSize > 0)
    {
        S_NODE* pEraseNode = pFindNode;

        pFindNode = pFindNode->pR;
        if (pFindNode == pEnd)
            pFindNode = pBegin->pR;

        if (nTurn == nK)
        {
            // 지워질 타이밍
            nSize--;
            if (nSize > 0)
                printf("%d, ", pEraseNode->nMyNum);
            else
                printf("%d", pEraseNode->nMyNum);
            eraseNode(pEraseNode);
            nTurn = 0;
        }
        nTurn++;
    }
    printf(">");
}

S_NODE* createNode(int nData)
{
    S_NODE* pNewNode = new S_NODE{};
    pNewNode->nMyNum = nData;
    return pNewNode;
}

void linkNode(S_NODE* pBeforeNode, S_NODE* pNewNode)
{
    S_NODE* pNextNode = pBeforeNode->pR;
    pBeforeNode->pR = pNewNode;
    pNewNode->pL = pBeforeNode;
    pNewNode->pR = pNextNode;
    pNextNode->pL = pNewNode;
}

void printData(S_NODE* pStartNode)
{
    S_NODE* pPrintNode = pStartNode->pR;
    while (pPrintNode != pStartNode->pL)
    {
        printf("%d ", pPrintNode->nMyNum);
        pPrintNode = pPrintNode->pR;
    }
    printf("\n");
}

void eraseNode(S_NODE* pEraseNode)
{
    S_NODE* pBeforeNode = pEraseNode->pL;
    S_NODE* pAfterNode = pEraseNode->pR;

    pBeforeNode->pR = pAfterNode;
    pAfterNode->pL = pBeforeNode;

    delete pEraseNode;
    pEraseNode = nullptr;
}

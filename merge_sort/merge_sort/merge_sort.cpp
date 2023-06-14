// merge_sort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void mergeSort(int* pData, int nLength, int* pTmp);
void printData(int* pData, int nLegnth);

int main()
{
    int arData[10]{ 15,73,64,16,20,41,22,76,38,5 };
    int pTmp[10]{};

    mergeSort(arData, 10, pTmp);
    printData(arData, 10);
}

void mergeSort(int* pData, int nLength, int* pTmp)
{
    if (nLength <= 1)
        return;

    int* pLeftData = pData;
    int nLeftLength = nLength / 2;
    int* pRightData = pData + nLeftLength;
    int nRightLength = nLength - nLeftLength;

    mergeSort(pLeftData, nLeftLength, pTmp);
    mergeSort(pRightData, nRightLength, pTmp);

    int nLeftIndex{};
    int nRightIndex{};
    for (int i = 0; i < nLength; i++)
    {
        int* pData = pLeftData;
        int* pDatIndex = &nLeftIndex;
        if (*pDatIndex >= nLeftLength || (nRightIndex < nRightLength && pData[*pDatIndex] > pRightData[nRightIndex]))
        {
            pData = pRightData;
            pDatIndex = &nRightIndex;
        }

        pTmp[i] = pData[*pDatIndex];
        (*pDatIndex)++;
    }

    // 임시 공간의 것을 다시 원래 배열에 넣어주는 것임..
    for (int i = 0; i < nLength; i++)
    {
        pData[i] = pTmp[i];
    }
}

void printData(int* pData, int nLegnth)
{
    for (int i = 0; i < nLegnth; i++)
    {
        printf("%d ", pData[i]);
    }
    printf("\n");
}

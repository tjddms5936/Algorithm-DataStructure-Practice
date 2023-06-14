// selection_sort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int findMinDataIndex(const int* p, int nLength);
void swapData(int& nDst, int& nSrc);
void selectSortLogic(int* pData, int nLength);
void printData(const int* pData, int nLength);
void selectionSort(int* pData, int nLength);

int main()
{
    // 중복 데이터 없는 경우로 작업
    int arData[9]{ 6,5,2,4,3,1,7,9,8 };
    selectionSort(arData, 9);
    printData(arData, 9);
}

int findMinDataIndex(const int* p, int nLength)
{
    // 배열 내용물을 직접 복사하지 말자
    int nMinIndex{};

    for (int i = 1; i < nLength; i++)
    {
        if (p[nMinIndex] > p[i])
            nMinIndex = i;
    }

    return nMinIndex;
}

void swapData(int& nDst, int& nSrc)
{
    int nTmp{};
    nTmp = nDst;
    nDst = nSrc;
    nSrc = nTmp;
}

void selectSortLogic(int* pData, int nLength)
{
    swapData(pData[0], pData[findMinDataIndex(pData, nLength)]);
}

void printData(const int* pData, int nLength)
{
    for (int i = 0; i < nLength; i++)
    {
        printf("%d ", pData[i]);
    }
    printf("\n");
}

void selectionSort(int* pData, int nLength)
{
    // 한 개짜리 배열은 무조건 정렬이 되어있는 상태. 그러니 배열의 개수가 1개일 때는 정렬할 필요가 없다. 
    while (nLength > 1)
    {
        selectSortLogic(pData, nLength);

        pData++;
        nLength--;
    }
}
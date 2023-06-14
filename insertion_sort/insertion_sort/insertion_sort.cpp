// insertion_sort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void insertSortLogic(int* pData, int nLength, int nInsertData);
void insertSort(int* pData, int nLength);
void printData(const int* pData, int nLength);

int main()
{
    int arData[9]{ 6,5,2,4,3,1,7,9,8 };
    insertSort(arData, 9);

    printData(arData, 9);
}

void insertSortLogic(int* pData, int nLength, int nInsertData)
{
    int nCompareData{};
    int nCompareIndex{};
    int nBackupIndex{};

    nCompareIndex = nLength - 2;
    nCompareData = pData[nCompareIndex];
    nBackupIndex = nCompareIndex + 1;

    while (nCompareIndex >= 0 && nCompareData > nInsertData)
    {
        pData[nBackupIndex] = nCompareData;

        nBackupIndex = nCompareIndex;
        nCompareIndex--;
        nCompareData = pData[nCompareIndex];
    }

    pData[nBackupIndex] = nInsertData;

}

void insertSort(int* pData, int nLength)
{
    int nCompareLength{};
    int nInsertData{};

    nCompareLength = 2;

    while (nCompareLength <= nLength)
    {
        nInsertData = pData[nCompareLength - 1];
        insertSortLogic(pData, nCompareLength, nInsertData);
        nCompareLength++;
    }

}

void printData(const int* pData, int nLength)
{
    for (int i = 0; i < nLength; i++)
    {
        printf("%d ", pData[i]);
    }
    printf("\n");
}

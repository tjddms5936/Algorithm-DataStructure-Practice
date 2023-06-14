// bubble_sort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void BubbleSortLogic(int* pData, int nLength);
void BubbleSort(int* pData, int nLength);
void printData(const int* pData, int nLength);

int main()
{
    int arData[5] = { 10,5,1,8,3 };

    BubbleSort(arData, 5);
    printData(arData, 5);
}

void BubbleSortLogic(int* pData, int nLength)
{
    int nBeforeIndex{};
    int nBeforeData{};

    while (nBeforeIndex < nLength - 1)
    {
        nBeforeData = pData[nBeforeIndex];
        if (nBeforeData > pData[nBeforeIndex + 1])
        {
            pData[nBeforeIndex] = pData[nBeforeIndex + 1];
            pData[nBeforeIndex + 1] = nBeforeData;
        }
        nBeforeIndex++;
    }
}

void BubbleSort(int* pData, int nLength)
{
    while (nLength > 1)
    {
        BubbleSortLogic(pData, nLength);
        nLength--;
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

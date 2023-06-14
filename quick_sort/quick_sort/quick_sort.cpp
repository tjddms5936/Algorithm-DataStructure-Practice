// quick_sort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void quickSort(int* pData, int nLength);
void printData(const int* pData, int nLength);
void swapData(int& nDst, int& nSrc);
int main()
{
    int arData[10]{34,12,49,76,54,84,31,29,64,33};

    quickSort(arData, 10);
    printData(arData, 10);
}

void quickSort(int* pData, int nLength)
{
    if (nLength <= 1)
        return;

    int nPivot{};
    int nLow{};
    int nHigh{};

    nLow = 1;
    nHigh = nLength - 1;
    while (nLow <= nHigh)
    {
        // 아래의 경우 nLow = nLength 까지 업데이트 될 수 있는데, 우린 이 인덱스로 배열에 접근만 안하면 된다.
        while (nLow < nLength && pData[nLow] < pData[nPivot])
            nLow++;

        // 아래의 경우 nHigh는 nPivot을 만나는 순간 더이상 내려갈 수 없다. 즉, nPivot이 기준 역할을 해주는 것이다.
        while (pData[nHigh] > pData[nPivot])
            nHigh--;

        if (nLow < nHigh)
            swapData(pData[nLow], pData[nHigh]);
        else if (nLow > nHigh)
            swapData(pData[nPivot], pData[nHigh]);
    }

    quickSort(pData, nHigh);
    quickSort(pData + nHigh + 1, nLength - nLow);
}

void printData(const int* pData, int nLength)
{
    for (int i = 0; i < nLength; i++)
    {
        printf("%d ", pData[i]);
    }
    printf("\n");
}

void swapData(int& nDst, int& nSrc)
{
    int nTmp = nDst;
    nDst = nSrc;
    nSrc = nTmp;
}

// BinarySearch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

const int* binarySearch(const int* pData, int nLength, int nFindData);

int main()
{
    int arData[50]{};

    for (int i = 0; i < 50; i++)
    {
        arData[i] = i * 2;
    }

    const int* pResult{}; // 찾았으면 찾은 번지..를

    pResult = binarySearch(arData, 50, 26);

    printf("%d \n", *pResult);
}

const int* binarySearch(const int* pData, int nLength, int nFindData)
{
    if (nLength <= 0)
        return nullptr;

    int nFindIndex = nLength / 2;

    if (pData[nFindIndex] > nFindData)
        return binarySearch(pData, nFindIndex, nFindData); // 뒤에 짜르기

    if (pData[nFindIndex] < nFindData)
        return binarySearch(pData + nFindIndex + 1, nLength - (nFindIndex + 1), nFindData); // 앞에 짜르기

    // return nullptr; // 로직상 nullptr이 나올 필요가 없음
    return pData + nFindIndex; // 같으면 찾은것을 반환하는것을 default로 주자. 
}
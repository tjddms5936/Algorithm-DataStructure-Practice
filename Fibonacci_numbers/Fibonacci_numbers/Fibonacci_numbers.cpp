// Fibonacci_numbers.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void fibonacci(int nIndex, int* pResult);

int main()
{
    int nData{};


    fibonacci(8, &nData);
    printf("%d\n", nData);

}

void fibonacci(int nIndex, int* pResult)
{
    if (nIndex <= 1)
    {
        *pResult = 1;
        return;
    }

    int nResult1{};
    int nResult2{};

    fibonacci(nIndex - 2, &nResult1);
    fibonacci(nIndex - 1, &nResult2);

    *pResult = nResult1 + nResult2;
}
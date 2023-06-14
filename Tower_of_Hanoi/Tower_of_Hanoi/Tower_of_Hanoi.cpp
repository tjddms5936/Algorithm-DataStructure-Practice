// Tower_of_Hanoi.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void hanoi(int nNumber, char S, char T, char E);

int main()
{
    hanoi(3, 'a', 'b', 'c');
}

void hanoi(int nNumber, char S, char T, char E)
{
    if (nNumber <= 0)
        return;

    hanoi(nNumber - 1, S, E, T); // n-1개가 T자리로 옮겨져야 한다.  
    printf("%c -> %c, %d \n", S, E, nNumber); // 제일 밑의 판을 E로 출력
    hanoi(nNumber - 1, T, S, E); // T자리로 옮긴 n-1개를 다시 E지점으로 옮겨야 한다. 
}
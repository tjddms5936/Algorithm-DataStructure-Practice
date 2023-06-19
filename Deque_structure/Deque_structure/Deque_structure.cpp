// Deque_structure.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "deque.h"

int main()
{
    C_DEQUE cDeque{};

    cDeque.push_front(5);
    cDeque.push_front(2);
    cDeque.push_front(1);
    cDeque.push_front(6);

    cDeque.push_back(100);
    cDeque.push_back(1010);
    cDeque.push_back(101110);
    cDeque.printData();

    int nPopData{};
    if (cDeque.pop_front(nPopData))
        printf("Pop : %d\n", nPopData);
    if (cDeque.pop_back(nPopData))
        printf("Pop : %d\n", nPopData);
    cDeque.printData();

    int nData{};
    if (cDeque.front(nData))
        printf("Front : %d\n", nData);
    if (cDeque.back(nData))
        printf("Back : %d\n", nData);
}
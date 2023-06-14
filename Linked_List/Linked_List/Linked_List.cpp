// Linked_List.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "list.h"

int main()
{
    C_LINKEDLIST cList{};
    cList.pushFront(5);
    cList.pushFront(14);
    cList.pushFront(25);

    cList.pushBack(7);
    cList.pushBack(12);
    cList.pushBack(67);

    cList.printList();

    cList.remove(14);
    cList.printList();
}


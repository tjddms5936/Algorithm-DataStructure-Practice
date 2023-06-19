// queue_structure.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "queue.h"

int main()
{
    C_QUEUE cQueue{};
    cQueue.push(5);
    cQueue.push(4);
    cQueue.push(2);
    cQueue.push(7);
    cQueue.push(9);
    cQueue.push(12);
    cQueue.push(43);
    cQueue.printQueue();
    printf("Queue Size : %d\n", cQueue.size());
    printf("Pop Data : %d\n", cQueue.pop());
    cQueue.printQueue();

    int nFrontData{}; 
    if (cQueue.front(nFrontData))
        printf("Front Data : %d\n", nFrontData);

    int nBackData{};
    if(cQueue.back(nBackData))
        printf("Back Data : %d\n", nBackData);

    printf("Queue Size : %d\n", cQueue.size());
}

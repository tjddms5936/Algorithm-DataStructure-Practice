// heap_structure.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "heap.h"

int main()
{
    C_HEAP cHeap{};
    
    cHeap.init(10);

    cHeap.add(10);
    cHeap.add(5);
    cHeap.add(15);
    cHeap.add(2);
    cHeap.add(12);

    cHeap.print();

    int nData{};
    cHeap.pop(&nData);
    printf("%d\n", nData);

    cHeap.release();
    if (!cHeap.pop(&nData))
        printf("꺼낼 데이터가 없습니다!\n");
}

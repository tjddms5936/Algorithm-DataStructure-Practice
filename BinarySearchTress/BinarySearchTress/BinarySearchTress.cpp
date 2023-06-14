// BinarySearchTress.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "BTS.h"

int main()
{
    C_BST cBst{};

    cBst.add(20);
    cBst.add(10);
    cBst.add(40);
    cBst.add(5);
    cBst.add(19);
    cBst.add(21);
    cBst.add(80);

    cBst.erase(20);
    cBst.printBST();

}

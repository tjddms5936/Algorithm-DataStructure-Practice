#include "node.h"

C_NODE* C_NODE::getNext()
{
    return m_pNext;
}

int C_NODE::getData()
{
    return m_Data;
}
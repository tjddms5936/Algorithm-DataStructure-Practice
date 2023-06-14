#pragma once
#include <stdio.h>

class C_HEAP
{
private:
	// 힙구조는 5개 원소라고 하면 6개를 잡아야 한다. 0번지를 안쓰니까
	int* m_pBuffer;
	int m_nLength; // 사용자가 전달하는 배열의 길이. 0번지를 안쓰는 걸 감안하고 적용해야함
	int m_nCount; // 배열 안의 원소 개수를 의미.

private:
	// 숫자에 의미 부여
	enum
	{
		E_NULL = 0
	};

private:
	void exchange(int nDownIndex);
	void swapData(int nDst, int nSrc);
	void erase();
	void setChildIndex(int nParentIndex, int* pChildLeftIndex, int* pChildRightIndex);
	void findMaxChildIndex(int* pMaxChildIndex, int nChildLeftIndex, int nChildRightIndex);
public:
	C_HEAP() = default;
	~C_HEAP() = default;
	C_HEAP(const C_HEAP&) = delete;
	C_HEAP& operator=(const C_HEAP&) = delete;

	void init(int nLength); // 사용자로부터 받아온 길이를 m_nLength에 적용
	void release(); // 배열 동적 할당 해제
	bool add(int nData);
	int getLength(); // 사용자 기준으로 배열의 길이 출력
	bool pop(int* pData);
	void print(); // 전체 배열중 데이터 있는 부분까지만 출력
};
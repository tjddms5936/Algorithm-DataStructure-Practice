#include "heap.h"

void C_HEAP::init(int nLength)
{
	// 사소한 것이지만, nLength를 직접적으로 쓰지말고 백업해놓고 백업본을 쓰자
	m_nLength = nLength + 1; // 백업해놓기. 우리는 안쓰는 0번지도 추가해주어야 하기때문에 +1
	m_pBuffer = new int[m_nLength] {};
}

void C_HEAP::release()
{
	m_nLength = 0;
	m_nCount = 0;
	delete[] m_pBuffer; // 배열 동적할당이다. 만약 배열 원소도 동적할당이면 원소까지 delete.
	m_pBuffer = nullptr;
}

int C_HEAP::getLength()
{
	return m_nLength - 1; // 사용자가 5개 길이 입력했으면 5를 반환해줘야 한다.
}

void C_HEAP::print()
{
	// m_nCount는 들어있는 원소의 개수. 헷갈릴 수 있으나 다음과 같이 생각해보자
	// 배열에 데이터 1개있음(m_nCount는 1). 배열에서 1번지까지 있음. 
	for (int i = 1; i < m_nCount + 1; i++)
	{
		printf("%d ", m_pBuffer[i]);
	}
	printf("\n");
}

void C_HEAP::exchange(int nDownIndex)
{
	int nUpIndex = nDownIndex / 2;
	if (nUpIndex == E_NULL || m_pBuffer[nDownIndex] < m_pBuffer[nUpIndex])
		return;
	swapData(nUpIndex, nDownIndex);
	exchange(nUpIndex);
}


void C_HEAP::swapData(int nDst, int nSrc)
{
	int nTmp = m_pBuffer[nDst];
	m_pBuffer[nDst] = m_pBuffer[nSrc];
	m_pBuffer[nSrc] = nTmp;
}

bool C_HEAP::add(int nData)
{
	// 배열에 데이터가 꽉 찼을 때 Stop
	if (m_nCount >= m_nLength - 1)
	{
		printf("배열이 꽉찼습니다.\n");
		return false;
	}

	// 배열의 마지막에 일단 넣는다.
	int nIndex{};
	nIndex = m_nCount + 1;
	m_nCount++;
	m_pBuffer[nIndex] = nData;

	// 데이터를 위의 데이터와 비교해가면서 교환한다. 
	// 이 때 재귀함수 호출
	int nUpIndex{};
	nUpIndex = nIndex / 2;
	exchange(nIndex);

	return true;
}

void C_HEAP::erase()
{
	// 제일 마지막 노드의 데이터가 첫번째 노드의 데이터가 된다.
	m_pBuffer[1] = m_pBuffer[m_nCount];
	m_nCount--;

	// 일단 밑의 노드가 둘 다 있는 경우만 작업한다.
	int nParentIndex{};
	int nChildLeftIndex{};
	int nChildRightIndex{};
	int nMaxChildIndex{};
	bool bLoop = true;

	nParentIndex = 1;
	nChildLeftIndex = 2 * nParentIndex;
	nChildRightIndex = nChildLeftIndex + 1;

	// m_pBuffer[nChildLeftIndex] != E_NULL 오른쪽 있으면 왼쪽은 무조건 있으니까... 필요없음. 
	// 왼족만 있는 경우도 아주 쉽게 추가해보자
	while (nChildLeftIndex <= m_nCount && bLoop == true)
	{
		nMaxChildIndex = nChildLeftIndex;
		if (nChildRightIndex <= m_nCount && m_pBuffer[nChildLeftIndex] < m_pBuffer[nChildRightIndex])
			nMaxChildIndex = nChildRightIndex; // 조건식에 오른쪽이 존재할 경우만을 추가

		if (m_pBuffer[nParentIndex] < m_pBuffer[nMaxChildIndex])
			swapData(nParentIndex, nMaxChildIndex);
		else
			bLoop = false; // 내려갈 깊이는 더 있지만 바로 아래놈중 바꿀게 없을 경우 Loop 종료

		nParentIndex = nMaxChildIndex;
		nChildLeftIndex = 2 * nParentIndex;
		nChildRightIndex = nChildLeftIndex + 1;
	}
}

void C_HEAP::setChildIndex(int nParentIndex, int* pChildLeftIndex, int* pChildRightIndex)
{
	*pChildLeftIndex = 2 * nParentIndex;
	*pChildRightIndex = 2 * nParentIndex + 1;
}

void C_HEAP::findMaxChildIndex(int* pMaxChildIndex, int nChildLeftIndex, int nChildRightIndex)
{
	*pMaxChildIndex = nChildRightIndex;
	if (m_pBuffer[nChildLeftIndex] >= m_pBuffer[nChildRightIndex])
		*pMaxChildIndex = nChildLeftIndex;
}


bool C_HEAP::pop(int* pData)
{
	if (m_nCount <= 0)
		return false;
	*pData = m_pBuffer[1];
	erase();

	return true;
}
#include "heap.h"

void C_HEAP::init(int nLength)
{
	// ����� ��������, nLength�� ���������� �������� ����س��� ������� ����
	m_nLength = nLength + 1; // ����س���. �츮�� �Ⱦ��� 0������ �߰����־�� �ϱ⶧���� +1
	m_pBuffer = new int[m_nLength] {};
}

void C_HEAP::release()
{
	m_nLength = 0;
	m_nCount = 0;
	delete[] m_pBuffer; // �迭 �����Ҵ��̴�. ���� �迭 ���ҵ� �����Ҵ��̸� ���ұ��� delete.
	m_pBuffer = nullptr;
}

int C_HEAP::getLength()
{
	return m_nLength - 1; // ����ڰ� 5�� ���� �Է������� 5�� ��ȯ����� �Ѵ�.
}

void C_HEAP::print()
{
	// m_nCount�� ����ִ� ������ ����. �򰥸� �� ������ ������ ���� �����غ���
	// �迭�� ������ 1������(m_nCount�� 1). �迭���� 1�������� ����. 
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
	// �迭�� �����Ͱ� �� á�� �� Stop
	if (m_nCount >= m_nLength - 1)
	{
		printf("�迭�� ��á���ϴ�.\n");
		return false;
	}

	// �迭�� �������� �ϴ� �ִ´�.
	int nIndex{};
	nIndex = m_nCount + 1;
	m_nCount++;
	m_pBuffer[nIndex] = nData;

	// �����͸� ���� �����Ϳ� ���ذ��鼭 ��ȯ�Ѵ�. 
	// �� �� ����Լ� ȣ��
	int nUpIndex{};
	nUpIndex = nIndex / 2;
	exchange(nIndex);

	return true;
}

void C_HEAP::erase()
{
	// ���� ������ ����� �����Ͱ� ù��° ����� �����Ͱ� �ȴ�.
	m_pBuffer[1] = m_pBuffer[m_nCount];
	m_nCount--;

	// �ϴ� ���� ��尡 �� �� �ִ� ��츸 �۾��Ѵ�.
	int nParentIndex{};
	int nChildLeftIndex{};
	int nChildRightIndex{};
	int nMaxChildIndex{};
	bool bLoop = true;

	nParentIndex = 1;
	nChildLeftIndex = 2 * nParentIndex;
	nChildRightIndex = nChildLeftIndex + 1;

	// m_pBuffer[nChildLeftIndex] != E_NULL ������ ������ ������ ������ �����ϱ�... �ʿ����. 
	// ������ �ִ� ��쵵 ���� ���� �߰��غ���
	while (nChildLeftIndex <= m_nCount && bLoop == true)
	{
		nMaxChildIndex = nChildLeftIndex;
		if (nChildRightIndex <= m_nCount && m_pBuffer[nChildLeftIndex] < m_pBuffer[nChildRightIndex])
			nMaxChildIndex = nChildRightIndex; // ���ǽĿ� �������� ������ ��츸�� �߰�

		if (m_pBuffer[nParentIndex] < m_pBuffer[nMaxChildIndex])
			swapData(nParentIndex, nMaxChildIndex);
		else
			bLoop = false; // ������ ���̴� �� ������ �ٷ� �Ʒ����� �ٲܰ� ���� ��� Loop ����

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
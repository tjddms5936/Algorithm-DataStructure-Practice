#pragma once
#include <stdio.h>

class C_HEAP
{
private:
	// �������� 5�� ���Ҷ�� �ϸ� 6���� ��ƾ� �Ѵ�. 0������ �Ⱦ��ϱ�
	int* m_pBuffer;
	int m_nLength; // ����ڰ� �����ϴ� �迭�� ����. 0������ �Ⱦ��� �� �����ϰ� �����ؾ���
	int m_nCount; // �迭 ���� ���� ������ �ǹ�.

private:
	// ���ڿ� �ǹ� �ο�
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

	void init(int nLength); // ����ڷκ��� �޾ƿ� ���̸� m_nLength�� ����
	void release(); // �迭 ���� �Ҵ� ����
	bool add(int nData);
	int getLength(); // ����� �������� �迭�� ���� ���
	bool pop(int* pData);
	void print(); // ��ü �迭�� ������ �ִ� �κб����� ���
};
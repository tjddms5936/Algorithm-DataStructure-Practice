#pragma once
#include <stdio.h>

class C_BST
{
private:
	// �����˻�Ʈ���� ������ : �����͸� �������! 
	struct S_NODE
	{
		int nData;
		S_NODE* pL;
		S_NODE* pR;
	};
private:
	S_NODE* m_pRoot; // ������ ������ �ִ�. �ٸ� ���� �𸥴�
	S_NODE* createNode(int nData);
private:
	void printNode(S_NODE* pNode);
public:
	C_BST() = default;
	~C_BST() = default;
	C_BST(const C_BST&) = delete;
	C_BST& operator=(const C_BST&) = delete;

	bool add(int nData); // �ߺ� ������ ��� ���ϱ� ������. �������� ��ȯ
	void erase(int nData); // ������ �̰͵� �������� ��ȯ����� ��. �ٵ� ��� ���⿡ ���� �����ص� �����ϱ� ��ȯ �����ִ� ��� ���� �׸��� �� ���������µ� �ϴ��� void�� ������
	bool find(int nData);

	void printBST();
};
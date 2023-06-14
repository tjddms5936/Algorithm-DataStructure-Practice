#pragma once
#include <stdio.h>

class C_BST
{
private:
	// 이진검색트리의 목적은 : 데이터를 기억해줘! 
	struct S_NODE
	{
		int nData;
		S_NODE* pL;
		S_NODE* pR;
	};
private:
	S_NODE* m_pRoot; // 시작은 정해져 있다. 다만 끝은 모른다
	S_NODE* createNode(int nData);
private:
	void printNode(S_NODE* pNode);
public:
	C_BST() = default;
	~C_BST() = default;
	C_BST(const C_BST&) = delete;
	C_BST& operator=(const C_BST&) = delete;

	bool add(int nData); // 중복 데이터 허용 안하기 때문에. 실패유무 반환
	void erase(int nData); // 원래는 이것도 실패유무 반환해줘야 함. 근데 사람 성향에 따라 실패해도 없으니까 반환 안해주는 경우 있음 그리고 더 복잡해지는데 일단은 void로 만들어보자
	bool find(int nData);

	void printBST();
};
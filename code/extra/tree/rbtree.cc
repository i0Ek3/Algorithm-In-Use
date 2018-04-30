// 
// rbtree.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-22 16:09:35
// 
// @Reb Black Tree 
//  Ref1: https://bbs.pediy.com/thread-225432.html
//  Ref2: http://www.sohu.com/a/201923614_466939
//
// @Nature
//  BST's nature (but there is a flaw, it has line performance)
//  Auto-banlance
//  Nodes' color is red or black
//  Root node's color is black
//  All leaf nodes' color is black and it's value is NULL
//  All red nodes' two subnodes' color is black, cannot exisit two continuous red nodes
//  Any nodes come to it's leaf nodes of path which have same numbers black nodes
//
// @Fix Up
//  Change the color
//      Black -> Red
//      Red -> Black
//  Roation
//      LR
//      RR
//
// 
//
//
 
#include <iostream>
#include <queue>
#include <assert.h>
using std::queue;
using std::cout;
using std::endl;


//RBTree definaion
class RBTree 
{

private:
    //I dont know what are you doing!
    //Who can explain?
    typedef enum {
        E_TREE_BLACK,
        E_TREE_RED,
        E_TREE_COLOR_MAX
    }ETreeColor;

    const static char *s_pszColor[E_TREE_COLOR_MAX];
    
    typedef struct __TreeNode {
        __TreeNode* pParent;
        __TreeNode* pLeft;
        __TreeNode* pRight;
        ETreeColor eColor;
        int nValue;
    }TreeNode, *PTreeNode;

public:
    RBTree();
    ~RBTree();
    void InsertData(int nValue);
    bool Empty();
    bool GetMax(PTreeNode pNode, int &nMax);
    bool GetMin(PTreeNode pNode, int &nMin);
    void DeleteElement(int nDelete);
    bool FindElement(int nFindValue);
    void BFS();

private:
    void InsertedFixUp(PTreeNode pInsertNode); //fixed up tree after insert node
    void DeletedFixUp(PTreeNode pFixNode); //fixed up tree after delete node
    void SingleLeftRoation(PTreeNode &pNode, PTreeNode &newTop); //LR then return newTop
    void SingleRightRoation(PTreeNode &pNode, PTreeNode &newTop); //RR then return newTop
    void ReplaceParent(PTreeNode pBeReplaceNode, PTreeNode pReplaceNode); //replace the pReplaceNode's father to pBeReplaceNode
    bool GetMinNode(PTreeNode pNode, PTreeNode &pMinNode); 

private:
    PTreeNode m_pRoot; //the pointer to root
    PTreeNode m_pNil; //null node

};


//RBTree specific implement

RBTree::RBTree() 
{
	//null rbtree
	m_pRoot = nullptr;
	m_pNil = new TreeNode();
	m_pNil->pLeft = nullptr;
	m_pNil->pRight = nullptr;
	m_pNil->pParent = nullptr;
	m_pNil->eColor = E_TREE_BLACK;
	m_pNil->nValue = 0xFFFFFFFF;
}

RBTree::~RBTree() 
{
	if (!Empty())
	{
		queue<PTreeNode> nodeQue;
		nodeQue.push(m_pRoot);
		while (!nodeQue.empty())
		{
			PTreeNode pNode = nodeQue.front();
			PTreeNode pLeft = pNode->pLeft;
			PTreeNode pRight= pNode->pRight;
			nodeQue.pop();
			delete pNode;

			if (pLeft != m_pNil)
			{
				nodeQue.push(pLeft);
			}

			if (pRight != m_pNil)
			{
				nodeQue.push(pRight);
			}
		}
	}

	if (m_pNil)
	{
		//free space
		delete m_pNil;
		m_pNil = nullptr;
	}
}

void RBTree::InsertData(int nValue)
{

}

bool RBTree::Empty()
{
	return nullptr == m_pRoot;
}

bool RBTree::GetMax(PTreeNode pNode, int &nMax)
{
	if (nullptr == pNode)
	{
		return false;
	}

	while (pNode)
	{
		nMax = pNode->nValue;
		pNode = pNode->pRight;
	}
	return true;
}

bool RBTree::GetMin(PTreeNode pNode, int &nMin)
{
	if (nullptr == pNode)
	{
		return false;
	}

	while (pNode)
	{
		nMin = pNode->nValue;
		pNode = pNode->pLeft;
	}
	return true;
}

void RBTree::DeleteElement(int nDelete)
{

}

bool RBTree::FindElement(int nFindValue)
{
	if (Empty())
	{
		return false;
	}

	PTreeNode pCurrent = m_pRoot;
	while (m_pNil != pCurrent)
	{
		//left small, right big
		if (nFindValue < pCurrent->nValue)
		{
			pCurrent = pCurrent->pLeft;
		}
		else if (nFindValue > pCurrent->nValue)
		{
			pCurrent = pCurrent->pRight;
		}
		else
		{
			return true;
		}
	}
	return true;
}

void RBTree::BFS()
{

}

void RBTree::InsertedFixUp(PTreeNode pInsertNode)
{

}

void RBTree::DeletedFixUp(PTreeNode pFixNode)
{

}

void RBTree::SingleLeftRoation(PTreeNode &pNode, PTreeNode &newTop)
{

}

void RBTree::SingleRightRoation(PTreeNode &pNode, PTreeNode &newTop)
{

}

void RBTree::ReplaceParent(PTreeNode pBeReplaceNode, PTreeNode pReplaceNode)
{

}

bool RBTree::GetMinNode(PTreeNode pNode, PTreeNode &pMinNode)
{
	if (nullptr == pNode || pNode == m_pNil)
	{
		return false;
	}
	PTreeNode pPreNode = pNode->pParent;
	while (m_pNil != pNode)
	{
		pPreNode = pNode;
		pNode = pNode->pLeft;
	}
	pMinNode = pPreNode;
	return true;
}


//Test
int main()
{


    return 0;
}


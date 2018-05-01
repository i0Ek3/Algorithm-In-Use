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
    //if there is no node we should create one node then insert data
    if (Empty())
    {
        m_pRoot = new TreeNode();
        m_pRoot->eColor = E_TREE_BLACK;
        m_pRoot->nValue = nValue;
        m_pRoot->pLeft = m_pNil;
        m_pRoot->pRight = m_pNil;
        m_pRoot->pParent = m_pNil;
        return;
    }
    
    //find the place to insert
    PTreeNode pPreNode = m_pRoot->pParent;
    PTreeNode pCurrent = m_pRoot;
    while (m_pNil != pCurrent)
    {
        pPreNode = pCurrent;
        if (nValue <= pCurrent->nValue)
        {
            pCurrent = pCurrent->pLeft;
        }
        else
        {
            pCurrent = pCurrent->pRight;
        }
    }

    //insert data into right place
    PTreeNode pInsertNode = new TreeNode();
    pInsertNode->eColor = E_TREE_RED;
    pInsertNode->nValue = nValue;
    pInsertNode->pLeft = m_pNil;
    pInsertNode->pRight = m_pNil;
    pInsertNode->pParent = pPreNode;
    if (nValue <= pPreNode->nValue)
    {
        pPreNode->pLeft = pInsertNode;
    }
    else
    {
        pPreNode->pRight = pInsertNode;
    }

    //start fixed up the rbtree from the insert place 
    InsertedFixUp(pInsertNode);
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
    if (Empty())
    {
        return;
    }

    //find the node which should be deleted 
    PTreeNode pCurrent = m_pRoot;
    PTreeNode pNeedDeleteNode = nullptr;
    while (m_pNil != pCurrent)
    {
        if (nDelete < pCurrent->nValue)
        {
            pCurrent = pCurrent->pLeft;
        }
        else if (nDelete > pCurrent->nValue)
        {
            pCurrent = pCurrent->pRight;
        }
        else
        {
            pNeedDeleteNode = pCurrent;
            break;
        }
    }

    if (nullptr == pNeedDeleteNode)
    {
        return;
    }

    //execute delete
    PTreeNode pRealDeleteNode = nullptr;
    PTreeNode pFixUpNode = nullptr;
    ETreeColor eRealDeleteColor = E_TREE_COLOR_MAX;

    //if the left subtree is null
    if (m_pNil == pNeedDeleteNode->pLeft)
    {
        pRealDeleteNode = pNeedDeleteNode;
        eRealDeleteColor = pRealDeleteNode->eColor;
        pFixUpNode = pRealDeleteNode->pRight;
        ReplaceParent(pRealDeleteNode, pRealDeleteNode->pRight);
    }
    else if (m_pNil == pNeedDeleteNode->pRight) //if the right subtree is null
    {
        pRealDeleteNode = pNeedDeleteNode;
        eRealDeleteColor = pRealDeleteNode->eColor;
        pFixUpNode = pRealDeleteNode->pLeft;
        ReplaceParent(pRealDeleteNode, pRealDeleteNode->pLeft);
    }
    else // ???  none of left and right subtrees are null
    {
        // what talking about???
        bool bGetMinRet = GetMinNode(pNeedDeleteNode->pRight, pRealDeleteNode);
        assert(bGetMinRet);
        assert(pRealDeleteNode != m_pNil);
        eRealDeleteColor = pRealDeleteNode->eColor;
        pFixUpNode = pRealDeleteNode->pRight;

        //There are two cases to consider
        //case one:
        if (pRealDeleteNode->pParent == pNeedDeleteNode)
        {
            pFixUpNode->pParent = pRealDeleteNode;
        }
        else //case two:
        {
            ReplaceParent(pRealDeleteNode, pRealDeleteNode->pRight);
            pRealDeleteNode->pRight = pNeedDeleteNode->pRight;
            pRealDeleteNode->pRight->pParent = pRealDeleteNode;
        }

        ReplaceParent(pNeedDeleteNode, pRealDeleteNode);
        pRealDeleteNode->pLeft = pNeedDeleteNode->pLeft;
        pRealDeleteNode->pLeft->pParent = pRealDeleteNode;
        pRealDeleteNode->eColor = pNeedDeleteNode->eColor;
    }

    //execute fixed up at point pFixUpNode
    if (E_TREE_BLACK == eRealDeleteColor)
    {
        DeletedFixUp(pFixUpNode);
    }

    if (m_pRoot ==  m_pNil)
    {
        m_pRoot = nullptr;
    }

    delete pNeedDeleteNode; //cleaned up the node which is deleted 
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
    /*
     *      k2                k1
     *        \              /  \
     *         k1           k2   N
     *          \
     *           N
     */           

    PTreeNode k2 = pNode;
    PTreeNode k1 = pNode->pRight;
    k2->pRight = k1->pLeft;  //?
    
    //change the k1 lchild's father node
    if (k1->pLeft)
    {
        k1->pLeft->pParent = k2;
    }
    k1->pLeft = k2;

    //change the k1's father node 
    k1->pParent = pNode->pParent;

    //change the k2's father node 
    k2->pParent = k1;

    //change the k1's father node's lchild and rchild
    pNode = k1;
    newTop = k1;
}

void RBTree::SingleRightRoation(PTreeNode &pNode, PTreeNode &newTop)
{
    /*
     *         k2                k1
     *        /                 /  \
     *      k1                 N    k2
     *     /
     *    N
     */    
        
    PTreeNode k2 = pNode;
    PTreeNode k1 = pNode->pLeft;
    k2->pLeft = k1->pRight;

    //change the k1 rchild's father node 
    if (k1->pRight)
    {
        k1->pRight->pParent = k2;
    }
    k1->pRight = k2;
    k1->pParent = pNode->pParent;
    k2->pParent = k1;
    pNode = k1;
    newTop = k1;
}

void RBTree::ReplaceParent(PTreeNode pBeReplaceNode, PTreeNode pReplaceNode)
{
    //if the pBeReplaceNode is root node
    if (pBeReplaceNode == m_pRoot)
    {
        m_pRoot = pReplaceNode;
    }
    else if (pBeReplaceNode == pBeReplaceNode->pParent->pLeft) //if the pBeReplaceNode is father node's left child
    {
        pBeReplaceNode->pParent->pLeft = pBeReplaceNode;
    }
    else if (pBeReplaceNode == pBeReplaceNode->pParent->pRight) //if the pBeReplaceNode is father node's right child
    {
        pBeReplaceNode->pParent->pRight = pBeReplaceNode;
    }

    //change the father node of pReplaceNode 
    pReplaceNode->pParent = pBeReplaceNode->pParent;
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


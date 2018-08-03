// 
// rbtree.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-22 16:09:35
// 
// @Reb Black Tree 
//  Ref1: https://bbs.pediy.com/thread-225432.html
//  Ref2: http://www.sohu.com/a/201923614_466939
//  Ref3: https://segmentfault.com/a/1190000000472153 
//  Ref4: https://blog.csdn.net/v_JULY_v/article/details/6114226
//
//
// @Nature
//  Roughly,
//  	BST's nature (but there is a flaw, it has line performance)
//  	Auto-banlance
//  	Nodes' color is red or black
//  	Root node's color is black
//  	All leaf nodes' color is black and it's value is NULL
//  	All red nodes' two subnodes' color is black, cannot exisit two continuous red nodes
//  	Any nodes come to it's leaf nodes of path which have same numbers black nodes
//  Specially,
//	1) Every nodes' color are all red or black
//	2) The root's color is black
//	3) Every leaf node(NIL node)'s color is black
//	4) If one node's color is red then it's two childs are all black
//	5) With every node, same black nodes on the path which to it's grandchild node
//
//  @Insert
//	Whatever which red node will be inserted, nature 2) and 4) will be cracked. 
//	Solutions:
//		1) Move up the node which cracked nature then fixed it up
//		2) Enum all possible then integerity it
//		   Case:
//			1) insert node is root
//			2) insert node's father is black
//			3) current node's father is red and it's grandfather's other subchild(uncle node) is red
//			4) current node(rchild)'s father is red and it's uncle node is black,
//			5) current node(lchild)'s father is red and it's uncle node is black,
//  
//  @Delete
//	The suitation of delete same with delete of binary search tree, but we should consider the case of lost banlance of origin rbtree. 
//	Case:
//	     1) No child, a leaf
//	     2) One child, rchild or lchild
//	     3) Two child, rchild and lchild
//
//
// @Fix Up
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
    
    typedef struct __TreeNode { //five fields in every node: color, key, left, right, p
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
const char * RBTree::s_pszColor[E_TREE_COLOR_MAX] = {"Black", "Red"};

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
    if (Empty())
    {
        return;
    }
    queue<PTreeNode> nodeQue;
    nodeQue.push(m_pRoot);

    //the current level of the tree
    int nHeight = 0;
    while (!nodeQue.empty())
    {
        int nCurrentLevelSize = nodeQue.size();
        int nCnt = 0;
        cout << "This is " << nHeight + 1 << "th level.";
        while (nCnt < nCurrentLevelSize)
        {
            PTreeNode accessNode = nodeQue.front();
            nodeQue.pop();
            if (accessNode == m_pRoot)
            {
                cout << accessNode->nValue << "(root, color:" << s_pszColor[accessNode->eColor] << ")" << " ";
            }
            else
            {
                if (accessNode->pParent->pLeft == accessNode)
                {
                    cout << "[(" << accessNode->nValue << "color:" << s_pszColor[accessNode->eColor] << ")" << "(" << accessNode->pParent->nValue << "'s lchild)]" << " ";
                }
                else if (accessNode->pParent->pRight == accessNode)
                {
                    cout << "[(" << accessNode->nValue << "color:" << s_pszColor[accessNode->eColor] << ")" << "(" << accessNode->pParent->nValue << "'s rchild)]" << " ";
                }
            }

            PTreeNode pLeft = accessNode->pLeft;
            PTreeNode pRight= accessNode->pRight;
            if (pLeft != m_pNil)
            {
                nodeQue.push(pLeft);
            }
            if (pRight != m_pNil)
            {
                nodeQue.push(pRight);
            }
            ++nCnt;
        }
        nHeight++;
        cout << endl;
    }
    cout << endl;
}

void RBTree::InsertedFixUp(PTreeNode pInsertNode)
{
    PTreeNode pFixNode = pInsertNode;
    while (E_TREE_RED == pFixNode->pParent->eColor)
    {
        if (pFixNode->pParent == pFixNode->pParent->pParent->pLeft)
        {
            PTreeNode pUncle = pFixNode->pParent->pParent->pRight;
            if (E_TREE_RED == pUncle->eColor)
            {
                pFixNode->pParent->eColor = E_TREE_BLACK;
                pUncle->eColor = E_TREE_BLACK;
                pFixNode->pParent->pParent->eColor = E_TREE_RED;
                pFixNode = pFixNode->pParent->pParent;
            }
            else if (pFixNode == pFixNode->pParent->pRight)
            {
                pFixNode = pFixNode->pParent;
                PTreeNode pNewTop = nullptr;
                SingleLeftRoation(pFixNode->pParent->pLeft, pNewTop);
                pFixNode = pNewTop->pLeft;
            }
            else if (pFixNode == pFixNode->pParent->pLeft)
            {
                pFixNode->pParent->eColor = E_TREE_BLACK;
                pFixNode->pParent->pParent->eColor = E_TREE_RED;
                pFixNode = pFixNode->pParent->pParent;
                PTreeNode pNewTop = nullptr;
                if (m_pRoot == pFixNode)
                {
                    SingleRightRoation(m_pRoot, pNewTop);
                }
                else if (pFixNode == pFixNode->pParent->pLeft)
                {
                    SingleRightRoation(pFixNode->pParent->pLeft, pNewTop);
                }
                else if (pFixNode == pFixNode->pParent->pRight)
                {
                    SingleRightRoation(pFixNode->pParent->pRight, pNewTop);
                }
                pFixNode = pNewTop->pLeft;
            }
        }
        else if (pFixNode->pParent == pFixNode->pParent->pParent->pRight)
        {
            PTreeNode pUncle = pFixNode->pParent->pParent->pLeft;
            if (E_TREE_RED == pUncle->eColor)
            {
                pFixNode->pParent->eColor = E_TREE_BLACK;
                pUncle->eColor = E_TREE_BLACK;
                pFixNode->pParent->pParent->eColor = E_TREE_RED;
                pFixNode = pFixNode->pParent->pParent;
            }
            else if (pFixNode == pFixNode->pParent->pLeft)
            {
                pFixNode = pFixNode->pParent;
                PTreeNode pNewTop = nullptr;
                SingleRightRoation(pFixNode->pParent->pRight, pNewTop);
                pFixNode = pNewTop->pRight;
            }
            else if (pFixNode == pFixNode->pParent->pRight)
            {
                pFixNode->pParent->eColor = E_TREE_BLACK;
                pFixNode->pParent->pParent->eColor = E_TREE_RED;
                pFixNode = pFixNode->pParent->pParent;
                PTreeNode pNewTop = nullptr;
                if (m_pRoot == pFixNode)
                {
                    SingleLeftRoation(m_pRoot, pNewTop);
                }
                else if (pFixNode == pFixNode->pParent->pLeft)
                {
                    SingleLeftRoation(pFixNode->pParent->pLeft, pNewTop);
                }
                else if (pFixNode == pFixNode->pParent->pRight)
                {
                    SingleLeftRoation(pFixNode->pParent->pRight, pNewTop);
                }
                pFixNode = pNewTop->pRight;
            }
        }
    }
    m_pRoot->eColor = E_TREE_BLACK;
}

void RBTree::DeletedFixUp(PTreeNode pFixNode)
{
    while (pFixNode != m_pRoot && E_TREE_BLACK == pFixNode->eColor)
    {
        if (pFixNode == pFixNode->pParent->pLeft)
        {
            PTreeNode pBroNode = pFixNode->pParent->pRight;
            if (E_TREE_RED == pBroNode->eColor)
            {
                pBroNode->eColor = E_TREE_BLACK;
                pFixNode->pParent->eColor = E_TREE_RED;
                PTreeNode pPivot = pFixNode->pParent;
                PTreeNode pNewTop = nullptr;
                PTreeNode pBackParent = pFixNode->pParent;
                if (m_pRoot == pPivot)
                {
                    SingleLeftRoation(m_pRoot, pNewTop);
                }
                else if (pPivot == pPivot->pParent->pLeft)
                {
                    SingleLeftRoation(pPivot->pParent->pLeft, pNewTop);
                }
                else if (pPivot == pPivot->pParent->pRight)
                {
                    SingleLeftRoation(pPivot->pParent->pRight, pNewTop);
                }
                pFixNode->pParent = pBackParent;
            }
            else if (E_TREE_BLACK == pBroNode->pLeft->eColor && E_TREE_BLACK == pBroNode->pRight->eColor)
            {
                pBroNode->eColor = E_TREE_RED;
                pFixNode = pFixNode->pParent;
            }
            else if (E_TREE_RED == pBroNode->pLeft->eColor && E_TREE_BLACK == pBroNode->pRight->eColor)
            {
                ETreeColor eNodeThrColor = pBroNode->pLeft->eColor;
                ETreeColor eNodeBroColor = pBroNode->eColor;
                pBroNode->pLeft->eColor = eNodeBroColor;
                pBroNode->eColor = eNodeThrColor;
                PTreeNode pBackParent = pFixNode->pParent;
                PTreeNode pNewTop = nullptr;
                SingleRightRoation(pBroNode->pParent->pRight, pNewTop);
                pFixNode->pParent = pBackParent;
            }
            else if (E_TREE_RED == pBroNode->pRight->eColor)
            {
                pBroNode->eColor = pFixNode->pParent->eColor;
                pFixNode->pParent->eColor = E_TREE_BLACK;
                pBroNode->pRight->eColor = E_TREE_BLACK;
                PTreeNode pPivot = pFixNode->pParent;
                PTreeNode pNewTop = nullptr;
                if (m_pRoot == pPivot)
                {
                    SingleLeftRoation(pPivot, pNewTop);
                }
                else if (pPivot == pPivot->pParent->pLeft)
                {
                    SingleLeftRoation(pPivot->pParent->pLeft, pNewTop);
                }
                else if (pPivot == pPivot->pParent->pRight)
                {
                    SingleLeftRoation(pPivot->pParent->pRight, pNewTop);
                }
                pFixNode = m_pRoot;
            }
        }
        else if (pFixNode == pFixNode->pParent->pRight)
        {
            PTreeNode pBroNode = pFixNode->pParent->pLeft;
            if (E_TREE_RED == pBroNode->eColor)
            {
                pBroNode->eColor = E_TREE_BLACK;
                pFixNode->pParent->eColor = E_TREE_RED;
                PTreeNode pPivot = pFixNode->pParent;
                PTreeNode pNewTop = nullptr;
                PTreeNode pBackParent = pFixNode->pParent;
                if (m_pRoot == pPivot)
                {
                    SingleRightRoation(m_pRoot, pNewTop);
                }
                else if (pPivot == pPivot->pParent->pLeft)
                {
                    SingleRightRoation(pPivot->pParent->pLeft, pNewTop);
                }
                else if (pPivot == pPivot->pParent->pRight)
                {
                    SingleRightRoation(pPivot->pParent->pRight, pNewTop);
                }
                pFixNode->pParent = pBackParent;
            }
            else if (E_TREE_BLACK == pBroNode->pLeft->eColor && E_TREE_BLACK == pBroNode->pRight->eColor)
            {
                pBroNode->eColor = E_TREE_RED;
                pFixNode = pFixNode->pParent;
            }
            else if (E_TREE_BLACK == pBroNode->pLeft->eColor && E_TREE_RED == pBroNode->pRight->eColor)
            {
                ETreeColor eNodeThrColor = pBroNode->pRight->eColor;
                ETreeColor eNodeBroColor = pBroNode->eColor;
                pBroNode->pRight->eColor = eNodeBroColor;
                pBroNode->eColor = eNodeThrColor;
                PTreeNode pBackParent = pFixNode->pParent;
                PTreeNode pNewTop = nullptr;
                SingleLeftRoation(pBroNode->pParent->pLeft, pNewTop);
                pFixNode->pParent = pBackParent;
            }
            else if (E_TREE_RED == pBroNode->pLeft->eColor)
            {
                pBroNode->eColor = pFixNode->pParent->eColor;
                pFixNode->pParent->eColor = E_TREE_BLACK;
                pBroNode->pLeft->eColor = E_TREE_BLACK;
                PTreeNode pPivot = pFixNode->pParent;
                PTreeNode pNewTop = nullptr;
                if (m_pRoot == pPivot)
                {
                    SingleRightRoation(pPivot, pNewTop);
                }
                else if (pPivot == pPivot->pParent->pLeft)
                {
                    SingleRightRoation(pPivot->pParent->pLeft, pNewTop);
                }
                else if (pPivot == pPivot->pParent->pRight)
                {
                    SingleRightRoation(pPivot->pParent->pRight, pNewTop);
                }
                pFixNode = m_pRoot;
            }
        }
    }
    pFixNode->eColor = E_TREE_BLACK;
}

// With roation of tree, the nature for search doesn't changed, but not the red or black of tree. 
// Some cases of double roation of tree just the applys of single roation, without news.
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
int main(int argc, char* argv[])
{
    RBTree rbtree;

    //Insert 
    int nArrayInsertValue[] = {12, 1, 9, 2, 0, 11, 7, 19, 4, 15, 1, 8, 5, 14, 13, 10, 16, 6, 3, 8, 17};
    for (int i = 0; i < sizeof(nArrayInsertValue) / sizeof(nArrayInsertValue[0]); i++)
    {
        rbtree.InsertData(nArrayInsertValue[i]);
    }

    //BFS
    rbtree.BFS();
    cout << endl;

    //Delete
    for (int i = 0; i < sizeof(nArrayInsertValue)/sizeof(nArrayInsertValue[0]); i++)
    {
        cout << "After deleted " << nArrayInsertValue[i] << "'th node" << endl;
        rbtree.DeleteElement(nArrayInsertValue[i]);
        rbtree.BFS();
    }

    //Insert any seq
    cout << "Insert any sequence..." << endl;
    for (int i = 0; i < 50; i++)
    {
        rbtree.InsertData(i);
    }

    //Find node 3
    cout << "Find the node 3..." << endl;
    cout << "Result: " << rbtree.FindElement(3) << endl;

    rbtree.BFS();
    cout << endl;

    //Delete any seq just save three
    for (int i = 49; i >= 3; i--)
    {
        rbtree.DeleteElement(i);
    }

    rbtree.BFS();
    cout << endl;

    return 0;
}


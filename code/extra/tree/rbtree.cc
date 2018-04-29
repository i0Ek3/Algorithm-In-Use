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
RBTree::RBTree() {}
RBTree::~RBTree() {}

void RBTree::InsertData(int nValue)
{

}

bool RBTree::Empty()
{

}

bool RBTree::GetMax(PTreeNode pNode, int &nMax)
{

}

bool RBTree::GetMin(PTreeNode pNode, int &nMin)
{

}

void RBTree::DeleteElement(int nDelete)
{

}

bool RBTree::FindElement(int nFindValue)
{

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

}


//Test
int main()
{


    return 0;
}


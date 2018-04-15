// 
// treeTraverse.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-15 08:27:25
//
// The static traverse for tree.
//
// @Less nodes recommend
// 
//      struct node {
//         typename data;
//         int child[maxn];
//      }Node[maxn];
//
//
// @Huge nodes recommend
// 
//      struct node {
//         typename data;
//         vector<int> child;
//      }Node[maxn];
// 
//
// @Create a new node
// 
//      int index = 0;
//      int createNewNode(int v)
//      {
//          Node[index].data = v;
//          Node[index].child.clear(); //clear leaf nodes
//          return index++;
//      }
//
//
// @PreOrder for tree
//  
//      void PreOrder(int root)
//      {
//          printf("%d ", Node[root].data);
//          for (int i = 0; i < Node[root].child.size(); i++)
//          {
//              PreOrder(Node[root].child[i]);
//          }
//      }
//
//
// @LayerOrder for tree with layer number
//
//      struct node {
//          int layer;
//          int data;
//          vector<int> child;
//      }Node[maxn];
//
//      void LayerOrder(int root)
//      {
//          queue<int> q;
//          q.push(root);
//          Node[root].layer = 0;
//          while (!q.empty())
//          {
//              int front = q.front();
//              printf("%d ", Node[front].data);
//              q.pop();
//              for (int i = 0; i < Node[front].child.size(); i++)
//              {
//                  int child = Node[front].child[i];
//                  Node[child].layer = Node[front].layer + 1;
//                  q.push(Node[front].child[i]);
//              }
//          }
//      }
//
//
//
//

#include <cstdio>
#include <queue>
using namespace std;


int main()
{



    return 0;
}






// 
// heap.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-22 16:35:03
//
// @Heap
//  Basic operation
//
//  Big-top-heap
//  Small-top-heap
//
//

#include <cstdio> 
#include <algorithm>
using namespace std;


//define heap with array
const int maxn = 110;
int heap[maxn], n = 100;


//downAdjust
//low: pre-adjust node index
//high: the last one node index 
void downAdjust(int low, int high)
{
    int i = low, j = i*2; //i is pre-adjust node, j is it's lchild
    while (j <= high)
    {
        if (j + 1 <= high && heap[j + 1] > heap[j])
        {
            j += 1;
        }
        if (heap[j] > heap[i])
        {
            swap(heap[j], heap[i]);
            i = j;
            j = i*2;
        }
        else
        {
            break;
        }
    }
}

void createHeap()
{
    for (int i = n / 2; i >= 1; i--)
    {
        downAdjust(i, n);
    }
}

void deleteTop()
{
    heap[1] = heap[n--];
    downAdjust(1, n);
}

//upAdjust
//low = 1, high is pre-adjust node index
void upAdjust(int low, int high)
{
    int i = high, j = i / 2; //i is pre-adjust node, j is it's father node
    while (j >= low) // j is range in [low, high]
    {
        if (heap[j] < heap[i])
        {
            swap(heap[j], heap[i]);
            i = j;
            j = i / 2;
        }
        else
        {
            break;
        }
    }
}

void addElement(int x)
{
    heap[++n] = x;
    upAdjust(1, n);
}


int main()
{


    return 0;
}




// 
// pat_a1034.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-25 10:13:48
// 
//
// @Head of a Gang
//  Maybe later, I don't know what talking about of this question.Let me try later...
//
// 
 
#include <iostream>
#include <string>
#include <map>
#include <iterator>

const int maxn = 2001;
const int INF = 0x3fffffff;

std::map<int, std::string> intToString; //id -> name 
std::map<std::string, int> stringToInt; //name -> id 
std::map<std::string, int> Gang; // head -> number of person 

int G[maxn][maxn] = {0}; //adjacent matrix 
int weight[maxn] = {0}; //weight of point 
int n, k, numPerson = 0; 
bool visit[maxn] = {false};

void DFS(int nowVisit, int &head, int &numMember, int &totalValue)
{
    numMember++;
    visit[nowVisit] = true;
    if (weight[nowVisit] > weight[head])
    {
        head = nowVisit; //update head 
    }
    for (int i = 0; i < numPerson; i++)
    {
        if (G[nowVisit][i] > 0)
        {
            totalValue += G[nowVisit][i]; //add weight of line 
            G[nowVisit][i] = G[i][nowVisit] = 0; //delete that line avoid to recount 
            if (visit[i] == false)
            {
                DFS(i, head, numMember, totalValue);
            }
        }
    }
}

void DFSTrave()
{
    for (int i = 0; i < numPerson; i++)
    {
        if (visit[i] == false)
        {
            int head = i, numMember = 0, totalValue = 0;
            DFS(i, head, numMember, totalValue);
            if (numMember > 2 && totalValue > k)
            {
                Gang[intToString[head]] = numMember;
            }
        }
    }
}

int change(std::string str)
{
    if (stringToInt.find(str) != stringToInt.end())
    {
        return stringToInt[str];
    }
    else
    {
        stringToInt[str] = numPerson;
        intToString[numPerson] = str;
        return numPerson;
    }
}

int main()
{
    int w;
    std::string str1, str2;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    DFSTrave();
    std::cout << Gang.size() << std::endl;
    std::map<std::string, int>::iterator it;
    for (it = Gang.begin(); it != Gang.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
    return 0;
}


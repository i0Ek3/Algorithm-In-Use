#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>
#define N 100

int main()
{
        char str[N];
        gets(str);
        std::string a = str;
        for (int i = 0; i < a.size(); i++) {
                a[i] = tolower(a[i]);
        }
        while (gets(str)) {
                std::string b = str, c = b; 
                for (int i = 0; i < b.size(); i++) {
                        b[i] = tolower(b[i]);
                }
                int tmp = b.find(a, 0);
                while (tmp != std::string::npos) {
                        c.erase(tmp, a.size());
                        b.erase(tmp, a.size());
                        tmp = b.find(a, tmp);
                }
                tmp = c.find(' ', 0);
                while (tmp != std::string::npos) {
                        c.erase(tmp, 1);
                        tmp = c.find(' ', 0);
                }
                std::cout << c << std::endl;
        }
        
        return 0;
}


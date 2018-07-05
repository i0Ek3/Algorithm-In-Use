#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using std::cin;

typedef long long LL;
const LL MOD = 1e9 + 7;
const LL P = 1e7 + 19;
const LL MAXN = 200010;
LL powP[MAXN], H1[MAXN], H2[MAXN];

void init()
{
    powP[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        powP[i] = (powP[i-1] * P) % MOD;
    }
}

void calHash(LL H[], std::string &str)
{
    H[0] = str[0];
	for (int i = 1; i < str.length(); i++) {
		H[i] = 	(H[i-1] * P + str[i]) % MOD;
	}
}

int calSingleSubHash(LL H[], int i, int j)
{
	if (i == 0) {
		return H[j];
	}
	return ((H[j] - H[i-1] * powP[j - i + 1]) % MOD + MOD) % MOD;
}

int binarySearch(int l, int r, int len, int i, int isEven)
{
    while (l < r) {
		int mid = (l + r) / 2;
		int H1L = i - mid + isEven, H1R = i;
		int H2L = len - 1 - (i + mid), H2R = len - 1 - (i + isEven);
		int hashL = calSingleSubHash(H1, H1L, H1R);
		int hashR = calSingleSubHash(H2, H2L, H2R);
		if (hashL != hashR) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l - i;
}

int main()
{
	init();
	std::string str;
	getline(cin, str);
	calHash(H1, str);
	reverse(str.begin(), str.end());
	calHash(H2, str);
	int ans = 0;

	for (int i = 0; i < str.length(); i++) {
		int maxLen = std::min(i, (int)str.length() - 1 - i) + 1;
		int k = binarySearch(0, maxLen, str.length(), i, 0);
		ans = std::max(ans, k * 2 + 1);
	}

	for (int i = 0; i < str.length(); i++) {
		int maxLen = std::min(i+1, (int)str.length() - 1 - i) + 1;
		int k = binarySearch(0, maxLen, str.length(), i, 1);
		ans = std::max(ans, k * 2);
	}
	printf("%d\n", ans);

    return 0;
}

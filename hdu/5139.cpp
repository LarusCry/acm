/*****************************************************
  > File Name: 5139.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年12月06日 星期六 22时01分22秒
*****************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <bitset>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <utility>
#include <limits>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define PQ priority_queue
#define MOD 1000000007L

inline int readInt()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

int FASTBUFFER;
int n;
long long ans[(int)1e5 + 5];
pair<long long, int> in[(int)1e5 + 5];

int main()
{
    ios::sync_with_stdio(false);
    int tot = 0;
    while (cin >> n) {
        in[tot] = make_pair(n, tot);
        ++tot;
    }
    sort(in, in + tot);
    long long start = 1, fact = 1, now = 1;
    for (int i = 0; i < tot; ++i) {
        while (start < in[i].first) {
            fact = fact * (++start) % MOD;
            now = now * fact % MOD;
        }
        ans[in[i].second] = now;
    }
    for (int i = 0; i < tot; ++i)
        cout << ans[i] << endl;
    return 0;
}

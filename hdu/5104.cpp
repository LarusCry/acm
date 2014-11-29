/*****************************************************
  > File Name: a.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年11月15日 星期六 21时49分39秒
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

inline int readInt()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

int FASTBUFFER;
int prim[10005], pos[10005], tot = 0;
int n;

void pre()
{
    pos[1] = 1;
    for (int i = 2; i <= 10000; ++i) {
        if (pos[i])
            continue;
        prim[++tot] = i;
        for (int j = i << 1; j <= 10000; j += i) {
            pos[j] = 1;
        }
    }
}

void work()
{
    long long ans = 0;
    for (int i = 1; i <= tot; ++i) {
        for (int j = i; j <= tot; ++j) {
            if (prim[i] + prim[j] > n)
                continue;
            if (pos[n - prim[i] - prim[j]])
                continue;
            if (n - prim[i] - prim[j] >= prim[j])
                ++ans;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    pre();
    while (cin >> n) {
        work();
    }
    return 0;
}

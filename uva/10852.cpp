/*****************************************************
  > File Name: 10852.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年12月07日 星期日 22时21分40秒
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
int m, n, a[405], v[405], ans[405];

bool check(int x, int *b)
{
    memset(a, 0, sizeof(a));
    int t = 0;
    for (int i = m - 1; i >= 0; --i) {
        t = t + x * b[i];
        int k = t % n;
        a[k]++;
        t = t / n;
        if (a[k] > v[k])
            return false;
    }
    return t == 0;
}

bool judge(int x)
{
    memset(v, 0, sizeof(v));
    int t = 0;
    for (int i = 0; i < m; ++i) {
        t = (x + t) % n;
        ans[i] = t;
        v[t]++;
    }
    swap(ans[0], ans[m - 1]);
    sort(ans, ans + m - 1);
    do {
        bool flag = true;
        if (ans[0] == 0)
            continue;
        for (int i = 2; i <= m; ++i) {
            if (check(i, ans))
                continue;
            flag = false;
            break;
        }
        if (flag)
            return true;
    } while (next_permutation(ans, ans + m - 1));
    return false;
}

void work()
{
    bool good = false;
    for (int i = 1; i < n; ++i) {
        if (judge(i)) {
            good = true;
            break;
        }
    }
    if (!good)
        printf("Not found.\n");
    else {
        printf("%d", ans[0]);
        for (int i = 1; i < m; ++i)
            printf(" %d", ans[i]);
        printf("\n");
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    while (~scanf("%d %d", &m, &n) && (m + n)) {
        work();
    }
    return 0;
}

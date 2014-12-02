/*****************************************************
  > File Name: B.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年12月02日 星期二 00时38分59秒
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
int n, tot;
int len;
double a[10005];
double b[10005];
map<int, int> m;

inline bool check(double x)
{
    if (b[tot - 1] + x < len)
        return false;
    double pre = 0.0;
    for (int i = 0; i < tot; ++i) {
        if (b[i] - x > pre) {
            return false;
        }
        else {
            pre = b[i] + x;
        }
    }
    return true;
}

void work()
{
    m.clear();
    tot = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        t = readInt();
        if (m.find(t) == m.end()) {
            b[tot++] = t;
            m[t] = 1;
        }
    }
    sort(b, b + tot);
    double l = 0.0, r = len + 1;
    while (r - l > 1e-9) {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    printf("%.9lf\n", l);
}

int main()
{
    //ios::sync_with_stdio(false);
    while (~scanf("%d%d", &n, &len)) {
        work();
    }
    return 0;
}

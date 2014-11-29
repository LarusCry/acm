/*****************************************************
  > File Name: 4850.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年11月29日 星期六 23时17分02秒
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
int n, pos;

struct node {
    int s, d;
    bool operator < (const node &a)const {
        return d < a.d;
    }
};

node in[505];

int solve(int x)
{
    int time = 0, mx1 = 0, mx2 = 0;
    for (int i = 0; i <= pos; ++i) {
        if (i == x)
            continue;
        time += in[i].s;
        int t = max(time - in[i].d, 0);
        if (mx1 < t) {
            mx2 = mx1;
            mx1 = t;
        }
        else if (mx2 < t) {
            mx2 = t;
        }
    }
    time += in[x].s;
    int t = max(time - in[x].d, 0);
    if (mx1 < t) {
        mx2 = mx1;
        mx1 = t;
    }
    else if (mx2 < t) {
        mx2 = t;
    }
    return mx1 + mx2;
}
void work()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> in[i].s >> in[i].d;
    }
    sort(in, in + n);
    int time = 0, mx1 = 0, mx2 = 0;
    pos = 0;

    for (int i = 0; i < n; ++i) {
        time += in[i].s;
        int t = max(time - in[i].d, 0);
        if (mx1 < t) {
            mx2 = mx1;
            mx1 = t;
            pos = i;
        }
        else if (mx2 < t) {
            mx2 = t;
            pos = i;
        }
    }
    int ans = mx1 + mx2;
    for (int i = 0; i < pos; ++i) {
        ans = min(ans, solve(i));
    }
    cout << ans << endl;
}

int main()
{
    //ios::sync_with_stdio(false);
    int test; cin >> test;
    while (test--) {
        work();
    }
    return 0;
}

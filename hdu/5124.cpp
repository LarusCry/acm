/*****************************************************
  > File Name: B2.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年11月29日 星期六 21时27分10秒
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
vector<pair<int, int> > v;
int n;

void work()
{
    v.clear();
    n = readInt();
    for (int i = 0; i < n; ++i) {
        int x, y;
        x = readInt(); y = readInt();
        v.push_back(make_pair(x, 1));
        v.push_back(make_pair(y + 1, -1));
    }
    sort(v.begin(), v.end());
    int ans = -1, sum = 0;
    for (int i = 0; i < n + n; ++i) {
        sum += v[i].second;
        ans = Max(ans, sum);
    }
    printf("%d\n", ans);
}

int main()
{
    //ios::sync_with_stdio(false);
    int test; test = readInt();
    while (test--) {
        work();
    }
    return 0;
}

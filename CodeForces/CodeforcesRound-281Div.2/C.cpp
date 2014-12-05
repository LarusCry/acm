/*****************************************************
  > File Name: C.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年12月04日 星期四 14时37分56秒
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
int n1, n2;
typedef pair<int, int> pii;
vector<pii> v;

void work()
{
    for (int i = 0; i < n1; ++i) {
        int x;
        x = readInt();
        v.push_back(make_pair(x, 0));
    }
    n2 = readInt();
    for (int i = 0; i < n2; ++i) {
        int x;
        x = readInt();
        v.push_back(make_pair(x, 1));
    }
    sort(v.begin(), v.end());
    int pnt1 = 3 * n1, pnt2 = 3 * n2;
    int ans1 = pnt1, ans2 = pnt2;
    int i = 0;
    while (i < (int)v.size()) {
        int j = i;
        while (i < (int)v.size() && v[i].first == v[j].first) {
            if (v[i].second == 1)
                --pnt2;
            else
                --pnt1;
            ++i;
        }
        if (pii(ans1 - ans2, ans1) < pii(pnt1 - pnt2, pnt1)) {
            ans1 = pnt1;
            ans2 = pnt2;
        }
    }
    cout << ans1 << ":" << ans2 << endl;
}

int main()
{
    //ios::sync_with_stdio(false);
    while (~scanf("%d", &n1)) {
        work();
    }
    return 0;
}

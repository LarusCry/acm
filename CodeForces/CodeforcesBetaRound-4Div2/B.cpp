/*****************************************************
  > File Name: B.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年12月01日 星期一 09时35分38秒
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
int n, sumtime, a[55];
pair<int, int> in[55];

void work()
{
    memset(a, 0, sizeof(a));
    int mi, mx;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> mi >> mx;
        in[i] = make_pair(mi, mx);
        sum += mi;
    }
    if (sum > sumtime) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        sumtime -= in[i].first;
        a[i] = in[i].first;
    }
    for (int i = 0; i < n; ++i) {
        int t = min(sumtime, in[i].second - in[i].first);
        a[i] += t;
        sumtime -= t;
    }
    if (sumtime > 0) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    //ios::sync_with_stdio(false);
    while (cin >> n >> sumtime) {
        work();
    }
    return 0;
}

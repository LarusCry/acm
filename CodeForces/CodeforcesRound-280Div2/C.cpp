/*****************************************************
  > File Name: C.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年12月02日 星期二 08时27分11秒
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
long long n, r, avg;
pair<long, long> in[(int)1e5 + 5];

void work()
{
    long long a, b, sum = 0, tot = avg * n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        sum += a;
        in[i] = (make_pair(b, a));
    }
    if (sum >= tot) {
        cout << "0\n";
        return;
    }
    sort(in, in + n);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long ret = tot - sum;
        long long t = min(r - in[i].second, ret);
        sum += t;
        ans += t * in[i].first;
    }
    cout << ans << endl;
}

int main()
{
    //ios::sync_with_stdio(false);
    while (cin >> n >> r >> avg) {
        work();
    }
    return 0;
}

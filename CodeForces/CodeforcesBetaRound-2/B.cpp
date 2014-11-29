/*****************************************************
  > File Name: B.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年11月29日 星期六 17时51分59秒
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
int n, in[1005][1005], p[2] = {2, 5};
int dp[1005][1005], next[1005][1005];

int cnt(int a, int k)
{
    int ret = 0;
    while (a % k == 0) {
        ++ret;
        a /= k;
    }
    return ret;
}

void work()
{
    int zx = -1, zy = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            in[i][j] = readInt();
            if (in[i][j] == 0) {
                in[i][j] = 10;
                zx = i; zy = j;
            }
        }
    }
    int mi = (int)1e10;
    string ans;
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < n; ++i) {
            dp[n][i] = dp[i][n] = (int)1e10;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i < n - 1 || j < n - 1) {
                    if (dp[i][j + 1] <= dp[i + 1][j]) {
                        next[i][j] = 'R';
                        dp[i][j] = dp[i][j + 1];
                    }
                    else {
                        next[i][j] = 'D';
                        dp[i][j] = dp[i + 1][j];
                    }
                }
                else {
                    dp[i][j] = 0;
                }
                dp[i][j] += cnt(in[i][j], p[k]);
            }
        }
        if (dp[0][0] < mi) {
            mi = dp[0][0];
            ans.clear();
            int x = 0, y = 0;
            while (x < n - 1 || y < n - 1) {
                ans += next[x][y];
                if (next[x][y] == 'R')
                    ++y;
                else
                    ++x;
            }
        }
    }
        if (mi > 1 && zx != -1) {
            mi = 1;
            ans.clear();
            for (int i = 0; i < zy; ++i) ans += 'R';
            for (int i = 0; i < zx; ++i) ans += 'D';
            for (int i = zy; i < n - 1; ++i) ans += 'R';
            for (int i = zx; i < n - 1; ++i) ans += 'D';
        }
        printf("%d\n%s\n", mi, ans.c_str());
}

int main()
{
    //ios::sync_with_stdio(false);
    while (~scanf("%d", &n)) {
        work();
    }
    return 0;
}

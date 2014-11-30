/*****************************************************
  > File Name: 3266.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年11月30日 星期日 10时19分39秒
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
int n, a[1005], b[1005];

void work()
{
    for (int i = 0; i < n; ++i)
        a[i] = readInt();
    for (int i = 0; i < n; ++i)
        b[i] = readInt();

    sort(a, a + n, greater<int>());
    sort(b, b + n, greater<int>());

    int ans = 0;
    int first_t = 0, first_q = 0, last_t = n - 1, last_q = n - 1;
    for (int k = 0; k < n; ++k) {
        if (a[first_t] > b[first_q]) {
            ans += 200;
            ++first_t; ++first_q;
        }
        else if (a[first_t] < b[first_q]) {
            ans -= 200;
            ++first_q; --last_t;
        }
        else if (a[first_t] == b[first_q]) {
            if (a[last_t] > b[last_q]) {
                ans += 200;
                --last_t; --last_q;
            }
            else if (a[last_t] < b[last_q]) {
                ans -= 200;
                ++first_q; --last_t;
            }
            else if (a[last_t] == b[last_q]) {
                if (a[last_t] < b[first_q]) {
                    ans -= 200;
                }
                else if (a[last_t] > b[first_q]) {
                    ans += 200;
                }
                else
                    ans += 0;
                --last_t; ++first_q;
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    //ios::sync_with_stdio(false);
    while (1) {
        n = readInt();
        if (n)
            work();
        else
            break;
    }
    return 0;
}

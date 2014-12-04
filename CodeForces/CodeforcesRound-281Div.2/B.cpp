/*****************************************************
  > File Name: A1.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年12月03日 星期三 23时00分05秒
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
int n;
int a[200005], b[200005];
int tot1 = 0, tot2 = 0;

bool check1()
{
    bool good = false, f = true;
    if (tot1 <= tot2)
        return false;
    for (int i = 0; i < tot2; ++i) {
        if (a[i] != b[i])
            f = false;
    }
    return f;
}
bool check2()
{
    bool good = false, f = true;
    if (tot2 <= tot1)
        return false;
    for (int i = 0; i < tot1; ++i) {
        if (a[i] != b[i])
            f = false;
    }
    return f;
}

bool do1()
{
    for (int i = 0; i < tot1 && i < tot2; ++i) {
        if (i == 0) {
            if (a[i] > b[i]) {
                return true;
            }
            else if (a[i] < b[i])
                return false;
        }
        else if (a[i] > b[i] && (a[i - 1] == b[i - 1]))
            return true;
    }
    return false;
}
bool do2()
{
    for (int i = 0; i < tot1 && i < tot2; ++i) {
        if (i == 0) {
            if (b[i] > a[i]) {
                return true;
            }
            else if (b[i] < a[i])
                return false;
        }
        else if (b[i] > a[i] && (a[i - 1] == b[i - 1]))
            return true;
    }
    return false;
}


void work()
{
    long long sum1 = 0, sum2 = 0;
    long long x, xx;
    string s1, s2;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (i == n - 1)
            xx = x;
        if (x > 0)
            sum1 += x, a[tot1++] = x;
        else
            sum2 -= x, b[tot2++] = (-x);
    }
    if (sum1 > sum2)
        cout << "first\n";
    else if (sum1 < sum2)
        cout << "second\n";
    else if (sum1 == sum2) {
        if (check1() || do1()) {
            cout << "first\n";
            return;
        }
        else if (check2() || do2()) {
            cout << "second\n";
            return;
        }
        else {
            if (xx > 0)
                cout << "first\n";
            else
                cout << "second\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n) {
        work();
    }
    return 0;
}

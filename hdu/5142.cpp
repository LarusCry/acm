/*****************************************************
  > File Name: t.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年12月13日 星期六 22时11分29秒
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

string int2string(int x)
{
    string ret;
    while (x) {
        int t = x % 2;
        ret += t + '0';
        x /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

void work()
{
    string t = int2string(n);
    int sum = 0;
    for (int i = 0; i < int(t.size()); ++i) {
        sum += (t[i] - '0') * pow(2.0, i * 1.0);
    }
    cout << sum << endl;
}

int main()
{
    //ios::sync_with_stdio(false);
    int test; cin >> test;
    while (cin >> n) {
        work();
    }
    return 0;
}

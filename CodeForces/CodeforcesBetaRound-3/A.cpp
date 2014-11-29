/*****************************************************
  > File Name: A.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年11月29日 星期六 18时53分42秒
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
string from, to;

void work()
{
    int difx = abs(to[1] - from[1]), dify = abs(to[0] - from[0]);
    int commen = min(difx, dify);
    int d = abs(difx - dify);

    int ans = commen + d;

    cout << ans << endl;

    for (int i = 0; i < commen; ++i) {
        if (from[1] <= to[1] && from[0] >= to[0])
            cout << "LU\n";
        else if (from[1] <= to[1] && from[0] <= to[0])
            cout << "RU\n";
        else if (from[1] >= to[1] && from[0] >= to[0])
            cout << "LD\n";
        else if (from[1] >= to[1] && from[0] <= to[0])
            cout << "RD\n";
    }


    for (int i = 0; i < d; ++i) {
        if (difx > dify) {
            if (from[1] < to[1])
                cout << "U\n";
            else
                cout << "D\n";
        }
        else {
            if (from[0] < to[0])
                cout << "R\n";
            else
                cout << "L\n";
        }
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    while (cin >> from >> to) {
        work();
    }
    return 0;
}

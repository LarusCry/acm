/*****************************************************
  > File Name: C.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年11月30日 星期日 11时17分47秒
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
int count_X, count_0, count_d;
string s[5];
bool illegal = false, first_win = false, second_win = false, draw = false;
bool first = false, second = false;

void pre()
{
    count_X = count_0 = 0, count_d = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < (int)s[i].size(); ++j) {
            if (s[i][j] == 'X') {
                ++count_X;
            }
            if (s[i][j] == '0') {
                ++count_0;
            }
            if (s[i][j] == '.') {
                ++count_d;
            }
        }
    }
}

bool ifIllegal()
{
    if (count_0 > count_X || count_X - count_0 > 1)
        return true;
    return false;
}

bool ifFirst()
{
    if (count_X == count_0 && count_X + count_0 < 9)
        return true;
    return false;
}

bool ifSecond()
{
    if (count_0 < count_X && count_X + count_0 < 9)
        return true;
    return false;
}

bool ifFirstWin()
{
    bool good = false;
    for (int i = 0; i < 3; ++i) {
        int cnt = 0;
        for (int j = 0; j < 3; ++j) {
            if (s[i][j] == 'X')
                ++cnt;
        }
        if (cnt == 3)
            good = true;
    }
    for (int j = 0; j < 3; ++j) {
        int cnt = 0;
        for (int i = 0; i < 3; ++i) {
            if (s[i][j] == 'X')
                ++cnt;
        }
        if (cnt == 3)
            good = true;
    }
    if (s[0][0] == 'X' && s[1][1] == 'X' && s[2][2] == 'X')
        good = true;
    if (s[0][2] == 'X' && s[1][1] == 'X' && s[2][0] == 'X')
        good = true;
    return good;
}

bool ifSecondWin()
{
    bool good = false;
    for (int i = 0; i < 3; ++i) {
        int cnt = 0;
        for (int j = 0; j < 3; ++j) {
            if (s[i][j] == '0')
                ++cnt;
        }
        if (cnt == 3)
            good = true;
    }
    for (int j = 0; j < 3; ++j) {
        int cnt = 0;
        for (int i = 0; i < 3; ++i) {
            if (s[i][j] == '0')
                ++cnt;
        }
        if (cnt == 3)
            good = true;
    }
    if (s[0][0] == '0' && s[1][1] == '0' && s[2][2] == '0')
        good = true;
    if (s[0][2] == '0' && s[1][1] == '0' && s[2][0] == '0')
        good = true;
    return good;
}

bool ifDraw()
{
    if (count_d == 0 && !first_win && !second_win)
        return true;
    return false;
}

void work()
{
    illegal = false, first_win = false, second_win = false, draw = false;
    first = false, second = false;
    pre();
    illegal = ifIllegal();
    first = ifFirst();
    second = ifSecond();
    first_win = ifFirstWin();
    second_win = ifSecondWin();
    draw = ifDraw();

    if (illegal || (first_win && second_win) || (second_win && count_X > count_0) || (first_win && count_0 == count_X)) {
        cout << "illegal\n";
        return;
    }
    if (first_win) {
        cout << "the first player won\n";
        return;
    }
    if (second_win) {
        cout << "the second player won\n";
        return;
    }
    if (draw) {
        cout << "draw\n";
        return;
    }
    if (first) {
        cout << "first\n";
        return;
    }
    if (second) {
        cout << "second\n";
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> s[0] >> s[1] >> s[2]) {
        work();
    }
    return 0;
}

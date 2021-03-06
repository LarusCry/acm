/*****************************************************
  > File Name: B.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年11月29日 星期六 10时34分26秒
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
int r, c;
char s[20], *p;

void print(int x)
{
    if (x--) {
        print(x / 26);
        putchar((x % 26) + 'A');
    }
}

void work()
{
    scanf("%s", s);
    if (sscanf(s, "R%dC%d", &r, &c) == 2) {
        print(c);
        printf("%d\n", r);
    }
    else {
        for (c = 0, p = s; *p >= 'A'; ++p) {
            c = c * 26 + (*p^64);
        }
        printf("R%sC%d\n", p, c);
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    int test; scanf("%d", &test);
    while (test--) {
        work();
    }
    return 0;
}

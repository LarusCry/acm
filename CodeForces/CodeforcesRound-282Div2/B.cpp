/*****************************************************
  > File Name: B.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年12月14日 星期日 11时12分44秒
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
int a, b;


void work()
{
    if (a == b) {
        cout << "infinity\n";
        return;
    }
    if (a < b) {
        cout << "0\n";
        return;
    }
    int x = a - b, count = 0;
    for (int i = 1; i <= floor(sqrt(x)); ++i) {
        if (x % i == 0) {
            int y = x / i;
            if (i > b)
                ++count;
            if (y != i && y > b)
                ++count;
        }
    }
    cout << count << endl;
}

int main()
{
    //ios::sync_with_stdio(false);
    while (cin >> a >> b) {
        work();
    }
    return 0;
}

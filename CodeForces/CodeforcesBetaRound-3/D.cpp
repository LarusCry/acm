/*****************************************************
  > File Name: D.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年11月30日 星期日 18时41分51秒
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
pair<int, int> p;
PQ<pair<int, int> >pq;
string s;

void work()
{
    int c = 0, t1, t2;
    long long ans = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '(') {
            ++c;
        }
        else if (s[i] == ')') {
            --c;
        }
        else {
            --c;
            s[i] = ')';
            t1 = readInt(); t2 = readInt();
            pq.push(make_pair(t2 - t1, i));
            ans += t2;
        }
        if (c < 0) {
            if (pq.empty())
                break;
            p = pq.top();
            pq.pop();
            c += 2;
            s[p.second] = '(';
            ans -= p.first;
        }
    }
    if (c != 0) {
        printf("-1\n");
    }
    else {
        cout << ans << endl;
        cout << s << endl;
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    while (cin >> s && !isdigit(s[0])) {
        work();
    }
    return 0;
}

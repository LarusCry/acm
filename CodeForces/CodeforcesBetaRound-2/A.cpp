/*****************************************************
  > File Name: A.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年11月29日 星期六 14时27分29秒
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
pair<string, int> _p[1005];
map<string, int> score, cur;

void work()
{
    score.clear();
    string name; int sco;
    for (int i = 0; i < n; ++i) {
        cin >> name >> sco;
        _p[i] = make_pair(name, sco);
        score[name] += sco;
    }

    int max_score = 0;

    for (map<string, int>::iterator it = score.begin(); it != score.end(); ++it) {
        max_score = max(max_score, it->second);
    }

    cur.clear();
    for (int i = 0; i < n; ++i) {
        cur[_p[i].first] += _p[i].second;
        if (cur[_p[i].first] >= max_score && score[_p[i].first] == max_score) {
            cout << _p[i].first << endl;
            return;
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

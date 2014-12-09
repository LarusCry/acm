/*****************************************************
  > File Name: 11995.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年12月09日 星期二 22时13分47秒
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
#include <stack>
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
queue<int> q;
PQ<int, vector<int>, less<int> > pq;
stack<int> st;
pair<int, int> in[1005];

bool isQueue()
{
    for (int i = 0; i < n; ++i) {
        if (in[i].first == 1) {
            q.push(in[i].second);
        }
        else {
            if (q.empty())
                return false;
            if (q.front() != in[i].second)
                return false;
            q.pop();
        }
    }
    return true;
}

bool isPQ()
{
    for (int i = 0; i < n; ++i) {
        if (in[i].first == 1) {
            pq.push(in[i].second);
        }
        else {
            if (pq.empty())
                return false;
            if (pq.top() != in[i].second)
                return false;
            pq.pop();
        }
    }
    return true;
}

bool isST()
{
    for (int i = 0; i < n; ++i) {
        if (in[i].first == 1) {
            st.push(in[i].second);
        }
        else {
            if (st.empty())
                return false;
            if (st.top() != in[i].second)
                return false;
            st.pop();
        }
    }
    return true;
}

void work()
{
    while (!q.empty()) q.pop();
    while (!pq.empty()) pq.pop();
    while (!st.empty()) st.pop();
    int ask, x;

    for (int i = 0; i < n; ++i) {
        cin >> in[i].first >> in[i].second;
    }

    bool is_queue = isQueue();
    bool is_pq = isPQ();
    bool is_st = isST();

    if ((int)is_queue + (int)is_pq + (int)is_st > 1)
        cout << "not sure\n";
    else if (is_queue)
        cout << "queue\n";
    else if (is_pq)
        cout << "priority queue\n";
    else if (is_st)
        cout << "stack\n";
    else
        cout << "impossible\n";
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n) {
        work();
    }
    return 0;
}

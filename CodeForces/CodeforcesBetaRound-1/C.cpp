/*****************************************************
  > File Name: C.cpp
  > Author: Larus
  > Mail: LarusCry@gmail.com
  > Created Time: 2014年11月29日 星期六 12时27分03秒
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
#define PI acos(-1.0)
#define EPS 1e-2

inline int readInt()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

int FASTBUFFER;
pair<double, double> p[3];
double r, s, dis[3], angel[3];

double cal_dis(double xx1, double yy1, double xx2, double yy2) {
    return sqrt((xx1 - xx2) * (xx1 - xx2) + (yy1 - yy2) * (yy1 - yy2));
}

double feq(double a, double b)
{
    return fabs(a - b) < EPS;
}

double fgcd(double a, double b)
{
    if (feq(a, 0))
        return b;
    if (feq(b, 0))
        return a;
    return fgcd(b, fmod(a, b));
}

void work()
{
    for (int i = 0; i < 3; ++i) {
        dis[i] = cal_dis(p[i].first, p[i].second, p[(i + 1) % 3].first, p[(i + 1) % 3].second);
    }
    double t = (dis[0] + dis[1] + dis[2]) / 2;
    s = sqrt(t * (t - dis[0]) * (t - dis[1]) * (t - dis[2]));
    r = (dis[0] * dis[1] * dis[2]) / (4 * s);
    for (int i = 0; i < 3; ++i) {
        angel[i] = acos(1 - dis[i] * dis[i] / (2 * r * r));
    }
    angel[2] = 2 * PI - angel[0] - angel[1];
    double u = 0;
    for (int i = 0; i < 3; ++i) {
        u = fgcd(u, angel[i]);
    }
    printf("%.6lf\n", r * r * sin(u) * PI / u);
}

int main()
{
    //ios::sync_with_stdio(false);
    while (~scanf("%lf%lf%lf%lf%lf%lf", &p[0].first, &p[0].second, &p[1].first, &p[1].second, &p[2].first, &p[2].second)) {
        work();
    }
    return 0;
}

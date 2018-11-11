#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int dis[205], e[205][205], weight[205];
bool visit[205];
const int inf=99999999;

vector<int> pre[205]

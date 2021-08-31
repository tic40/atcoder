#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n,m;
vector<queue<int>> a;
vector<vector<int>> mem;
queue<int> que;

void solve() {
  while(que.size()) {
    int color = que.front(); que.pop();
    for(int v: mem[color]) {
      a[v].pop();
      if (a[v].size()) {
        int ncolor = a[v].front();
        mem[ncolor].push_back(v);
        if (mem[ncolor].size() == 2) que.push(ncolor);
      }
    }
  }

  int ok = true;
  REP(i,m) {
    if (a[i].size()) ok = false;
  }

  cout << (ok ? "Yes" : "No") << endl;
  return;
}

int main() {
  cin >> n >> m;
  a.resize(m);
  mem.resize(n+1);

  REP(i,m) {
    int k; cin >> k;
    REP(j,k) {
      int _a; cin >> _a;
      a[i].push(_a);
    }
    int color = a[i].front();
    mem[color].push_back(i);
    if (mem[color].size() == 2) que.push(color);
  }

  solve();
  return 0;
}
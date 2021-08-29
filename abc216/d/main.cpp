#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n,m;
vector<int> k;
vector<queue<int>> a;
// mem[i] := iは色番号, 配列で筒番号を持つ
vector<vector<int>> mem;

void solve() {
  // 筒の先頭に同じ色がある色番号を入れる
  queue<int> que;

  REP(i,n) {
    if (mem[i].size() == 2) que.push(i);
  }

  while(que.size()) {
    int now = que.front(); que.pop();
    for(int p: mem[now]) {
      a[p].pop();
      if (a[p].size()) {
        mem[a[p].front()].push_back(p);
        if (mem[a[p].front()].size() == 2) {
          que.push(a[p].front());
        }
      }
    }
  }

  for(auto p: a) {
    if (p.size()) {
      cout << "No" << endl;
      return;
    }
  }

  cout << "Yes" << endl;
  return;
}

int main() {
  cin >> n >> m;
  k.resize(m);
  a.resize(m);
  mem.resize(n);
  REP(i,m) {
    cin >> k[i];
    REP(j,k[i]) {
      int _a; cin >> _a;
      _a--;
      a[i].push(_a);
    }
    mem[a[i].front()].push_back(i);
  }

  solve();
  return 0;
}
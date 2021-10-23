#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

vector<vector<int>> g(9);
vector<int> p(9,-1), g_state(9);
int emp = -1; // 存在しないコマ
map<vector<int>, int> memo;

void solve() {
  // 完成形
  REP(i,9) g_state[i] = i==emp ? -1 : i;

  int first_emp_idx = -1;
  REP(i,9) if (p[i] == -1) first_emp_idx = i;

  queue< tuple<int,int,vector<int>> > q;
  q.push({ 0,first_emp_idx,p });
  memo[p]++;

  while(q.size()) {
    auto [cnt, emp_idx, state] = q.front();
    q.pop();

    if (state == g_state) {
      cout << cnt << endl;
      return;
    }

    for (int v: g[emp_idx]) {
      vector<int> n_state = state;
      swap(n_state[v], n_state[emp_idx]);

      if (memo[n_state]) continue;

      memo[n_state]++;
      q.push({ cnt+1, v, n_state });
    }
  }

  cout << -1 << endl;
  return;
}

int main() {
  int m; cin >> m;
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  REP(i,8) {
    int x; cin >> x;
    x--;
    p[x] = i;
  }

  vector<bool> mb(9);
  REP(i,9) if (0 <= p[i]) mb[p[i]] = true;
  REP(i,9) if (!mb[i]) emp = i;

  solve();
  return 0;
}
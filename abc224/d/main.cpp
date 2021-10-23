#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

vector<vector<int>> g(9);
string s = "888888888";
string g_s = "012345678"; // 完成形

void solve() {
  int emp_idx; // コマが置いてない点
  REP(i,9) if (s[i]-'0' == 8) emp_idx = i;

  queue< tuple<int,int,string> > q;
  q.push({ 0,emp_idx,s });
  map<string, int> memo;
  memo[s]++;

  while(q.size()) {
    auto [cnt, emp_idx, state] = q.front();
    q.pop();

    if (state == g_s) { // 完成
      cout << cnt << endl;
      return;
    }

    for (int v: g[emp_idx]) {
      string n_state = state;
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
    s[x] = i+'0';
  }

  solve();
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

vector<vector<int>> g(9);
string s = "888888888";
string g_s = "012345678"; // 完成形

void solve() {
  queue<string> q;
  q.push(s);

  map<string, int> memo;
  memo[s]++;

  while(q.size()) {
    auto state = q.front(); q.pop();

    REP(i,9) {
      if (state[i] != '8') continue;

      for (int v: g[i]) {
        auto n_state = state;
        swap(n_state[v], n_state[i]);

        if (memo[n_state]) continue;
        memo[n_state] = memo[state]+1;
        q.push(n_state);
      }
    }
  }

  cout << memo[g_s]-1 << endl;
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
    int x; cin >> x; x--;
    s[x] = i+'0';
  }

  solve();
  return 0;
}
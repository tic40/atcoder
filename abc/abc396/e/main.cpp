#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<pair<int,int>>());
  REP(i,m) {
    int x,y,z; cin >> x >> y >> z; x--; y--;
    g[x].emplace_back(y,z);
    g[y].emplace_back(x,z);
  }

  vector<ll> ans(n);
  vector<bool> visited(n);
  auto bfs = [&](int start) -> bool {
    queue<int> q;
    vector<int> comp;

    auto push = [&](int v) {
      q.push(v);
      comp.push_back(v);
      visited[v] = true;
    };

    push(start);
    while(q.size()) {
      int from = q.front(); q.pop();
      for (auto [to,z]: g[from]) {
        if (visited[to]) {
          if ((ans[from] ^ ans[to]) != z) return false;
        } else {
          ans[to] = ans[from] ^ z;
          push(to);
        }
      }
    }

    ll t = 0;
    REP(bit,31) {
      int one = 0;
      for (auto v: comp) one += (ans[v] >> bit) & 1;
      if (one > (int)comp.size() - one) t |= (1LL << bit);
    }
    for (auto v: comp) ans[v] ^= t;
    return true;
  };

  REP(i,n) if (!visited[i] && !bfs(i)) { cout << -1 << endl; return 0; }
  for(auto v: ans) cout << v << " ";
  return 0;
}

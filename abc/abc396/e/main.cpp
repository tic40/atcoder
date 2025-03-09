#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<P>());
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
    ans[start] = 0;
    visited[start] = true;
    q.push(start);
    comp.push_back(start);

    while(q.size()) {
      int from = q.front(); q.pop();
      for (auto [to,z]: g[from]) {
        if (visited[to]) {
          if ((ans[from] ^ ans[to]) != z) return false;
        } else {
          ans[to] = ans[from] ^ z;
          visited[to] = true;
          q.push(to);
          comp.push_back(to);
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

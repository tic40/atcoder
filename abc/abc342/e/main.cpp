#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll, int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();

struct Edge {
  int from;
  ll l,d,k,c;
};

int main() {
  int n,m; cin >> n >> m;
  vector g(n, vector<Edge>());
  REP(i,m) {
    int l,d,k,c,a,b;
    cin >> l >> d >> k >> c >> a >> b;
    a--; b--;
    g[b].push_back((Edge){a,l,d,k,c});
  }

  // f[i] := 駅 i から 駅 n に到着できる最終時刻
  vector<ll> f(n,-LINF);
  f[n-1] = LINF;
  // 降順 pq, 最終時刻と地点のペア
  priority_queue<P> q;
  q.emplace(LINF,n-1);

  while(q.size()) {
    auto [t,v] = q.top(); q.pop();
    if (f[v] != t) continue;
    for(auto e: g[v]) {
      if (e.l+e.c > t) continue; // 到達不可
      ll nt = t - e.c;
      ll k = (nt - e.l) / e.d;
      k = min(k, e.k-1);
      ll nf = e.l + e.d * k;
      if (f[e.from] >= nf) continue;
      f[e.from] = nf;
      q.emplace(nf,e.from);
    }
  }

  REP(i,n-1) {
    if (f[i] == -LINF) cout << "Unreachable" << endl;
    else cout << f[i] << endl;
  }
  return 0;
}
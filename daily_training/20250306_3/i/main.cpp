#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll INF = 1e9+5;
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  int m = 0;
  vector to(n,vector<int>());
  vector<int> es(n),eg(n),mul(n),id(n);
  vector<int> dvs;

  es[0] = 0; eg[0] = 1;
  for(int i = 1; i < n; i++) {
    int p,t,s,g; cin >> p >> t >> s >> g; p--;
    to[p].push_back(i);
    if (t == 1) { es[i] = s; eg[i] = g; }
    if (t == 2) {
      es[i] = -1;
      mul[i] = g;
      dvs.push_back(i);
      id[i] = m;
      m++;
    }
  }

  int m2 = 1<<m;
  vector<ll> dp(m2,-1);
  using PQ = priority_queue<P,vector<P>,greater<P>>;
  vector<PQ> mem_q(m2);
  vector<int> mem_nb(m2);

  auto push = [&](int s, ll p, PQ q, int nb) {
    while(!q.empty() && q.top().first <= p) {
      int v = q.top().second; q.pop();
      if (es[v] != -1) p += eg[v];
      for(int u: to[v]) {
        if (es[u] == -1) nb |= 1<<id[u];
        else q.emplace(es[u],u);
      }
    }
    if (dp[s] < p) {
      dp[s] = min(p,INF);
      mem_q[s] = q; mem_nb[s] = nb;
    }
  };

  {
    PQ q;
    q.emplace(0,0);
    push(0,0,q,0);
  }

  REP(s,m2) {
    int nb = mem_nb[s];
    REP(i,m) if (nb>>i&1) {
      int v = dvs[i];
      ll p = dp[s];
      PQ q = mem_q[s];
      q.emplace(0,v);
      p *= mul[v]; p = min(p,INF);
      push(s|1<<i,p,q,nb^1<<i);
    }
  }

  bool ok = dp[m2-1] != -1 && mem_q[m2-1].empty();
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}

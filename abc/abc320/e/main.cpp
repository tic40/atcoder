#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<ll> t(m),w(m),s(m);
  REP(i,m) cin >> t[i] >> w[i] >> s[i];

  // そうめん流しに並んでいる人
  priority_queue<int, vector<int>, greater<int>> pq1;
  // 列から外れた人
  priority_queue<P, vector<P>, greater<P>> pq2;
  REP(i,n) pq1.push(i);

  vector<ll> ans(n);
  REP(i,m) {
    // 列へ戻ってくる人の処理
    while(pq2.size()) {
      auto [vt,vi] = pq2.top();
      if (vt > t[i]) break;
      pq2.pop(); pq1.push(vi);
    }
    // そうめんを食べる人の処理
    if (pq1.empty()) continue;
    auto vi = pq1.top(); pq1.pop();
    ans[vi] += w[i];
    pq2.emplace(t[i]+s[i],vi);
  }

  for(auto v: ans) cout << v << endl;
  return 0;
}
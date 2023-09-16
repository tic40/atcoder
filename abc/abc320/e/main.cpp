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

  // 現在そうめん流しに並んでいる人の priority queue
  priority_queue<int, vector<int>, greater<int>> q;
  // 列から外れた人の戻ってくる時間の早い順の priority queue
  priority_queue<P, vector<P>, greater<P>> pq;
  REP(i,n) q.push(i);

  vector<ll> ans(n);
  REP(i,m) {
    // 列へ戻ってくる人の処理
    while(pq.size()) {
      auto [vt,vi] = pq.top();
      if (vt > t[i]) break;
      pq.pop(); q.push(vi);
    }
    // そうめんを食べる人の処理
    if (q.size() == 0) continue;
    auto vi = q.top(); q.pop();
    ans[vi] += w[i];
    pq.emplace(t[i]+s[i],vi);
  }

  for(auto v: ans) cout << v << endl;
  return 0;
}
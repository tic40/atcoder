#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // bit で転倒数処理
  fenwick_tree<int> bit(m);
  vector<ll> ans(m);
  // 初期 k = 0
  REP(i,n) {
    ans[0] += i - bit.sum(0,a[i]+1);
    bit.add(a[i],1);
  }

  vector e(m,vector<ll>());
  REP(i,n) if (a[i] > 0) {
    int t = m-a[i];
    e[t].push_back(i-(n-i-1));
  }

  ll cur = ans[0];
  for (int k = 1; k < m; k++){
    for (auto d : e[k]) cur += d;
    ans[k] = cur;
  }

  REP(i,m) cout << ans[i] << endl;
  return 0;
}

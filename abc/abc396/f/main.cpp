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

  vector<ll> ans(m);
  fenwick_tree<int> fw(m);
  // k = 0 のときの転倒数を fenwich tree で求める
  REP(i,n) {
    ans[0] += i - fw.sum(0,a[i]+1);
    fw.add(a[i],1);
  }

  vector events(m,vector<ll>());
  REP(i,n) if (a[i] > 0) {
    // m-1 -> m となるとき(時刻t = m-a[i])に転倒数にどれだけ寄与するか
    // 増える転倒数 i
    // 減る転倒数 n-i-1
    events[m-a[i]].push_back(i-(n-i-1));
  }

  ll now = ans[0];
  for (int k = 1; k < m; k++){
    for (auto v : events[k]) now += v;
    ans[k] = now;
  }
  for(auto v: ans) cout << v << endl;
  return 0;
}

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

  // 累積和
  vector<ll> s(n+1);
  REP(i,n) s[i+1] = (s[i]+a[i]) % m;
  fenwick_tree<ll> fw(m);

  ll ans = 0, t = 0;
  REP(r,n+1) {
    ans += s[r] * r - t + fw.sum(s[r]+1,m) * m;
    t += s[r];
    fw.add(s[r],1);
  }

  cout << ans << endl;
  return 0;
}
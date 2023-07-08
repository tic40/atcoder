#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,ll>;

int main() {
  ll n,m; cin >> n >> m;
  vector<ll> l(m),r(m);
  REP(i,m) {
    cin >> l[i] >> r[i];
    l[i]--; r[i]--;
  }

  vector<ll> v1(n+1),v2(n+1),v3(n+1);
  ll ans1 = 0;
  REP(i,m) v3[l[i]]++;
  REP(i,m) v3[r[i]]++;
  REP(i,n) ans1 += v3[i] * (v3[i] - 1LL) / 2LL;

  ll ans2 = 0;
  REP(i,m) v1[r[i]]++;
  REP(i,m) if (l[i]-1 >= 0) v2[l[i]-1]++;
  REP(i,n) v1[i+1] += v1[i];
  REP(i,n) ans2 += v1[i] * v2[i];

  vector<P> vec;
  REP(i,m) vec.emplace_back(r[i],l[i]);
  sort(vec.begin(),vec.end());

  ll ans3 = 0;
  fenwick_tree<ll> b(n+1);
  for(auto [cr,cl]: vec) {
    ans3 += b.sum(cl+1,cr);
    b.add(cl,1);
  }

  ll tot = m * (m-1) / 2LL;
  ll ans = tot - (ans1 + ans2 + ans3);
  cout << ans << endl;

  return 0;
}
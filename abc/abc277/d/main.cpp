#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());

  dsu uf(n);
  REP(i,n) {
    int j = (i+1)%n;
    if (a[i] == a[j] || (a[i]+1)%m == a[j]) uf.merge(i,j);
  }

  vector<ll> s(n);
  REP(i,n) s[uf.leader(i)] += a[i];

  ll mx = *max_element(s.begin(),s.end());
  ll tot = accumulate(a.begin(),a.end(),0LL);
  cout << tot-mx << endl;
  return 0;
}
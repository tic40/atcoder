#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n;
vector<int> a,b,c;

ll solve() {
  ll ans = 0;
  map<int, ll> ma,mb,mc;
  REP(i,n) {
    ma[ a[i]%46 ]++;
    mb[ b[i]%46 ]++;
    mc[ c[i]%46 ]++;
  }

  for(auto x: ma) for(auto y: mb) for(auto z: mc) {
    int tot = x.first + y.first + z.first;
    if (tot % 46 == 0) ans += x.second * y.second * z.second;
  }

  return ans;
}

int main() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  c.resize(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];
  REP(i,n) cin >> c[i];
  cout << solve() << endl;

  return 0;
}
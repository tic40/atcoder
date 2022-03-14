#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
using ll = long long;

int main() {
  int n; ll k;
  cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  map<ll,pair<ll,ll>> mp; // pair<idx,x>
  ll x = 0;
  REP(i,k) {
    ll r = x%n;
    if (mp.count(r)) {
      auto [mi, mx] = mp[r];
      ll p = i - mi; // p: ループの長さ
      if ((k-i)%p == 0) { // ちょうどループで終わるところで終了する
        x += (x-mx) * ((k-i)/p);
        break;
      }
    }
    mp[r] = {i,x};
    x += a[x%n];
  }

  cout << x << endl;
  return 0;
}

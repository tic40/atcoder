#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

const int M = 1e6;

int main() {
  ll n; cin >> n;
  vector<int> c(M+1);
  REP(i,n) {
    int a; cin >> a;
    c[a]++;
  }

  // 累積和
  vector<int> s(M+2);
  REP(i,M+1) s[i+1] = s[i]+c[i];

  auto sum = [&](int l, int r) { return s[min(M+1,r)]-s[l]; };

  ll ans = 0;
  // 分子の方を固定して考える
  for(int y = 1; y <= M; y++) if (c[y] > 0) {
    ll now = 0;
    for(int x = 1; x*y <= M; x++) {
      int l = x*y;
      int r = y*(x+1);
      now += (ll)sum(l,r) * x;
    }
    now -= c[y];
    ans += now * c[y];
    ans += c[y] * ll(c[y]-1)/2;
  }
  cout << ans << endl;
  return 0;
}
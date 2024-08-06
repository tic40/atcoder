#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  // 累積 xor
  vector<int> s(n+1);
  REP(i,n) s[i+1] = s[i] ^ a[i];

  n++;
  ll ans = 0;
  REP(k,30) {
    int one = 0;
    REP(i,n) if (s[i]>>k&1) one++;
    ans += one*(ll)(n-one) * (1<<k);
  }

  // 幅 1 の区間を引く
  REP(i,n-1) ans -= a[i];
  cout << ans << endl;
  return 0;
}
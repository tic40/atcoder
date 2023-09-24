#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n,m,p; cin >> n >> m >> p;
  vector<ll> a(n),b(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  vector<ll> bs(m+1); // b の累積和
  REP(i,m) bs[i+1] = bs[i] + b[i];

  ll ans = 0;
  // a を固定して考える
  REP(i,n) {
    // a+b >= p となる b の index
    int idx = lower_bound(b.begin(),b.end(),p-a[i]) - b.begin();
    // a+b < p となる組み合わせの合計
    ans += a[i] * idx + bs[idx];
    // a+b >= p となる組み合わせの合計
    ans += (m-idx) * p;
  }
  cout << ans << endl;
  return 0;
}
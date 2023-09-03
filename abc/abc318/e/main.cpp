#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

ll choose(int n, int a) {
  ll x = 1, y = 1;
  for(ll i = 0; i < a; i++) {
    x *= n-i; y *= i+1;
  }
  return x / y;
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> cnt(n+1);
  vector<ll> sum(n+1);
  ll ans = 0;

  // step1. x?x のケースを数え上げる
  REP(k,n) {
    // Σ(Σ(k-i-1))
    // Σ(Σ(k)) - Σ(Σ(i)) - Σ(Σ(1))
    // Σ(Σ(k-1)) - Σ(Σ(i))
    // Σ(k-1)Σ(1) - Σ(Σ(i))
    // Σ(1) := i の個数, Σ(i) := i の合計
    ans += (ll)(k-1)*cnt[a[k]] - sum[a[k]];
    cnt[a[k]]++;
    sum[a[k]] += k;
  }
  // step2. xxx のケースを引く
  REP(i,n) if (cnt[i+1] >= 3) ans -= choose(cnt[i+1],3);

  cout << ans << endl;
  return 0;
}
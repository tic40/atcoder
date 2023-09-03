#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

ll choose(int n, int a) {
  if (n < a) return 0;
  ll x = 1, y = 1;
  for(ll i = 0; i < a; i++) {
    x *= n-i; y *= a-i;
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
    // ΣΣ(k) - ΣΣ(i) - ΣΣ(1)
    // ΣΣ(k-1) - ΣΣ(i)
    // Σ(k-1)Σ(1) - ΣΣ(i)
    // Σ(1) := i の個数, Σ(i) := i の合計
    ans += (ll)(k-1)*cnt[a[k]] - sum[a[k]];
    cnt[a[k]]++;
    sum[a[k]] += k;
  }
  // step2. xxx のケースを引く
  REP(i,n+1) if (cnt[i] >= 3) ans -= choose(cnt[i],3);

  cout << ans << endl;
  return 0;
}
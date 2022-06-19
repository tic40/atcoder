#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n,d; cin >> n >> d;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  ll ans = 0;
  REP(i, 1<<n) {
    ll bit = 0;

    // フラグが立っているa[j]の論理和を取る
    REP(j,n) {
      if ((i >> j) & 1) bit |= a[j];
    }

    // d桁の中で0の数をカウントする
    int free_digits = d - __builtin_popcountll(bit);
    ll x = 1LL << free_digits;

    // 偶数なら足す、奇数なら引く
    ans += __builtin_popcountll(i) % 2 ? -x : x;
  }

  cout << ans << endl;
  return 0;
}
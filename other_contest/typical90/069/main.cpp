#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using mint = modint1000000007;

// 繰り返し二乗法
mint f(ll base, ll n) {
  if (n == 0) return 1;
  mint x = f(base, n/2);
  x *= x;
  if (n % 2 == 1) x *= base;
  return x;
}

int main() {
  ll n, k; cin >> n >> k;

  mint ans = 1;
  REP(i,min(3,(int)n)) ans *= (k-i);

  if (n > 3) ans *= f(max(0LL,k-2), max(0LL,n-3) );
  cout << ans.val() << endl;
  return 0;
}
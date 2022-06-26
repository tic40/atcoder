#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

// 排他的論理和 0^1^2...x-1^x
ll f(ll x) {
  // 任意の偶数 n について n ^ (n + 1) = 1 の性質がある
  // これを利用して、例えばx=5の場合は (0^1)^(2^3)^5 = 1^1^5 となる
  ll res = ((x+1) / 2) % 2;
  return (x+1) % 2 ? res^x : res;
}

int main() {
  ll a,b; cin >> a >> b;

  // f(a,b) = f(0, a-1) ^ f(0, b) が成り立つ
  ll ans = f(a-1) ^ f(b);
  cout << ans << endl;
  return 0;
}
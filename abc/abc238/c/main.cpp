#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
using mint = modint998244353;

mint sum(ll x) {
  return (mint)(1+x)*x/2;
}

int main() {
  ll n; cin >> n;
  ll l = 1;

  mint ans = 0;
  while(l <= n) {
    ll len = min(n+1,l*10) - l;
    ans += sum(len);
    l *= 10;
  }

  cout << ans.val() << endl;
  return 0;
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using mint = modint1000000007;

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  mint ans = 0, x = 1;
  REP(i,60) {
    int one = 0;
    REP(j,n) one += (a[j]>>i & 1) == 1;
    ans += x * one * (n-one);
    x *= 2;
  }

  cout << ans.val() << endl;
  return 0;
}
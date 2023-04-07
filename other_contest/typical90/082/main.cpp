#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = unsigned long long;
using mint = modint1000000007;

int main() {
  ll l,r; cin >> l >> r;

  mint ans = 0;
  ll x = 1;
  REP(i,19) {
    if (l < x*10 && x <= r) {
      ll nl = max(l,x);
      ll nr = min(r, x*10-1);
      ans += (mint)(nl+nr)*(nr-nl+1)/2*(i+1);
    }
    x *= 10;
  }
  cout << ans.val() << endl;
  return 0;
}
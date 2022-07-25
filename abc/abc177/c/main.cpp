#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<mint> m(n+1);
  REP(i,n) m[i+1] = a[i]+m[i];

  mint ans = 0;
  REP(i,n-1) ans += a[i]*(m[n]-m[i+1]);

  cout << ans.val() << endl;
  return 0;
}
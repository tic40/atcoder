#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n; string s; cin >> n >> s;

  mint ans = 0;

  vector<mint> b(n+1);
  vector ds(n+1,vector<int>());
  // m は n でない n の約数。よって m < n かつ n % m == 0
  for(int m = 1; m < n; m++) {
    if (n%m) continue;
    mint a = 1;
    REP(i,m) {
      int x = 2;
      for(int j = i; j < n; j+=m) {
        if(s[j] == '.') x = 1;
      }
      a *= x;
    }
    for(int d: ds[m]) a -= b[d];
    ans += a;
    b[m] = a;

    for(int i = m*2; i < n; i+=m) ds[i].push_back(m);
  }
  cout << ans.val() << endl;
  return 0;
}
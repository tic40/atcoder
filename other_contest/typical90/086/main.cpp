#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using mint = modint1000000007;

int main() {
  int n,q; cin >> n >> q;
  vector<int> x(q),y(q),z(q);
  vector<ll> w(q);
  REP(i,q) {
    cin >> x[i] >> y[i] >> z[i] >> w[i];
    x[i]--; y[i]--; z[i]--;
  }

  mint ans = 1;
  // bitの桁ごとに見ていく
  REP(i,60) {
    int cnt = 0;
    REP(bit,1<<n) {
      // b[j] := 数列Aの各数の i 桁目が何か
      vector<int> b(n);
      REP(j,n) b[j] = bit >> j & 1;

      bool ok = 1;
      REP(j,q) ok &= (b[x[j]] | b[y[j]] | b[z[j]]) == (w[j] >> i & 1);
      if (ok) cnt++;
    }
    ans *= cnt;
  }
  cout << ans.val() << endl;
  return 0;
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint;

int main() {
  const int M = 5000;
  int t,mod; cin >> t >> mod;
  mint::set_mod(mod);
  vector C(M+1,vector<mint>(M+1));
  C[0][0] = 1;

  auto solve = [&]() {
    int n; cin >> n;
    int s = 0;
    mint ans = 1;
    REP(i,n) {
      int c; cin >> c;
      s += c;
      ans *= C[s][c];
    }
    cout << ans.val() << endl;
  };

  REP(i,M) REP(j,i+1) {
    C[i+1][j] += C[i][j];
    C[i+1][j+1] += C[i][j];
  }
  REP(_,t) solve();
  return 0;
}
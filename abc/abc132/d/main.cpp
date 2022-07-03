#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using mint = modint1000000007;

vector<vector<mint>> c;
void init() {
  c[0][0] = 1;
  REP(i,(int)c.size()-1) REP(j,i+1) {
    c[i+1][j] += c[i][j];
    c[i+1][j+1] += c[i][j];
  }
  return;
}

mint comb(int n, int k) {
  return c[n][k];
}

int main() {
  int n,k; cin >> n >> k;
  c.resize(n+1, vector<mint>(n+1));

  init();
  for(int i = 1; i <= k; i++) {
    // n-kの中にi個区切りを入れる組み合わせ * k個のぼーるにi-1個の区切りを入れる組み合わせ
    mint ans = comb(n-k+1,i) * comb(k-1,i-1);
    cout << ans.val() << endl;
  }
  return 0;
}
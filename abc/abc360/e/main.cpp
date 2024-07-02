#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353; // modint1000000007;

int main() {
  int n,k; cin >> n >> k;
  mint p = mint(2) / n / n; // p = 2/n^2
  mint x = 1;
  REP(ki,k) {
    x = x * (1-p * (n-1)) + (mint(1) - x) * p;
  }
  mint ans = x + (mint(1) - x) * (mint(2+n) / 2);
  cout << ans.val() << endl;
  return 0;
}
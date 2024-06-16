#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353; // modint1000000007;

int main() {
  ll n; cin >> n;
  int d = to_string(n).size();
  // a := 等比数列として考えたときの比
  mint r = mint(10).pow(d);
  // 等比数列の和の公式
  // s := N * ( 等比数列の和 )
  mint s = n * (r.pow(n) - 1) / (r - 1);
  cout << s.val() << endl;
  return 0;
}
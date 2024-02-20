#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353; // modint1000000007;

int main() {
  int n,k,l; cin >> n >> k >> l;
  mint ans = 1;
  REP(i,n) ans *= (i < n-k) ? max(0,l-i) : max(0,l-(n-k));
  cout << ans.val() << endl;
  return 0;
}
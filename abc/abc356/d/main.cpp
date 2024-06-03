#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353;

int main() {
  ll n,m; cin >> n >> m;
  mint ans = 0;
  REP(i,60) {
    ll mask = 1LL << i;
    if (m & mask) {
      ll period = mask << 1;
      ans += (n+1) / period * mask;
      ans += max(0LL, (n+1) % period - mask);
    }
  }
  cout << ans.val() << endl;
  return 0;
}
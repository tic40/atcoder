#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = unsigned long long;
using mint = modint1000000007;

int main() {
  ll l,r; cin >> l >> r;

  mint ans = 0;
  ll now = 10;
  for(int i = 1; i <= 19; i++) {
    ll ml = max(l,now/10);
    ll mr = min(r,now-1);
    if (ml <= mr) {
      mint n = mr-ml+1;
      ans += n*(ml+mr)/2*i;
    }
    now *= 10;
  }
  cout << ans.val() << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  ll n;
  cin >> n;

  ll n2 = n*2, ans = 0;
  ll sq = sqrt(n2);
  // 約数を平方根までチェックする
  for (ll x = 1; x <= sq; x++) {
    if (n2 % x) continue; // 約数ではない

    ll y = n2/x;
    bool ok = (x+y-1) % 2 == 0 && (x-y+1) % 2 == 0;
    if (ok) ans += x==y ? 1 : 2; // x==yの場合は1通り
  }

  cout << ans << endl;
  return 0;
}
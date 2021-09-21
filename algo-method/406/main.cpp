#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  ll n,k;
  cin >> n >> k;

  ll ans = 0;
  for(int i = 1; i <= n; i++) ans += min(n, k/i);
  cout << ans << endl;
  return 0;
}
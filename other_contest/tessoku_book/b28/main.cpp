#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int MOD = 1e9+7;

int main() {
  int n; cin >> n;
  ll ans = 0;
  int a1 = 1, a2 = 1;
  REP(i,n-2) {
    ans = (a1 + a2) % MOD;
    a1 = a2;
    a2 = ans;
  }
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int n; cin >> n;
  ll ans = 1;
  REP(i,n) ans = (ans * (i+1)) % 1000000007;
  cout << ans << endl;
  return 0;
}

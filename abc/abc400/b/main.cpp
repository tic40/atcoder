#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  ll ans = 0, now = 1;
  REP(i,m+1) {
    ans += now;
    now *= n;
    if (ans > 1e9) { cout << "inf" << endl; return 0; }
  }
  cout << ans << endl;
  return 0;
}

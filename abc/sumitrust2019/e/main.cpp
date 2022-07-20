#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const int MOD = 1e9+7;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  ll ans = 1;
  vector<int> m(n);
  m[0] = 3;

  REP(i,n) {
    ans *= m[a[i]];
    ans %= MOD;
    m[a[i]]--;
    m[a[i]+1]++;
  }

  cout << ans << endl;
  return 0;
}
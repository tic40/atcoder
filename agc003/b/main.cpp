#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<int> a;

void solve() {
  ll ans = 0, sum = 0;
  REP(i,n) {
    sum += a[i];
    if (a[i] == 0) {
      ans += sum / 2;
      sum = 0;
    }
  }

  ans += sum / 2;
  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}
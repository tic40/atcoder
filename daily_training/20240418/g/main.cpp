#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector m(n,vector<int>(2));
  REP(i,n) {
    while(a[i] % 2 == 0) { a[i]/= 2; m[i][0]++; }
    while(a[i] % 3 == 0) { a[i]/= 3; m[i][1]++; }
  }

  auto all_same = [&]() {
    REP(i,n-1) if (a[i] != a[i+1]) return false;
    return true;
  };
  if (!all_same()) { cout << -1 << endl; return 0; }

  int ans = 0;
  REP(j,2) {
    int mn = INF;
    REP(i,n) mn = min(mn,m[i][j]);
    REP(i,n) {
      ans += m[i][j] - mn;
    }
  }

  cout << ans << endl;
  return 0;
}
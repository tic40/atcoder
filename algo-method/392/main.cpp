#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  int ans = 1;
  int cnt = 1;

  REP(i,n-1) {
    if (a[i] <= a[i+1]) {
      cnt++;
    } else {
      ans = max(ans,cnt);
      cnt = 1;
    }
  }
  ans = max(ans,cnt);

  cout << ans << endl;

  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  vector<int> a(4),b(2);
  REP(i,4) cin >> a[i];
  REP(i,2) cin >> b[i];

  sort(a.rbegin(),a.rend());
  sort(b.rbegin(),b.rend());
  int ans = a[0]+a[1]+a[2]+b[0];
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,h;
  cin >> n >> h;
  vector<int>a(n),b(n+1);
  REP(i,n) cin >> a[i] >> b[i];

  sort(a.rbegin(),a.rend());
  sort(b.rbegin(),b.rend());

  int cur = 0;
  while(1) {
    if (h <= 0) break;
    if (b[cur] <= a[0]) break;

    h -= b[cur];
    cur++;
  }

  int ans = cur + max(0, (h+a[0]-1)/a[0]);
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int n;
vector<int> a;

void solve() {
  vector<int> p(n),q(n);
  vector<int> dp1(n, INF), dp2(n, INF);

  REP(i,n) {
    int pos = lower_bound(dp1.begin(), dp1.end(), a[i]) - dp1.begin();
    dp1[pos] = a[i];
    p[i] = pos+1;
  }

  for (int i = n-1; 0 <= i; i--) {
    int pos = lower_bound(dp2.begin(), dp2.end(), a[i]) - dp2.begin();
    dp2[pos] = a[i];
    q[i] = pos+1;
  }

  int ans = 0;
  REP(i,n) ans = max(ans, p[i] + q[i] - 1);
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
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> p(n);
  REP(i,n) cin >> p[i];
  vector<int> s(n+1,0);
  REP(i,n) { s[i+1] = s[i] + p[i]; }

  int ind, ma = -1001001001;
  for(int i = 0; i <= n-k; i++) {
    int v = s[k+i] - s[i];
    if (ma < v) {
      ma = v;
      ind = i;
    }
  }
  double ans=0;
  for (int i = ind; i < ind+k; i++) {
    ans += (double)((1.0+p[i])*p[i]) / (2.0 * p[i]);
  }
  cout << fixed << setprecision(12) << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  vector<int> sum(n), sub(n);
  REP(i,n) sum[i] = x[i]+y[i];
  REP(i,n) sub[i] = x[i]-y[i];

  sort(sum.begin(),sum.end());
  sort(sub.begin(),sub.end());

  int ans = max(sum.back() - sum[0], sub.back()-sub[0]);
  cout << ans << endl;

  return 0;
}
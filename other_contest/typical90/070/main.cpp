#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  ll ans = 0;
  REP(i,n) {
    ans += abs(x[i] - x[n/2]);
    ans += abs(y[i] - y[n/2]);
  }
  cout << ans << endl;
  return 0;
}
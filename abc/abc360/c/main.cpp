#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n),w(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> w[i];

  ll ans = 0;
  vector<int> mx(1e5+1);
  REP(i,n) {
    ans += min(mx[a[i]],w[i]);
    mx[a[i]] = max(mx[a[i]],w[i]);
  }

  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  ll ans = 0;
  REP(i,n) {
    int idx = lower_bound(a.begin(),a.end(),a[i]*2) - a.begin();
    ans += n-idx;
  }
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  sort(a.begin(),a.end());
  ll ans = 0;
  REP(i,n) {
    int key = k - a[i];
    auto it = lower_bound(a.begin(),a.end(),key);
    ans += n - (it - a.begin());
  }
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  ll ans = 0;
  REP(i,n) {
    int id = upper_bound(a.begin(),a.end(),a[i]+k) - a.begin() - 1;
    ans += id - i;
  }
  cout << ans << endl;
  return 0;
}
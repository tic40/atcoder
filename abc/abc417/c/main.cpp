#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  /*
    j-i = a[i] + a[j]
    a[i] + i = j - a[j];
  */
  vector<int> cnt(2e5+1);
  REP(i,n) if (i-a[i] >= 0) cnt[i-a[i]]++;

  ll ans = 0;
  REP(i,n) {
    if (i-a[i] >= 0) cnt[i-a[i]]--;
    if (a[i]+i <= 2e5) ans += cnt[a[i]+i];
  }
  cout << ans << endl;
  return 0;
}
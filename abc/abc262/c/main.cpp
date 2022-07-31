#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) { cin >> a[i]; a[i]--; }

  vector<int> m(n+1);
  REP(i,n) if (a[i] == i) m[i]++;
  REP(i,n) m[i+1] += m[i];

  ll ans = 0;
  REP(i,n) {
    if (a[i] < i) continue;
    if (a[i] == i) {
      ans += m[n] - m[i];
    }
    if (a[i] > i) {
      if (a[ a[i] ] == i) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
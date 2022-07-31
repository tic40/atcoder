#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) {
    cin >> a[i];
    a[i]--;
  }

  // a[i] = i の数
  vector<int> m(n+1);
  REP(i,n) {
    if (a[i] == i) m[i]++;
    m[i+1] = m[i];
  }

  ll ans = 0;
  REP(i,n) {
    if (a[i] < i) continue;
    if (a[i] == i) {
      ans += m[n] - m[i];
    } else {
      if (a[a[i]] == i) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
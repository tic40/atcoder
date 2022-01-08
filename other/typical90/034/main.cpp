#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n,k;
vector<int> a;

void solve() {
  int ans = 0;

  map<int, int> m;
  int r = 0;
  int tot = 0; // 種類の合計
  // しゃくとり
  REP(l,n) {
    while(r < n) {
      if (m[a[r]] == 0) {
        if (k <= tot) break;
        tot++;
      }
      m[a[r]]++;
      r++;
    }
    ans = max(ans, r-l);

    if (r == l) r++;
    m[a[l]]--;
    if (m[a[l]] == 0) tot--;
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}
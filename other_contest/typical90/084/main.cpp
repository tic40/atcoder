#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; string s; cin >> n >> s;
  vector<int> a(n);
  REP(i,n) a[i] = s[i] == 'o' ? 0 : 1;
  vector<int> cnt(2);

  // しゃくとり法
  int r = 0;
  ll ans = 0;
  REP(l,n) {
    while(r < n) {
      if (cnt[0] && cnt[1]) break;
      cnt[a[r]]++;
      r++;
    }
    if (cnt[0] && cnt[1]) ans += n-r+1;
    if (r == l) r++;
    cnt[a[l]]--;
  }
  cout << ans << endl;
  return 0;
}
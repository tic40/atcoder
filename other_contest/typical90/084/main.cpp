#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; string s; cin >> n >> s;
  vector<int> t(n);
  REP(i,n) t[i] = s[i] == 'o' ? 0 : 1;

  int r = 0;
  ll ans = 0;
  vector<int> cnt(2); // 0: o, 1: x
  REP(l,n) {
    while(r < n) {
      if (cnt[0] && cnt[1]) break;
      cnt[t[r]]++;
      r++;
    }
    if (cnt[0] && cnt[1]) ans += n-r+1;
    if (l == r) r++;
    cnt[t[l]]--;
  }
  cout << ans << endl;
  return 0;
}
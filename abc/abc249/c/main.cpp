#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,k; cin >> n >> k;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  int ans = 0;
  REP(bit, (1<<n)) {
    vector<int> m(26);
    REP(i,n) {
      if (bit >> i & 1) {
        for(auto c: s[i]) m[c-'a']++;
      }
    }
    int cnt = 0;
    for(int v: m) if (v == k) cnt++;
    ans = max(ans,cnt);
  }

  cout << ans << endl;
  return 0;
}
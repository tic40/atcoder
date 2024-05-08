#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector g(n,vector<int>(26));
  REP(i,n) {
    string s; cin >> s;
    for(auto c: s) g[i][c-'a']++;
  }

  int ans = 0;
  REP(bit, 1<<n) {
    vector<int> cnt(26);
    REP(i,n) if (bit >> i & 1) {
      REP(j,26) cnt[j] += g[i][j];
    }
    int now = 0;
    REP(j,26) if (cnt[j] == k) now++;
    ans = max(ans,now);
  }
  cout << ans << endl;
  return 0;
}
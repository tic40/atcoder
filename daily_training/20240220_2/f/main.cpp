#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<string> s(n);
  REP(i,n) cin >> s[i];
  vector cnt(n,vector<int>(26));
  REP(i,n)  for(auto c: s[i]) cnt[i][c-'a']++;

  int ans = 0;
  REP(bit, 1<<n) {
    vector<int> v(26);
    REP(i,n) if ((bit >> i) & 1) {
      REP(j,26) v[j] += cnt[i][j];
    }
    int now = 0;
    REP(i,26) if (v[i] == k) now++;
    ans = max(ans,now);
  }
  cout << ans << endl;
  return 0;
}
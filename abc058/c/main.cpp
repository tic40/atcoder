#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int cnt[50][26];

int main() {
  int n; cin >> n;
  string s,ans="";
  REP(i,n) {
    cin >> s;
    for (char c : s) cnt[i][c-'a']++;
  }

  REP(i,26) {
    int m = 100;
    REP(j,n) m = min(m,cnt[j][i]);
    while(m>0) { ans += 'a'+i; m--; }
  }
  cout << ans << endl;
  return 0;
}
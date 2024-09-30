#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  const int n = 26;
  int now = 0;
  REP(i,n) if (s[i] == 'A') now = i;

  int ans = 0;
  for(int i = 1; i < 26; i++) {
    int nx = char('A' + i);
    REP(j,n) if (s[j] == nx) {
      ans += abs(now-j);
      now = j;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
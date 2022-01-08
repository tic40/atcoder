#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  string s; cin >> s;
  int ans = 100;

  for(char c: s) {
    int cnt = 0;

    REP(i, s.size()) {
      int j = i;
      while(j < s.size()) {
        if (s[j] == c) break;
        j++;
      }
      cnt = max(cnt, j-i);
      i = j;
    }
    ans = min(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}
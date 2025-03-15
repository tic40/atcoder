#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size(), ans = 0;
  REP(i,n) {
    int now = i+ans;
    char c = now % 2 == 0 ? 'i' : 'o';
    if (s[i] != c) { ans++; i--; }
  }
  ans += (n+ans)%2;
  cout << ans << endl;
  return 0;
}

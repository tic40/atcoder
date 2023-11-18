#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  string s; cin >> s;

  vector<int> mem(26);
  int r = 1;
  char now = s[0];
  int cnt = 1;
  REP(l,n) {
    while(r < n) {
      if (now != s[r]) break;
      cnt++; r++;
    }
    mem[now - 'a'] = max(mem[now - 'a'],cnt);
    cnt = 0;
    if (r == l) r++;
    now = s[r];
  }

  int ans = accumulate(mem.begin(),mem.end(),0);
  cout << ans << endl;
  return 0;
}
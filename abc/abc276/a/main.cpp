#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int ans = -1;
  REP(i,n) if (s[i] == 'a') ans = i+1;
  cout << ans << endl;
  return 0;
}
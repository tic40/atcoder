#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s,t;
  cin >> n >> s >> t;

  int ans = 0;
  REP(i,n) if (s[i] != t[i]) ans++;
  cout << ans << endl;
  return 0;
}

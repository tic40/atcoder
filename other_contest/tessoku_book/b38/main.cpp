#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s; cin >> n >> s;
  vector<int> ret1(n),ret2(n);

  ret1[0] = 1;
  REP(i,n-1) ret1[i+1] = s[i]=='A' ? ret1[i]+1 : 1;
  ret2[n-1] = 1;
  for(int i = n-2; i >= 0; i--) ret2[i] = s[i]=='B' ? ret2[i+1]+1 : 1;

  int ans = 0;
  REP(i,n) ans += max(ret1[i],ret2[i]);
  cout << ans << endl;
  return 0;
}
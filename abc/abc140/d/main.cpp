#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,k; string s;
  cin >> n >> k >> s;

  int cnt = 0;
  REP(i,n-1) if (s[i] == s[i+1]) cnt++;
  int ans = min(k*2+cnt, n-1);
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  string s; cin >> s;
  int n = s.size();

  int cnt = 0;
  vector<int> l(n+1), r(n+1);
  REP(i,n) {
    if (s[i] == '<') cnt++;
    else cnt = 0;
    l[i+1] = cnt;
  }

  cnt = 0;
  for (int i = n-1; 0<=i; i--) {
    if (s[i] == '>') cnt++;
    else cnt = 0;
    r[i] = cnt;
  }

  ll ans = 0;
  REP(i,n+1) ans += max(l[i],r[i]);
  cout << ans << endl;
  return 0;
}
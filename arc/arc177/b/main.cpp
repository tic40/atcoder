#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  string s; cin >> s;

  string ans = "";
  for(int i = n-1; i >= 0; i--) {
    if (s[i] == '0') continue;
    ans += string(i+1,'A');
    ans += string(i,'B');
  }
  cout << ans.size() << endl;
  cout << ans << endl;
  return 0;
}
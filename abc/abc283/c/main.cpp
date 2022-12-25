#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();

  int ans = 0, i = 0;
  while(i < n) {
    ans++;
    if (i+1 < n && s[i] == '0' && s[i+1] == '0') {
      i+=2;
    } else {
      i++;
    }
  }

  cout << ans << endl;
  return 0;
}
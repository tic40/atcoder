#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();

  int ans = 0;
  bool flag = false;
  REP(i,n) {
    if (s[i] != '0') {
      ans++;
      flag = false;
    } else {
      if (!flag) ans++;
      flag = !flag;
    }
  }

  cout << ans << endl;
  return 0;
}
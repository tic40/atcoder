#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  bool login = false;
  int ans = 0;
  REP(i,n) {
    string s; cin >> s;
    if (s == "login") login = true;
    if (s == "logout") login = false;
    if (s == "private" && !login) ans++;
  }
  cout << ans << endl;
  return 0;
}

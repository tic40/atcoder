#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int ans = 0;
  REP(i,12) {
    string s; cin >> s;
    if ((int)s.size() == (i+1)) ans++;
  }
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

const string atc = "atcoder";
int main() {
  string s; cin >> s;

  int ans = 0;
  REP(i,7) {
    int t = atc[i];
    int ni = 0;
    REP(j,7) {
      if (t == s[j]) { ni = j; break; }
    }

    while(1) {
      if (ni == i) break;
      swap(s[ni],s[ni-1]);
      ans++;
      ni--;
    }
  }

  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  auto solve = []() {
    int n; string s; cin >> n >> s;

    int l = -1;
    REP(i,n-1) {
      if (s[i] > s[i+1]) { l = i; break; }
    }

    if (l != -1) {
      int r = n-1;
      for(int i = l; i < n-1; i++) {
        if (s[l] < s[i+1]) { r = i; break; }
      }
      rotate(s.begin()+l, s.begin()+(l+1), s.begin()+(r+1));
    }

    cout << s << endl;
  };

  int t; cin >> t;
  REP(_,t) solve();
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n,a,b,c,d;
string s;

void solve() {
  for (int i = min(a,b); i < max(c,d); i++) {
    if (s[i] == '#' && s[i+1] == '#') {
      cout << "No" << endl;
      return;
    }
  }

  bool ok = false;
  if ( (a < b && d < c) || (b < a && c < d) ) {
    int as = min(a,b);
    int ag = max(c,d);
    int bs = max(a,b);
    int bg = min(c,d);
    for (int i = bs-1; i < bg; i++) {
      if (s[i] == '.' && s[i+1] == '.' && s[i+2] == '.') {
        ok = true;
      }
    }
  } else {
    ok = true;
  }

  cout << (ok ? "Yes" : "No") << endl;
  return;
}

int main() {
  cin >> n >> a >> b >> c >> d >> s;
  a--,b--,c--,d--;

  solve();
  return 0;
}
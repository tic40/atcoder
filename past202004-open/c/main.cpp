#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  for(int i = n-2; 0 <= i; i--) {
    for(int j = 1; j < 2*n-1; j++) {
      if (s[i][j] != '#') continue;
      int ok = s[i+1][j-1] == 'X' || s[i+1][j] == 'X' || s[i+1][j+1] == 'X';
      if (ok) s[i][j] = 'X';
    }
  }

  REP(i,n) cout << s[i] << endl;

  return 0;
}
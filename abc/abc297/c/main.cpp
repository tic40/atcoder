#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  REP(i,h) REP(j,w-1) {
    if (s[i][j] == 'T' && s[i][j+1] == 'T') {
      s[i][j] = 'P';
      s[i][j+1] = 'C';
    }
  }

  REP(i,h) cout << s[i] << endl;
  return 0;
}
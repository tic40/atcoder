#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  int top = 1e5, bottom = 0, left = 1e5, right = 0;
  REP(i,h) REP(j,w) if (s[i][j] == '#') {
    top = min(top,i);
    bottom = max(bottom,i);
    left = min(left,j);
    right = max(right,j);
  }

  for(int i = top; i <= bottom; i++) for(int j = left; j <= right; j++) {
    if (s[i][j] == '.') { cout << "No" << endl; return 0; }
  }
  cout << "Yes" << endl;
  return 0;
}
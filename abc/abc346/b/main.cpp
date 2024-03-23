#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

const string t = "wbwbwwbwbwbw";

int main() {
  int w,b; cin >> w >> b;
  string s;
  REP(i,100) s += t;
  REP(i,12) {
    int cw = 0, cb = 0;
    int j = i;
    while(1) {
      if (cw == w && cb == b) { cout << "Yes" << endl; return 0; }
      if (cw > w || cb > b) break;
      if (s[j] == 'w') cw++;
      if (s[j] == 'b') cb++;
      j++;
    }
  }
  cout << "No" << endl;
  return 0;
}
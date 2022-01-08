#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int h,w; cin >> h >> w;
  string s;

  REP(i,w+2) cout << "#";
  cout << endl;
  REP(i,h) {
    cin >> s; cout << "#" << s << "#" << endl;
  }
  REP(i,w+2) cout << "#";
  cout << endl;
  return 0;
}

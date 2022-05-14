#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  string s; cin >> s;
  int n = s.size();
  REP(i,6/n) cout << s;
  cout << endl;

  return 0;
}

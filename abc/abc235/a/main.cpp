#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  string s; cin >> s;
  int ans = 0;
  REP(i,3) {
    rotate(s.begin(), s.begin()+1, s.end());
    ans += stoi(s);
  }

  cout << ans << endl;
  return 0;
}
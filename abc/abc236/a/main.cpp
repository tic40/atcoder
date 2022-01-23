#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  string s; cin >> s;
  int a,b; cin >> a >> b;
  a--; b--;
  swap(s[a],s[b]);
  cout << s << endl;
  return 0;
}
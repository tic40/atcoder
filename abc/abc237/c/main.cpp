#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

bool is_palindrome(string s) {
  int n = s.size();
  REP(i,n/2) if (s[i] != s[n-i-1]) return false;
  return true;
}

int main() {
  string s; cin >> s;
  int n = s.size();

  // 両端からaを取り除く
  int fcnt = 0, bcnt = 0;
  for(int i = n-1; 0 <= i; i--) {
    if (s[i] != 'a') break;
    bcnt++;
  }
  REP(i,n) {
    if (s[i] != 'a') break;
    fcnt++;
  }

  fcnt = min(bcnt, fcnt);
  string ns = s.substr(fcnt, n-(fcnt+bcnt));

  bool ok = is_palindrome(ns);
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}
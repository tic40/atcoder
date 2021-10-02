#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  string s,t; cin >> s >> t;

  if (s != t) {
    int n = s.size();
    REP(i,n-1) {
      swap(s[i],s[i+1]);
      if (s == t) break;
      swap(s[i],s[i+1]);
    }
  }

  cout << (s==t ? "Yes" : "No") << endl;
  return 0;
}
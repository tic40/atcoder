#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  string s; cin >> s;
  int n = s.size();
  vector<int> m(26);
  REP(i,n) m[ s[i]-'a' ]++;

  if (n == 26) {
    vector<int> d;
    for (int i = n-1; i >= 0; i--) {
      for(char c: d) {
        if (s[i]-'a' < c-'a') {
          cout << s.substr(0, i) + c << endl;
          return 0;
        }
      }
      d.push_back(s[i]);
    }
  } else {
    REP(i,26) {
      if (m[i] == 0) {
        s.push_back('a'+i);
        cout << s << endl;
        return 0;
      }
    }
  }

  cout << -1 << endl;

  return 0;
}
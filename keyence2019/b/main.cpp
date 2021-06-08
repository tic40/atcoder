#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  string s; cin >> s;
  int n = s.size();

  REP(i,n) for (int j = i+1; j < n; j++) {
    string t = s.substr(0,i+1) + s.substr(j);
    if (t == "keyence") {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}
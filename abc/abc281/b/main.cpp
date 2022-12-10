#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();

  if (n == 8) {
    if (s[0] >= 'A' && s[0] <= 'Z') {
      if (s.back() >= 'A' && s.back() <= 'Z') {
        int x = stoi( s.substr(1,6) );
        if (x >= 100000 && x <= 999999) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
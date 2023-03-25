#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  auto r = regex("^((and)|(not)|(that)|(the)|(you))$");
  REP(i,n) {
    string w; cin >> w;
    if (regex_match(w,r)) { cout << "Yes" << endl; return 0;}
  }
  cout << "No" << endl;
  return 0;
}
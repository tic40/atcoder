#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  string s,t; cin >> s >> t;
  auto f = [](string x) {
    return x[0] == 'B' ?  -(x[1]-'0')+1 : x[0]-'0';
  };
  cout << abs(f(s) - f(t)) << endl;
  return 0;
}
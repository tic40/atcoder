#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;
  auto f = [&](string s) {
    int x = s[0]-'A', y = s[1]-'A';
    int d = abs(x-y);
    return d > 2 ? 5 - d : d;
  };

  cout << (f(s) == f(t) ? "Yes" : "No") << endl;
  return 0;
}
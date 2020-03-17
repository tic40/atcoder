#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  string s; cin >> s;
  for (int i = s.size()-2; i >= 0; i-=2) {
    if (s.substr(0,i/2) == s.substr(i/2,i/2)) { cout << i << endl; return 0; }
  }
  return 0;
}

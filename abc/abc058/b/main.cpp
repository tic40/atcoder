#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  string o,e; cin >> o >> e;
  REP(i, (o+e).size()) {
    if (i%2) cout << e[i/2];
    else cout << o[i/2];
  }
  cout << endl;
  return 0;
}
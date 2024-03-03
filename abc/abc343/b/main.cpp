#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  REP(i,n) REP(j,n) {
    int a; cin >> a;
    if (a == 1) g[i].push_back(j+1);
  }
  REP(i,n) {
    for(auto v: g[i]) cout << v << " ";
    cout << endl;
  }
  return 0;
}
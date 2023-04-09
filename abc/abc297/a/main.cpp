#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,d; cin >> n >> d;
  vector<int> t(n);
  int p = -1e9;
  REP(i,n) {
    int t; cin >> t;
    if (t-p <= d) { cout << t << endl; return 0; }
    p = t;
  }
  cout << -1 << endl;
  return 0;
}
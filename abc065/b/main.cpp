#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int n; cin >> n;
  int a[n]; REP(i,n) cin >> a[i];
  int cur = 0;
  REP(i,n) {
    if (a[cur] == 2) { cout << i+1 << endl; return 0; }
    cur = a[cur]-1;
  }
  cout << -1 << endl;
  return 0;
}

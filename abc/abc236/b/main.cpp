#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

vector<int> a(100005);
int main() {
  int n; cin >> n;
  REP(i,4*n-1) {
    int t; cin >> t;
    a[t]++;
  }

  for(int i = 1; i <= n; i++) {
    if (a[i] == 4) continue;
    cout << i << endl;
    break;
  }

  return 0;
}
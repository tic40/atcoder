#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<vector<int>> a(n,vector<int>(n));

  int now = 1;
  for(int i = 0; i < n; i+=2) REP(j,n) a[i][j] = now++;
  for(int i = 1; i < n; i+=2) REP(j,n) a[i][j] = now++;

  REP(i,n) {
    REP(j,n) cout << a[i][j] << " ";
    cout << endl;
  }
  return 0;
}
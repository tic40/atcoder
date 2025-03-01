#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector a(n,vector<char>(n,'-'));
  REP(i,n) {
    int j = n-1-i;
    if (i > j) continue;
    for(int i2 = i; i2 <= j; i2++) for(int j2 = i; j2 <= j; j2++) {
      a[i2][j2] = i%2 == 1 ? '.' : '#';
    }
  }

  REP(i,n) {
    REP(j,n) cout << a[i][j];
    cout << endl;
  }
  return 0;
}

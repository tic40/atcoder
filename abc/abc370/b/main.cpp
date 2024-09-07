#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector a(n,vector<int>());
  REP(i,n) REP(j,i+1) {
    int x; cin >> x; x--;
    a[i].push_back(x);
  }

  int i = 0;
  REP(j,n) i = i >= j ? a[i][j] : a[j][i];
  cout << i+1 << endl;
  return 0;
}
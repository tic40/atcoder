#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int x[10][10];
int y[10][10];

int main() {
  int n,m;
  cin >> n >> m;

  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    x[a][b]=1;
    x[b][a]=1;
  }
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    y[a][b]=1;
    y[b][a]=1;
  }

  vector<int> b(n);
  REP(i,n) b[i] = i;
  do {
    int ok = true;
    REP(i,n) REP(j,n) {
      if (x[i][j] != y[b[i]][b[j]]) ok = false;
    }

    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }
  } while (next_permutation(b.begin(), b.end()));

  cout << "No" << endl;
  return 0;
}
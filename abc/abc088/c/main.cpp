#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x)  cout << #x << " = " << (x) << endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int c[3][3];
  REP(i,3) REP(j,3) cin >> c[i][j];

  int ok = 1;
  REP(i,2) {
    int x = c[0][0] - c[0][i+1];
    if (c[1][0] - c[1][i+1] != x) ok = 0;
    if (c[2][0] - c[2][i+1] != x) ok = 0;
  }
  REP(i,2) {
    int x = c[0][0] - c[i+1][0];
    if (c[0][1] - c[i+1][1] != x) ok = 0;
    if (c[0][2] - c[i+1][2] != x) ok = 0;
  }

  COUT(ok ? "Yes" : "No");
  return 0;
}

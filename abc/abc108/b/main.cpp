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
  int x[4],y[4];
  REP(i,2) cin >> x[i] >> y[i];
  x[2] = x[1] - (y[1]-y[0]);
  y[2] = y[1] + x[1] - x[0];
  x[3] = x[0] - (y[1]-y[0]);
  y[3] = y[0] + x[1] - x[0];
  printf("%d %d %d %d", x[2],y[2],x[3],y[3]);
  return 0;
}

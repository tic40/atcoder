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

string s[55];

void solve(int x, int y) {
  char cur = s[x][y];
  if (cur == '#') { cout << '#'; return ; }
  int sum = 0;
  for (int i = x-1; i <= x+1; i++) {
    for (int j = y-1; j <= y+1; j++) {
      if (i < 0 || j < 0) continue;
      if (i==x && j==y) continue;
      if (s[i][j] == '#') sum++;
    }
  }
  cout << sum;
  return ;
}

int main() {
  int h,w; cin >> h >> w;
  REP(i,h) cin >> s[i];
  REP(i,h) {
    REP(j,w) solve(i,j);
    cout << endl;
  }
  return 0;
}

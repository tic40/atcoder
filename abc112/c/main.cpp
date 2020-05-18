#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x) cout<<#x<<" = "<<(x)<<endl;
#define Yes(x) cout<<(x?"Yes":"No")<<endl;
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
  int n; cin >> n;
  int x[n],y[n],h[n];
  REP(i,n) cin>>x[i]>>y[i]>>h[i];

  REP(posY,101) REP(posX,101) {
    int needH = -1;
    REP(i,n) {
      if (h[i] == 0) continue;
      int tmp = h[i]+abs(posY-y[i])+abs(posX-x[i]);
      if (needH == -1) needH = tmp;
      if (needH != tmp) { needH = -2; break; }
    }
    if (needH == -2) continue;

    REP(i,n) {
      if (h[i] > 0) continue;
      int dist = abs(posY-y[i])+abs(posX-x[i]);
      if (needH > dist) { needH = -2; break; }
    }
    if (needH == -2) continue;
    printf("%d %d %d\n",posX,posY,needH);
  }

  return 0;
}

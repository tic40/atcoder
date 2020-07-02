#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i, n) for(int i=0;i<n;i++)
#define YES(x) cout<<(x?"YES":"NO")<<"\n"
#define Yes(x) cout<<(x?"Yes":"No")<<"\n"
#define dump(x) cout<<#x<<" = "<<(x)<<"\n"
#define endl "\n"
using G = vector<vector<int>>;
using M = map<int,int>;
using P = pair<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int,vector<int>,greater<int>>;
using V = vector<int>;
using ll = long long;
using edge = struct { int to; int cost; };
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  IOS;
  int h,w; cin >> h >> w;
  int a[h][w];
  REP(i,h) REP(j,w) cin >> a[i][j];

  vector<tuple<int,int,int,int>> ans;
  REP(i,h-1) REP(j,w) {
    if(a[i][j]%2==0) continue;
    a[i][j]--; a[i+1][j]++;
    ans.push_back( make_tuple(i,j,i+1,j) );
  }
  REP(j,w-1) {
    if (a[h-1][j]%2==0) continue;
    a[h-1][j]--; a[h-1][j+1]++;
    ans.push_back( make_tuple(h-1,j,h-1,j+1) );
  }

  COUT(ans.size());
  for(auto x: ans) {
    cout
      << get<0>(x)+1 << " "
      << get<1>(x)+1 << " "
      << get<2>(x)+1 << " "
      << get<3>(x)+1 << endl;
  }

  return 0;
}
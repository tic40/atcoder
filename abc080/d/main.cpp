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

int N,C;
const int MAX = 100010;
int cs[30][MAX];
int ss[MAX];

int main() {
  IOS;
  cin >> N >> C;
  REP(i,N) {
    int s,t,c;
    cin >> s >> t >> c;
    c--; s--;
    cs[c][s]++;
    cs[c][t]--;
  }

  REP(i,C) REP(j,MAX-1) cs[i][j+1] += cs[i][j];
  REP(i,C) REP(j,MAX) {
    if (cs[i][j]) ss[j]++;
  }

  int ans = 0;
  REP(i,MAX) { chmax(ans, ss[i]); }
  COUT(ans);

  return 0;
}

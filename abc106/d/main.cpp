#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i,n) for(int i=0;i<n;i++)
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
template<class T>bool chmax(T &a,const T &b) {if(a<b){a=b; return 1;} return 0;}
template<class T>bool chmin(T &a,const T &b) {if(b<a){a=b; return 1;} return 0;}
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

const int SIZE = 505;
int g[SIZE][SIZE];
int s[SIZE][SIZE];

int main() {
  IOS;
  int N,M,Q;
  cin >> N >> M >> Q;
  REP(i,M) {
    int l,r; cin >> l >> r;
    l--; r--;
    g[l][r]++;
  }

  // 二次元累積和
  REP(i,N) REP(j,N) {
    s[i+1][j+1] += g[i][j];
    s[i+1][j+1] += s[i+1][j];
    s[i+1][j+1] += s[i][j+1];
    s[i+1][j+1] -= s[i][j];
  }

  REP(i,Q) {
    int l,r; cin >> l >> r;
    int ans = s[r][r];
    ans -= s[l-1][r];
    ans -= s[r][l-1];
    ans += s[l-1][l-1];
    COUT(ans);
  }

  return 0;
}
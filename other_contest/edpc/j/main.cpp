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

int n;
// [寿司が1個の皿の数][2個の皿の数][3個の皿の数] = 寿司をすべてなくすのに必要な操作回数の期待値
double dp[310][310][310];

double rec(int i, int j, int k) {
  if (0 <= dp[i][j][k]) return dp[i][j][k];
  if (i==0 && j==0 && k==0) return 0.0;

  double res = 0.0;
  if (0 < i) res += rec(i-1,j,k) * i;
  if (0 < j) res += rec(i+1,j-1,k) * j;
  if (0 < k) res += rec(i,j+1,k-1) * k;
  res += n;
  res *= 1.0 / (i+j+k);

  return dp[i][j][k] = res;
}

int main() {
  IOS;
  cin >> n;
  map<int, int> mp;
  REP(i,n) {
    int a; cin >> a;
    mp[a]++;
  }

  memset(dp, -1, sizeof(dp));
  cout << fixed << setprecision(10) << rec(mp[1],mp[2],mp[3]) << endl;
  return 0;
}
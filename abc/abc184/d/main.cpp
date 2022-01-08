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

double dp[105][105][105];

double rec(int i, int j, int k) {
  if (dp[i][j][k]) return dp[i][j][k];
  if (i==100 || j==100 || k==100) return 0.0;

  double res = 0.0;
  res += (rec(i+1,j,k)+1) * i / (i+j+k);
  res += (rec(i,j+1,k)+1) * j / (i+j+k);
  res += (rec(i,j,k+1)+1) * k / (i+j+k);
  return dp[i][j][k] = res;
}

int main() {
  IOS;
  int a,b,c;
  cin >> a >> b >> c;

  cout << fixed << setprecision(10) << rec(a,b,c) << endl;
  return 0;
}
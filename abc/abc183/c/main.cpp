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

int n,k;
int t[10][10];
int ans = 0;

void dfs(vector<int> v, int sum) {
  if (k < sum) return;

  int cur = v[v.size()-1];
  if (v.size() == n) {
    sum += t[cur][0];
    if (sum == k) ans++;
    return;
  }

  REP(i,n) {
    if (find(ALL(v), i) != v.end()) continue;
    vector<int> nv = v;
    nv.push_back(i);
    dfs(nv, sum + t[cur][i]);
  }
  return;
}

int main() {
  IOS;
  cin >> n >> k;
  REP(i,n) REP(j,n) cin >> t[i][j];

  vector<int> v;
  v.push_back(0);
  dfs(v, 0);

  COUT(ans);
  return 0;
}
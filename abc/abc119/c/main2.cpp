#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x) cout<<#x<<" = "<<(x)<<endl;
#define Yes(x) cout<<(x?"Yes":"No")<<endl;
#define YES(x) cout<<(x?"YES":"NO")<<endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
template<class T>bool chmax(T &a,const T &b) {if(a<b){a=b; return 1;} return 0;}
template<class T>bool chmin(T &a,const T &b) {if(b<a){a=b; return 1;} return 0;}
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int N,A,B,C;
vector<int> l;

int dfs(int cur, int a, int b, int c) {
  if (cur == N) {
    if (a < 1 || b < 1 || c < 1) return INF;
    int diff = abs(A-a) + abs(B-b) + abs(C-c);
    return diff - 30;
  }

  int next = cur+1;
  int res[4];
  res[0] = dfs(next,a,b,c); // 選ばない
  res[1] = dfs(next,a+l[cur],b,c) + 10;
  res[2] = dfs(next,a,b+l[cur],c) + 10;
  res[3] = dfs(next,a,b,c+l[cur]) + 10;

  int ans = INF;
  REP(i,4) chmin(ans,res[i]);
  return ans;
}

int main() {
  cin >> N >> A >> B >> C;
  l.resize(N);
  REP(i,N) cin >> l[i];

  COUT( dfs(0,0,0,0) );
  return 0;
}

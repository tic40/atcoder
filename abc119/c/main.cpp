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

int dfs(int n, int a, int b, int c) {
  if (n == N) {
    if (0 < a && 0 < b && 0 < c) {
      // 延長/短縮魔法(1MP)分をここで計算
      // 最初に素材にした分は10MPを消費しないので -10*3 を引く
      return abs(A-a) + abs(B-b) + abs(C-c) - 30;
    }
    return INF;
  }

  int mps[4],ret = INF;
  // 延長魔法(+10)でA or B or C の素材にする
  mps[0] = dfs(n+1, a+l[n], b, c) + 10;
  mps[1] = dfs(n+1, a, b+l[n], c) + 10;
  mps[2] = dfs(n+1, a, b, c+l[n]) + 10;
  // 使わない
  mps[3] = dfs(n+1, a, b, c);

  REP(i,4) chmin(ret, mps[i]);
  return ret;
}

int main() {
  cin >> N >> A >> B >> C;
  l.resize(N);
  REP(i,N) cin >> l[i];

  COUT(dfs(0,0,0,0));
  return 0;
}

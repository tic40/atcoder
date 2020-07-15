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

int f(int x) {
  if (x == 0) return 0;
  return f( x % __builtin_popcount(x) ) + 1;
}

int main() {
  IOS;
  int n; cin >> n;
  string s; cin >> s;
  vector<int> x(n);
  REP(i,n) x[i] = s[i]-'0';
  int pc = 0; // popcount
  REP(i,n) pc += x[i];
  vector<int> ans(n);

  REP(b,2) {
    int npc = b == 0 ? pc+1 : pc-1;
    if (npc <= 0) continue;

    int r0 = 0;
    // 2進数から10進数整数を算出
    REP(i,n) {
      r0 = (r0*2)%npc;
      r0 += x[i];
    }

    int k = 1;
    for (int i = n-1; i>=0; i--) {
      if (x[i] == b) {
        int r = r0;
        if (b == 0) r = (r+k)%npc;
        else r = (r-k+npc)%npc;
        ans[i] = f(r)+1;
      }
      k = (k*2)%npc;
    }
  }

  REP(i,n) COUT(ans[i]);
  return 0;
}
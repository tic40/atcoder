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
const int INF = 2e9;
const int MOD = 1e9+7;
const ll LINF = 1LL<<62;

int x[60], y[60];

int main() {
  IOS;

  int n,K;
  cin >> n >> K;
  ll ans = LINF;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  REP(i,n) {
    REP(j,n) {
      REP(k,n) {
        REP(l,n) {
          int cnt = 0;
          int lx = min(x[i],x[j]);
          int hx = max(x[i],x[j]);
          int ly = min(y[k],y[l]);
          int hy = max(y[k],y[l]);
          REP(m,n) {
            if (lx <= x[m] && x[m] <= hx && ly <= y[m] && y[m] <= hy) cnt++;
            if (K <= cnt) {
              ans = min(ans, (ll)(hx - lx) * (ll)(hy - ly));
              break;
            }
          }
        }
      }
    }
  }

  COUT(ans);
  return 0;
}
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
vector<ll> a,b;

void solve() {
  vector<pair<ll,int>> p(n);
  ll aoki = 0, takahashi = 0;
  REP(i,n) {
    p[i] = { a[i]*2+b[i], i };
    aoki += a[i];
  }

  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());

  int ans = 0;
  REP(i,n) {
    ans++;
    int idx = p[i].second;
    aoki -= a[idx];
    takahashi += a[idx]+b[idx];
    if (aoki < takahashi) break;
  }
  COUT(ans);
  return ;
}

int main() {
  IOS;
  cin >> n;
  a.resize(n); b.resize(n);
  REP(i,n) { cin >> a[i] >> b[i]; }

  solve();
  return 0;
}
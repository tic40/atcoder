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

ll N,C;
vector<ll> a,b,c;

void solve() {
  map<int, ll> events;
  REP(i,N) {
    events[a[i]]+=c[i];
    events[b[i]+1]-=c[i];
  }

  ll ans = 0, s = 0;
  int pre = 0;
  for(auto v: events) {
    ans += (v.first - pre) * min(C,s);
    s += v.second;
    pre = v.first;
  }
  COUT(ans);
  return;
}

int main() {
  IOS;
  cin >> N >> C;
  a.resize(N); b.resize(N); c.resize(N);

  REP(i,N) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
  }

  solve();
  return 0;
}
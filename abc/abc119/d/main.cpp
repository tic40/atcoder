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

vector<ll> s, t;

ll solve(ll x) {
  ll ans = LINF;
  ll cur, sum, move;
  auto reset = [&](){ sum = 0; cur = x; };

  REP(bit,4) {
    REP(i,2) {
      reset(); swap(s,t);
      int first = bit >> 0 & 1, second = bit >> 1 & 1;
      move = *(upper_bound(s.begin(), s.end(), cur) - first);
      sum += abs(cur-move);
      cur = move;

      move = *(upper_bound(t.begin(), t.end(), cur) - second);
      sum += abs(cur-move);
      chmin(ans, sum);
    }
  }
  return ans;
}

int main() {
  IOS;
  int a,b,q;
  cin >> a >> b >> q;
  s.resize(a); t.resize(b);
  REP(i,a) cin >> s[i];
  REP(i,b) cin >> t[i];
  // 突き抜けないように番兵を置く
  const ll MX = 1e15;
  s.push_back(MX); s.push_back(-MX);
  t.push_back(MX); t.push_back(-MX);
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());

  REP(i,q) {
    ll x; cin >> x;
    COUT(solve(x));
  }

  return 0;
}
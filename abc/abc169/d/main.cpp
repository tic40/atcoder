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
template<class T>bool CHMAX(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool CHMIN(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

vector<pair<ll, ll>> prime_factor(ll n) {
  vector<pair<ll,ll>> res;
  for (ll a = 2; a * a <= n; a++) {
    if (n % a != 0) continue;
    ll ex = 0;
    while (n % a == 0) { ++ex; n /= a; }
    res.push_back({a, ex});
  }

  if (n != 1) res.push_back({n, 1});
  return res;
}

ll counter(ll n){
  ll ans = 0;
  for(ll i=1; i<=n; i++) { n-=i; ans++; }
  return ans;
}

int main(){
  IOS;
  ll n; cin >> n;
  auto l = prime_factor(n);

  ll ans = 0;
  for (pair<ll,ll>x: l) ans += counter(x.second);
  COUT(ans);
  return 0;
}
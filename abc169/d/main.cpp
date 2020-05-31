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

ll prime_fac(ll n, vector<pair<ll, ll>>&l){
  ll r, s = floor(sqrt(n));
  pair<ll,ll> x;
  for (ll i=2; i<=s; i++) {
    if(n%i == 0){
      r = 0;
      do {
        r++;
        n /= i;
      } while(n%i == 0);
      x = make_pair(i, r);
      l.push_back(x);
    }
  }
  if(n > s){
    x = make_pair(n, 1);
    l.push_back(x);
  }
  return l.size();
}

ll counter(ll n){
  ll ans = 0;
  for(ll i=1; i<=n; i++) { n-=i; ans++; }
  return ans;
}

int main(){
  IOS;

  ll n; cin >> n;
  vector<pair<ll,ll>> l;
  prime_fac(n, l);

  ll ans = 0;
  for (pair<ll,ll>x: l) ans += counter(x.second);
  COUT(ans);
  return 0;
}
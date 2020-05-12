#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x)  cout << #x << " = " << (x) << endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  ll n;
  ll k;
  cin >> n >> k;
  ll a[n];
  REP(i,n) {
    cin >> a[i];
    a[i]--;
  }

  ll nv = 0;
  if (k <= 200000) {
    REP(i,k) {
      nv = a[nv];
    }
    COUT(nv+1);
    return 0;
  }

  vector<ll> x;
  vector<ll> hist(n,0);
  REP(i,k) {
    x.push_back(nv);
    hist[nv]++;
    if (hist[nv] == 2) { break; }
    nv = a[nv];
  }

  ll loop = 0;
  vector<ll> loopx;
  for (ll i = x.size()-2; i >= 0; i--) {
    loop++;
    loopx.push_back(x[i]);
    if (x[i] == nv) {
      break;
    }
  }
  ll beforeloop = x.size() - 1 - loop;
  reverse(loopx.begin(), loopx.end());
  COUT(loopx[ (k - beforeloop) % loop]+1);
  return 0;
}
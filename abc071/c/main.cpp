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
  ll n; cin >> n;
  ll a[n]; REP(i,n) cin >> a[i];
  sort(a,a+n,greater<ll>());

  ll x=0;
  REP(i,n-1) {
    if (a[i] == a[i+1]) {
      if (x > 0) { cout << x * a[i] << endl; return 0; }
      x = a[i];
      i++;
    }
  }
  cout << 0 << endl;
}
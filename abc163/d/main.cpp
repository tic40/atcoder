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
  ll n, k; cin >> n >> k;
  ll ans = 0;
  for (ll i = k; i <= n+1; i++) {
    ll left = (0+i-1)*i/2;
    ll right = ((n-(i-1))+n)*i/2;
    ans += right-left+1;
  }
  COUT(ans % MOD);
  return 0;
}
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
  ll n; string s; cin >> n >> s;
  map<char, ll> m;
  for(auto c : s) {
    if (m[c]) m[c]++;
    else m[c]=1;
  }
  ll ans = m['R']*m['G']*m['B'];
  ll sub = 0;
  for (ll j = 0; j < n; j++) {
    for (ll k = 0; k < n; k++) {
      ll i = 2*j-k;
      if (i >= n || i < 0) continue;
      if (i >= j || j >= k) continue;
      bool ok = (s[i] != s[j]) && (s[i] != s[k]) && (s[j] != s[k]);
      if (ok) sub++;
    }
  }
  ans-=sub;
  cout << ans << endl;
  return 0;
}
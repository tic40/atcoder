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

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }

int main() {
  int K; cin >> K;
  ll ans = 0;
  for(int i = 1; i <= K; i++) {
    for(int j = 1; j <= K; j++) {
      for(int k = 1; k <= K; k++) {
        ans += gcd(i,gcd(j,k));
      }
    }
  }
  COUT(ans);
  return 0;
}

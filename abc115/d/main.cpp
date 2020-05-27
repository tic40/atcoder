#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x) cout<<#x<<" = "<<(x)<<endl;
#define Yes(x) cout<<(x?"Yes":"No")<<endl;
#define YES(x) cout<<(x?"YES":"NO")<<endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

ll N,X;
ll a[51],p[51]; // a: 層の総数, p: パティの総数

ll solve(ll n, ll x) {
  if (n==0) return x>0 ? 1 : 0;

  if (x <= 1 + a[n-1]) return solve(n-1,x-1);

  return p[n-1] + 1 + solve(n-1,x-2-a[n-1]);
}

int main() {
  cin >> N >> X;
  a[0] = 1; p[0] = 1;
  for(int i = 1; i < N; i++) {
    a[i] = a[i-1]*2+3;
    p[i] = p[i-1]*2+1;
  }
  COUT(solve(N,X));
  return 0;
}

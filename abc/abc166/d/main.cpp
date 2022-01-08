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

ll f(ll a, ll n) {
  if (n == 0) return 1;
  ll x = f(a, n/2);
  x *= x;
  if (n % 2 == 1) x *= a;
  return x;
}

int main() {
  ll x; cin >> x;

  for (int i = -2000; i <= 2000; i++) {
    for (int j = -2000; j <= 2000; j++) {
      ll a=f(i,5);
      ll b=f(j,5);
      if (x == (a-b)) {
        printf("%d %d\n",i,j);
        return 0;
      }
    }
  }
  return 0;
}
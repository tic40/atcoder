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

int gcd(int a, int b) { return b?gcd(b,a%b):a; }

int main() {
  int n; cin >> n;
  int x[n+1]; REP(i,n+1) cin >> x[i];
  sort(x, x+n+1);

  int ans = x[1]-x[0];
  for (int i = 1 ; i < n+1; i++) {
    int diff = x[i] - x[i-1];
    ans = gcd(ans,diff);
  }
  COUT(ans);
  return 0;
}

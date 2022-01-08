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
  int n; cin >> n;
  int a[n],b[n];
  REP(i,n) {
    cin >> a[i];
    b[i]=a[i]-(i+1);
  }

  sort(b,b+n);
  int med = n%2 ? b[n/2] : (b[n/2] + b[n/2-1]) / 2;
  ll ans=0;
  REP(i,n) ans += abs(a[i] - (med+i+1));
  COUT(ans);

  return 0;
}

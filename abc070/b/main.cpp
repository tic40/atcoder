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

int ar[101];
int main() {
  int a,b,c,d; cin >> a >> b >> c >> d;
  int ans = 0;
  for(int i=a; i<b; i++) ar[i]++;
  for(int i=c; i<d; i++) ar[i]++;
  REP(i,101) if (ar[i] == 2) ans++;
  cout << ans << endl;
  return 0;
}

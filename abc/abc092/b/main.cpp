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
  int n,d,x; cin >> n >> d >> x;
  int a,ans = 0;
  REP(i,n) {
    cin >> a;
    REP(i,d) {
      if (a*i+1 > d) break;
      ans++;
    }
  }
  COUT(ans + x);
  return 0;
}

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
  int n,k; cin >> n >> k;
  int ans = INF;
  REP(bit, 1<<n) {
    int num = 1;
    REP(i, n) {
      if (bit >> i & 1) num*=2;
      else num+=k;
    }
    ans = min(ans, num);
  }
  COUT(ans);
  return 0;
}

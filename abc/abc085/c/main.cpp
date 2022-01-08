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
  int n,y; cin >> n >> y;

  REP(i,n+1) {
    REP(j,n+1) {
      int k = (y - (10000*i + 5000*j)) / 1000;
      if (k >= 0 && i+j+k == n) {
        printf("%d %d %d", i,j,k);
        return 0;
      }
    }
  }
  printf("-1 -1 -1");
  return 0;
}

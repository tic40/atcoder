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
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  bool t = true;
  while(1) {
    if (t) {
      c-=b;
    } else {
      a-=d;
    }
    if (a <= 0 || c <= 0) break;
    t = !t;
  }
  COUT(t ? "Yes" : "No");
  return 0;
}

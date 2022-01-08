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
  int n,m,x;
  cin >> n >> m >> x;
  int a;
  vector<int> gate(n+1, 0);
  REP(i,m) { cin >> a; gate[a]=1; }

  int left=0,right=0;
  REP(i,x) if (gate[x-i]) left++;
  REP(i,n-x) if (gate[x+i]) right++;
  COUT(min(left,right));
  return 0;
}

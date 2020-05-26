#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x) cout<<#x<<" = "<<(x)<<endl;
#define Yes(x) cout<<(x?"Yes":"No")<<endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n,d;
vector<int> nums;

int getDigit(int num) {
  int digit = 0;
  while(num!=0) { num/=10; digit++; }
  return digit;
}

void dfs(vector<int> v) {
  if (v.size() == d) return;

  for(int i: {3,5,7}) {
    vector<int> nv = v;
    nv.push_back(i);

    int x = 0;
    REP(j,nv.size()) x += nv[j] * pow(10,j);
    nums.push_back(x);

    dfs(nv);
  }
}

int main() {
  cin >> n; d = getDigit(n);
  dfs(vector<int>());

  int ans = 0;
  for(int num: nums) {
    if (num > n) continue;
    M m;
    while(num>0) {
      m[num % 10]++;
      num/=10;
    }
    if (m[3] > 0 && m[5] > 0 && m[7] > 0) ans++;
  }
  COUT(ans);
  return 0;
}
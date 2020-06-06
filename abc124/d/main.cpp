#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i, n) for(int i=0;i<n;i++)
#define YES(x) cout<<(x?"YES":"NO")<<"\n"
#define Yes(x) cout<<(x?"Yes":"No")<<"\n"
#define dump(x) cout<<#x<<" = "<<(x)<<"\n"
#define endl "\n"
using G = vector<vector<int>>;
using M = map<int,int>;
using P = pair<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int,vector<int>,greater<int>>;
using V = vector<int>;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  IOS;
  int n,k; cin >> n >> k;
  string s; cin >> s;

  vector<int> nums;
  int cnt = 0;
  int now = 1;
  REP(i, n) {
    if (s[i]-'0' == now) cnt++;
    else {
      nums.push_back(cnt);
      now ^= 1; // 0と1を切り替える
      cnt = 1;
    }
  }
  if (cnt != 0) nums.push_back(cnt);

  // 1-0-1-0-1 の配列がほしい. 1-0-1-0のように0で終わっていたら1つ足す
  if (nums.size() % 2 == 0) nums.push_back(0);

  int add = 2*k+1; // 1-0-1-0-1 の配列になっているため
  int ans = 0;

  // 累積和
  vector<int> sum(nums.size()+1, 0);
  REP(i,nums.size()) sum[i+1] = sum[i]+nums[i];

  for(int i = 0; i < nums.size(); i+=2) {
    int left = i;
    int right = min(i+add, (int)nums.size());
    int tmp = sum[right] - sum[left];

    chmax(ans,tmp);
  }

  /*
  // しゃくとり法
  int left=0, right=0;
  int tmp = 0; // [left, right) の sum
  // 1-0-1... の偶数番目だけみる
  for (int i = 0; i < nums.size(); i+=2) {
    int nextL = i;
    int nextR = min(i+add, (int)nums.size());
    while(nextL > left) {
      tmp -= nums[left];
      left++;
    }
    while(nextR > right) {
      tmp += nums[right];
      right++;
    }
    chmax(ans,tmp);
  }
  */
  COUT(ans);
  return 0;
}

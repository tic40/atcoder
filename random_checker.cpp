#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// ランダムテストケース作成
void random_generate(int N, vector<int> &A) {
  REP(i,N) A[i] = rand() % 10 + 1;
  return;
}

int solve_jury(int N, vector<int> &A) {
    int ans = -(1 << 30);
    REP(i,N) {
      for (int j = i + 1; j < N; j++) ans = max(ans, A[j] - A[i]);
    }
    return ans;
}

int solve(int N, vector<int> &A) {
    int ans = 0, curMin = A[0];
    for (int i = 1; i < N; i++) {
        ans = max(ans, A[i] - curMin);
        curMin = min(curMin, A[i]);
    }
    return ans;
}

int main() {
  REP(t, 1000) {
    int N = 5;
    vector<int> A(N);
    random_generate(N,A);

    int j1 = solve(N,A);
    int j2 = solve_jury(N,A);

    if (j1 != j2) {
      cout << "Wrong ans on Test #" << t << endl;
      cout << "Jury = " << j2 << ", Output = " << j1 << endl;
      cout << N << endl;
      REP(i,N) {
        if (i >= 1) cout << " ";
        cout << A[i];
      }
      cout << endl;
      return 0;
    }
  }
  cout << "Yay!" << endl;
  return 0;
}
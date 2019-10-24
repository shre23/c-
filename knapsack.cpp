#include <bits/stdc++.h>
#define speedio                                                                \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);

using namespace std;

typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<pii> vpi;

#define pb push_back
#define mod 1000000007
#define mini INT_MIN
#define maxo INT_MAX
#define eb emplace_back
#define ff first
#define ss second
#define re return
#define en "\n"
#define en "\n"

#define all(c) c.begin(), c.end()
#define mem(a, val) memset(a, val, sizeof(a))
#define mk(x, y) make_pair(x, y)
#define min3(x, y, z) min(min(x, y), (z))
#define max3(x, y, z) max(max(x, y), (z))
#define mid(s, e) ((s) + ((e) - (s)) / 2)

#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define F(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define RF(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define read(a, n)                                                             \
  for (int i = 0; i < n; i++)                                                  \
    cin >> a[i];
#define show(a, n)                                                             \
  for (int i = 0; i < n; i++)                                                  \
    cout << a[i] << ' ';                                                       \
  cout << endl;
#define p2(n) 1LL << n;

// KNAPSACK

const int maxn = 1e5 + 5;
int wt[maxn];
int val[maxn];
// W is the capacity and n is the no of items in the bag
// This method simply uses recursion (Note you can memoization very easily
// [handle the base cases first])
int knapsack(int n, int W) {
  if (n == 0 or W == 0)
    return 0;
  else if (wt[n - 1] > W)
    return knapsack(n - 1, W);
  else
    return max(knapsack(n - 1, W), val[n - 1] + knapsack(n - 1, W - wt[n - 1]));
}

void solve() {
  int N, W;
  cin >> N >> W;
  F(i, 0, N - 1) cin >> val[i];
  F(i, 0, N - 1) cin >> wt[i];

  // Method 1
  cout << knapsack(N, W) << ' ';

  // Method 2 (Bottom Up DP)
  int knapS[N + 1][W + 1];

  for (int n = 0; n <= N; n++) {
    for (int w = 0; w <= W; w++) {

      if (n == 0 or w == 0)
        knapS[n][w] = 0;
      else if (wt[n - 1] > w)
        knapS[n][w] = knapS[n - 1][w];
      else
        knapS[n][w] = max(knapsack(n - 1, w),
                          val[n - 1] + knapsack(n - 1, w - wt[n - 1]));
    }
  }
  cout << knapS[N][W] << endl;

  // Here comes the tricky part, i.e. printing the items selected in the
  // knapsack (see gfg printing 0-1 knap..)
  int res = knapS[N][W];

  int w = W;

  for (int i = N; i > 0 && res > 0; i--) {
    if (res == knapS[i - 1][w])
      continue;
    else {
      // printing weight (can be print value also)
      cout << val[i - 1] << ' ';
      res = res - val[i - 1];
      w = w - wt[i - 1];
    }
  }
}

//====================================================================

int main() {
  speedio;

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  // cin >> t;

  while (t--)
    solve();

  cout << "\n\n";

  re 0;
}


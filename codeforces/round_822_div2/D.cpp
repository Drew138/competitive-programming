#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;  // int vec
typedef vector<vi> vvi;  // int vec vec
typedef vector<pii> vpi; // int int pair vec

const double pi = 3.1415926535897932384626433832795;
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

#define d(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forab(i, a, b) for (int i = a; i < (int)b; ++i)
#define foreach(a, b) for (auto &(a) : (b))
#define formap(map) for (const auto &[key, value] : map)
#define all(v) v.begin(), v.end()
#define allar(arr, sz) arr, arr + sz
#define ms(ar, val) memset(ar, val, size)
#define pq(type) priority_queue<type>
#define pqd(type) priority_queue<type, vector<type>, greater<type>>
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define nl "\n"
#define in(t) while (t--)

void solve();

int main() { solve(); }

#define int long long

void solve() {
  ios int t;
  cin >> t;
  in(t) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    forn(i, n) cin >> arr[i];

    int cur_right = arr[k - 1], cur_left = arr[k - 1];
    int max_right = arr[k - 1], max_left = arr[k - 1];
    int i = k - 1, j = k - 1;
    while (i > 0 && j < n - 1) {
      if (cur_left + arr[i - 1] >= 0) {
        cur_left = cur_left + arr[i - 1];
        max_left = max(max_left, cur_left);
        i--;
      } else if (cur_right + arr[j + 1] >= 0) {
        cur_right = cur_right + arr[j + 1];
        max_right = max(max_right, cur_right);
        j++;
      } else if ((arr[i - 1] + max_right + cur_left - arr[k - 1]) >= 0) {
        cur_left = cur_left + arr[i - 1];
        max_left = max(max_left, cur_left);
        i--;
      } else if ((arr[j + 1] + max_left + cur_right - arr[k - 1]) >= 0) {
        cur_right = cur_right + arr[j + 1];
        max_right = max(max_right, cur_right);
        j++;
      } else {
        break;
      }
    }

    bool ans = i == 0 || j == n - 1;

    cout << (ans ? "YES" : "NO") << nl;
  }
}

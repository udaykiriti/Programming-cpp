/**
 * Problem: D1. Inverse Minimum Partition (Easy Version)
 * Language: C++20
 * Approach: Dynamic Programming + Monotonic Stack + Segment Tree + Sqrt Decomposition
 * Time Complexity: O(N * sqrt(N) * log N) roughly, optimized with pruning.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

// Segment Tree for Range Minimum Query on Stack
// Stores minimum 'dp' value in the stack ranges
struct SegTree {
    int n;
    vector<long long> tree;
    const long long INF = 2e18; // Sufficiently large value

    SegTree(int max_n) : n(max_n) {
        tree.assign(4 * n, INF);
    }

    // Reset function isn't strictly necessary if we overwrite, 
    // but good for cleanliness if needed. Here we just overwrite.

    void update(int node, int start, int end, int idx, long long val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return INF;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return min(query(2 * node, start, mid, l, r),
                   query(2 * node + 1, mid + 1, end, l, r));
    }

    void set(int idx, long long val) {
        update(1, 0, n - 1, idx, val);
    }

    long long get_min(int l, int r) {
        if (l > r) return INF;
        return query(1, 0, n - 1, l, r);
    }
};

// Global or static SegTree to avoid reallocation
// Max N is 400,000
static SegTree st(400005);

struct StackItem {
    long long val;
    long long min_dp;
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<StackItem> stack;
    stack.reserve(n);
    
    long long dp_val = 0; // dp[0] = 0
    
    for (int i = 0; i < n; ++i) {
        long long val = a[i];
        long long current_min_dp = dp_val;
        
        // Monotonic Stack Maintenance
        while (!stack.empty() && stack.back().val >= val) {
            current_min_dp = min(current_min_dp, stack.back().min_dp);
            stack.pop_back();
        }
        
        stack.push_back({val, current_min_dp});
        st.set(stack.size() - 1, current_min_dp);
        
        long long best_ans = dp_val + 1; // Base case
        
        // Optimization: sqrt decomposition on values
        long long cutoff = sqrt(val);
        
        // 1. Iterate distinct costs k for large v (v > cutoff)
        // The cost k = ceil(val/v). Since v > sqrt(val), k <= sqrt(val).
        // We limit k up to 'best_ans' for pruning.
        
        if (!stack.empty()) {
            long long min_stack_val = stack[0].val;
            // Maximum possible k we care about is best_ans.
            // Also k is bounded by roughly val / min_stack_val + 1
            
            long long limit_k = best_ans;
            
            for (long long k = 1; k <= limit_k; ++k) {
                // Range of v for cost k:
                // ceil(val / v) == k  =>  k-1 < val/v <= k
                // v <= val / (k-1)  (for k>1)
                // v >  val / k      => v >= floor((val)/k) + 1 ? No.
                // v >= floor((val-1)/k) + 1
                
                long long L = (val - 1) / k + 1;
                long long R = (k == 1) ? 2000000000000000000LL : (val - 1) / (k - 1);
                
                // We only care about v > cutoff
                if (R <= cutoff) break; // Since R decreases as k increases, we can stop
                
                long long query_L = max(L, cutoff + 1);
                long long query_R = R;
                
                if (query_L > query_R) continue;
                if (query_R < min_stack_val) break; // Values in stack are too large for this small v (large k)

                // Find range in stack
                // We need indices of stack items with val in [query_L, query_R]
                
                StackItem key;
                key.val = query_L;
                
                // lower_bound: first element >= query_L
                auto it_l = lower_bound(stack.begin(), stack.end(), key, 
                    [](const StackItem& item, const StackItem& val) {
                        return item.val < val.val;
                    });
                
                if (it_l == stack.end()) continue;
                // If the found element is already outside range
                if (it_l->val > query_R) continue;
                
                int l_idx = (int)(it_l - stack.begin());
                
                key.val = query_R;
                // upper_bound: first element > query_R
                auto it_r = upper_bound(stack.begin(), stack.end(), key, 
                    [](const StackItem& val, const StackItem& item) {
                        return val.val < item.val;
                    });
                
                int r_idx = (int)(it_r - stack.begin()) - 1;
                
                if (l_idx <= r_idx) {
                    long long m = st.get_min(l_idx, r_idx);
                    if (m != st.INF) {
                        if (m + k < best_ans) {
                            best_ans = m + k;
                            limit_k = best_ans; // Pruning
                        }
                    }
                }
            }
        }
        
        // 2. Iterate stack for small v (v <= cutoff)
        // These are at most 'cutoff' distinct values in the stack? 
        // Not necessarily distinct in stack, but stack is monotonic, so values are distinct.
        // At most 'cutoff' elements to check.
        
        StackItem key_cutoff;
        key_cutoff.val = cutoff;
        auto it_cutoff = upper_bound(stack.begin(), stack.end(), key_cutoff,
            [](const StackItem& val, const StackItem& item) {
                return val.val < item.val;
            });
            
        // Elements from beginning up to it_cutoff (exclusive) have val <= cutoff
        // Actually, iterating from largest v (closest to cutoff) downwards is usually better for pruning?
        // But 'm' is not monotonic.
        // However, stack is sorted by val.
        // Iterate backwards from it_cutoff-1 down to 0.
        
        int limit_idx = (int)(it_cutoff - stack.begin());
        for (int j = limit_idx - 1; j >= 0; --j) {
            long long v = stack[j].val;
            long long m = stack[j].min_dp;
            
            // Calculate cost
            long long k = (val + v - 1) / v;
            
            if (m + k < best_ans) {
                best_ans = m + k;
            } else {
                // Optimization:
                // As we go left in stack, v decreases, so k = ceil(val/v) increases significantly.
                // m usually decreases or stays similar (since min_dp is min of a range).
                // But if m + k is already > best_ans and k is growing fast...
                // It's not guaranteed we can break, but often possible.
                // However, strict correctness requires checking.
                // Given the constraint v <= cutoff, there are at most sqrt(val) items.
                // This loop is safe without break.
            }
        }
        
        dp_val = best_ans;
    }
    
    cout << dp_val << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    vi corpFlightBookings(vvi &bookings, int n) {
        vi ans(n, 0);
        vi dif(n, 0);

        // adjacent_difference(ans.begin(), ans.end(), dif.begin());

        for (auto &booking : bookings) {
            int l = booking[0] - 1;
            int r = booking[1] - 1;
            int x = booking[2];

            dif[l] += x;
            if (r + 1 < n) dif[r + 1] -= x;
        }

        partial_sum(dif.begin(), dif.end(), ans.begin());

        return ans;
    }
};

int main() {
    vvi input1 = {
            {1, 2, 10},
            {2, 3, 20},
            {2, 5, 25}
    };
    int n = 5;

    auto ans = Solution().corpFlightBookings(input1, n);

    auto printvi = [](vi &v) -> void {
        for (auto i : v)
            cout << i << ' ';
    };

    printvi(ans);
}
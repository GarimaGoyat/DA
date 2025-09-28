#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    int low = 0;
    int high = n - 2;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == mid + 1) {
            // All numbers to the left are correct, so search in the right half.
            low = mid + 1;
        } else {
            // A mismatch is found. This could be the answer.
            // Store it and check if an earlier mismatch exists in the left half.
            ans = mid + 1;
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
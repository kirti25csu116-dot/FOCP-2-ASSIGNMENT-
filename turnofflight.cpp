#include <bits/stdc++.h>
using namespace std;

bool can(string &s, int n, int k, int x) {
    int operations = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            operations++;
            i += (x - 1); // skip next x-1 positions
        }
    }

    return operations <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int left = 1, right = n;
    int answer = n;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(can(s, n, k, mid)) {
            answer = mid;
            right = mid - 1; // try smaller
        } else {
            left = mid + 1;
        }
    }

    cout << answer << "\n";
    return 0;
}



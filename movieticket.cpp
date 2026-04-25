#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    unordered_map<int, unordered_set<int>> movieUsers;
    unordered_map<int, int> ticketsLeft;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            int X, Y;
            cin >> X >> Y;

            // Initialize if not exists
            if (!ticketsLeft.count(Y)) {
                ticketsLeft[Y] = 100;
            }

            // Check conditions
            if (movieUsers[Y].count(X) || ticketsLeft[Y] == 0) {
                cout << "false\n";
            } else {
                movieUsers[Y].insert(X);
                ticketsLeft[Y]--;
                cout << "true\n";
            }
        }

        else if (query == "CANCEL") {
            int X, Y;
            cin >> X >> Y;

            if (!movieUsers[Y].count(X)) {
                cout << "false\n";
            } else {
                movieUsers[Y].erase(X);
                ticketsLeft[Y]++;
                cout << "true\n";
            }
        }

        else if (query == "IS_BOOKED") {
            int X, Y;
            cin >> X >> Y;

            if (movieUsers[Y].count(X))
                cout << "true\n";
            else
                cout << "false\n";
        }

        else if (query == "AVAILABLE_TICKETS") {
            int Y;
            cin >> Y;

            if (!ticketsLeft.count(Y))
                cout << 100 << "\n";
            else
                cout << ticketsLeft[Y] << "\n";
        }
    }

    return 0;
}
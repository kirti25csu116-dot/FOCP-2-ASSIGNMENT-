#include <bits/stdc++.h>
using namespace std;

class Bank {
    unordered_map<int, int> balance;

public:

    bool CREATE(int X, int Y) {
        if (balance.count(X)) {
            balance[X] += Y;
            return false;
        }
        balance[X] = Y;
        return true;
    }

    bool DEBIT(int X, int Y) {
        if (!balance.count(X) || balance[X] < Y)
            return false;

        balance[X] -= Y;
        return true;
    }

    bool CREDIT(int X, int Y) {
        if (!balance.count(X))
            return false;

        balance[X] += Y;
        return true;
    }

    int BALANCE(int X) {
        if (!balance.count(X))
            return -1;

        return balance[X];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    Bank bank;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            int X, Y;
            cin >> X >> Y;
            cout << (bank.CREATE(X, Y) ? "true" : "false") << "\n";
        }
        else if (query == "DEBIT") {
            int X, Y;
            cin >> X >> Y;
            cout << (bank.DEBIT(X, Y) ? "true" : "false") << "\n";
        }
        else if (query == "CREDIT") {
            int X, Y;
            cin >> X >> Y;
            cout << (bank.CREDIT(X, Y) ? "true" : "false") << "\n";
        }
        else if (query == "BALANCE") {
            int X;
            cin >> X;
            cout << bank.BALANCE(X) << "\n";
        }
    }

    return 0;
}
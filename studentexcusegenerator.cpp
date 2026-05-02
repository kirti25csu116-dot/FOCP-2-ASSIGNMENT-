#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed random generator (important for different output)
    srand(time(0));

    string name;
    cout << "Enter student name: ";
    cin >> name;

    // 10+ excuse templates
    vector<string> excuses = {
        "{name} couldn't complete the assignment because the laptop battery died unexpectedly.",
        "{name} tried finishing the homework, but the internet stopped working.",
        "{name} was ready to submit the assignment when the file mysteriously disappeared.",
        "{name} could not  finish the assignment because the laptop started updating for hours.",
        "{name} was about to complete homework when the Wi-Fi suddenly vanished.",
        "{name} tried typing the assignment, but the keyboard stopped working.",
        "{name} lost the assignment file due to a sudden system crash.",
        "{name} was preparing the homework when there was a power cut.",
        "{name} accidentally deleted the assignment before submitting it.",
        "{name} was about to submit, but the system froze completely."
    };

    // Random index
    int index = rand() % excuses.size();

    string excuse = excuses[index];

    // Replace {name} with actual name
    size_t pos = excuse.find("{name}");
    if (pos != string::npos) {
        excuse.replace(pos, 6, name);
    }

    // Output
    cout << "\nGenerated Excuse:\n";
    cout << excuse << endl;

    return 0;
}


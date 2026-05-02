#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

using namespace std;

int main() {
    // Step 1: Ask the user for their name
    cout << "Enter your name: ";
    string name;
    getline(cin, name);

    // Step 2: Handle edge case - empty input
    if (name.empty()) {
        cout << "Please enter a valid name." << endl;
        return 0; // Exit program early
    }

    // Step 3: Store roast templates with {name} placeholder
    vector<string> roasts = {
        "{name}, you procrastinate so much, even your code waits for you to compile it.",
        "{name}, your WiFi signal is stronger than your motivation.",
        "{name}, you debug like You're slower than a snail.",
        "{name}, you have more unfinished assignments than Netflix has shows.",
        "{name}, even your coffee needs coffee to deal with you.",
        "{name}, your code runs… away from you.",
        "{name}, you treat deadlines like suggestions.",
        "{name}, your laptop fan works harder than you do.",
        "{name}, you proof that Ctrl+C and Ctrl+V are survival skills.",
        "{name}, even your dreams have TODO comments."
    };

    // Step 4: Seed random number generator with current time
    srand(time(0));

    // Step 5: Pick a random roast
    int randomIndex = rand() % roasts.size();

    // Step 6: Replace {name} with actual user input
    string roast = roasts[randomIndex];
    size_t pos = roast.find("{name}");
    if (pos != string::npos) {
        roast.replace(pos, 6, name); // Replace "{name}" (6 characters) with user input
    }

    // Step 7: Display the roast
    cout << roast << endl;

    return 0;
}

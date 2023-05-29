#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    map<int, int> counts;
    set<int> exclude = { 0, 1, 2 };

    cout << "Enter integer values (ctrl + z to end or 'r' to see repetitions):\n";
    int value;
    while (cin >> value) {
        if (exclude.count(value)) {
            cout << "Number " << value << " is excluded.\n";
        } else {
            counts[value]++;
        }
    }

    cout << "Repetitions of each value:\n";
    for (const auto& [value, count] : counts) {
        cout << value << ": " << count << endl;
    }

    return 0;
}

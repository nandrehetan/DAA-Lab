#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> recentEntries;

    while (true) {
        int newData;
        cout << "Enter a new data point (-1 to exit): ";
        cin >> newData;

        if (newData == -1)
            break;

        recentEntries.push_back(newData);

        if (recentEntries.size() > 10)
            recentEntries.pop_front();

        int maxEntry = recentEntries.front();
        for (int i = 1; i < recentEntries.size(); ++i) {
            if (recentEntries[i] > maxEntry)
                maxEntry = recentEntries[i];
        }

        cout << "Maximum of all current entries: " << maxEntry << endl;
    }

    return 0;
}

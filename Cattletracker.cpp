
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

// Graph class to manage location connections
class Graph {
public:
    map<string, vector<string>> adj;

    void addEdge(string from, string to) {
        adj[from].push_back(to);
        adj[to].push_back(from); // Undirected graph
    }

    void displayGraph() {
        cout << "\n--- Location Map ---\n";
        for (auto &node : adj) {
            cout << node.first << " -> ";
            for (string &neighbor : node.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    bool locationExists(string loc) {
        return adj.find(loc) != adj.end();
    }
};

// CattleTracker class to track movement history
class CattleTracker {
    map<int, vector<string>> cattleHistory;

public:
    void registerMovement(int cattleID, string location) {
        cattleHistory[cattleID].push_back(location);
    }

    void displayMovement(int cattleID) {
        cout << "\n--- Movement for Cattle ID " << cattleID << " ---\n";
        if (cattleHistory.count(cattleID)) {
            for (string &loc : cattleHistory[cattleID]) {
                cout << loc << " -> ";
            }
            cout << "END" << endl;
        } else {
            cout << "No movement history found.\n";
        }
    }

    void displayAllMovements() {
        cout << "\n--- All Cattle Movements ---\n";
        for (auto &entry : cattleHistory) {
            cout << "Cattle " << entry.first << ": ";
            for (string &loc : entry.second) {
                cout << loc << " -> ";
            }
            cout << "END\n";
        }
    }
};

// Main menu and program logic
int main() {
    Graph g;
    CattleTracker tracker;
    int choice;

    cout << "=== Cattle Movement Tracker ===\n";

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Path Between Locations\n";
        cout << "2. Show Location Graph\n";
        cout << "3. Register Cattle Movement\n";
        cout << "4. Show Movement of One Cattle\n";
        cout << "5. Show All Cattle Movements\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string from, to;
            cout << "Enter first location: ";
            cin >> from;
            cout << "Enter second location: ";
            cin >> to;
            g.addEdge(from, to);
            cout << "Path added between " << from << " and " << to << ".\n";
        }
        else if (choice == 2) {
            g.displayGraph();
        }
        else if (choice == 3) {
            int id;
            string location;
            cout << "Enter Cattle ID: ";
            cin >> id;
            cout << "Enter current location: ";
            cin >> location;

            if (!g.locationExists(location)) {
                cout << "Location does not exist in the graph. Please add it first.\n";
            } else {
                tracker.registerMovement(id, location);
                cout << "Movement recorded.\n";
            }
        }
        else if (choice == 4) {
            int id;
            cout << "Enter Cattle ID: ";
            cin >> id;
            tracker.displayMovement(id);
        }
        else if (choice == 5) {
            tracker.displayAllMovements();
        }
        else if (choice == 6) {
            cout << "Exiting program. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

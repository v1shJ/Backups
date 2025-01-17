#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

// Single-Level Directory
class SingleLevel {
private:
    vector<string> files;

public:
    void createFile(const string& fileName) {
        files.push_back(fileName);
        cout << "File '" << fileName << "' created.\n";
    }

    void listFiles() {
        cout << "Files in Single-Level Directory:\n";
        for (const auto& file : files) {
            cout << file << endl;
        }
    }
};

// Two-Level Directory
class TwoLevel {
private:
    map<string, vector<string>> userDirectories;

public:
    void createFile(const string& user, const string& fileName) {
        userDirectories[user].push_back(fileName);
        cout << "File '" << fileName << "' created in user '" << user << "' directory.\n";
    }

    void listFiles(const string& user) {
        if (userDirectories.count(user)) {
            cout << "Files in '" << user << "' directory:\n";
            for (const auto& file : userDirectories[user]) {
                cout << file << endl;
            }
        } else {
            cout << "No directory found for user '" << user << "'.\n";
        }
    }
};

// Hierarchical Directory
class Hierarchical {
private:
    map<string, vector<string>> directories;

public:
    void createDirectory(const string& dirName) {
        directories[dirName] = {};
        cout << "Directory '" << dirName << "' created.\n";
    }

    void createFile(const string& dirName, const string& fileName) {
        if (directories.count(dirName)) {
            directories[dirName].push_back(fileName);
            cout << "File '" << fileName << "' created in '" << dirName << "' directory.\n";
        } else {
            cout << "Directory '" << dirName << "' does not exist.\n";
        }
    }

    void listDirectory(const string& dirName) {
        if (directories.count(dirName)) {
            cout << "Files in directory '" << dirName << "':\n";
            for (const auto& file : directories[dirName]) {
                cout << file << endl;
            }
        } else {
            cout << "Directory '" << dirName << "' does not exist.\n";
        }
    }
};

// Main Function
int main() {
    SingleLevel singleDir;
    TwoLevel twoDir;
    Hierarchical hierarchy;

    int choice;
    do {
        cout << "\nChoose File Organization Technique:\n";
        cout << "1. Single-Level Directory\n";
        cout << "2. Two-Level Directory\n";
        cout << "3. Hierarchical Directory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int singleChoice;
            cout << "\nSingle-Level Directory Options:\n";
            cout << "1. Create File\n";
            cout << "2. List Files\n";
            cout << "Enter your choice: ";
            cin >> singleChoice;

            if (singleChoice == 1) {
                string fileName;
                cout << "Enter file name: ";
                cin >> fileName;
                singleDir.createFile(fileName);
            } else if (singleChoice == 2) {
                singleDir.listFiles();
            }
            break;
        }
        case 2: {
            int twoChoice;
            cout << "\nTwo-Level Directory Options:\n";
            cout << "1. Create File\n";
            cout << "2. List Files\n";
            cout << "Enter your choice: ";
            cin >> twoChoice;

            if (twoChoice == 1) {
                string user, fileName;
                cout << "Enter user name: ";
                cin >> user;
                cout << "Enter file name: ";
                cin >> fileName;
                twoDir.createFile(user, fileName);
            } else if (twoChoice == 2) {
                string user;
                cout << "Enter user name: ";
                cin >> user;
                twoDir.listFiles(user);
            }
            break;
        }
        case 3: {
            int hierChoice;
            cout << "\nHierarchical Directory Options:\n";
            cout << "1. Create Directory\n";
            cout << "2. Create File\n";
            cout << "3. List Directory\n";
            cout << "Enter your choice: ";
            cin >> hierChoice;

            if (hierChoice == 1) {
                string dirName;
                cout << "Enter directory name: ";
                cin >> dirName;
                hierarchy.createDirectory(dirName);
            } else if (hierChoice == 2) {
                string dirName, fileName;
                cout << "Enter directory name: ";
                cin >> dirName;
                cout << "Enter file name: ";
                cin >> fileName;
                hierarchy.createFile(dirName, fileName);
            } else if (hierChoice == 3) {
                string dirName;
                cout << "Enter directory name: ";
                cin >> dirName;
                hierarchy.listDirectory(dirName);
            }
            break;
        }
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

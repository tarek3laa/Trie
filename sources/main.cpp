#include "../headers/Trie.h"

int main() {

    Trie trie;

    int choice;
    string val;
    do {
        cout << "******* enter your choice *********\n";
        cout << "1. Search for a word \n";
        cout << "2. insert word to trie \n";
        cout << "0. to quite\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << " enter a word in english \n";
                cin >> val;
                cout << "\n" << trie.search(val) << endl;
                break;
            case 2:
                string arabic;
                cout << "Enter english word\n";
                cin >> val;
                cout << "enter arabic word\n";
                cin >> arabic;

                trie.insert(val, arabic);
                trie.saveIntoTxt(val, arabic);
                break;

        }

    } while (choice != 0);


}
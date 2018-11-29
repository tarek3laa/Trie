//
// Created by tarek on 27/11/18.
//

#ifndef TRIE_TRIE_H
#define TRIE_TRIE_H

#include "bits/stdc++.h"

using namespace std;


class Trie {
public:
    Trie();

    void insert(string english, string arabic);

    void saveIntoTxt(string english, string arabic);

    string search(string english);

    ~Trie();

private:
    struct Node {
        bool isword = false;
        string Arabic;
        Node *next[26];
    };
    Node *root = new_node();
    const string path = "/home/tarek/CLionProjects/Trie/sources/word.txt";

    int hashing(char s);

    ifstream in;
    ofstream out;

    Node *new_node();

    void freeTrie(Node *);


};


#endif //TRIE_TRIE_H

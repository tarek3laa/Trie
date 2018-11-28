//
// Created by tarek on 27/11/18.
//

#ifndef TRIE_TRIE_H
#define TRIE_TRIE_H

#include "bits/stdc++.h"

using namespace std;

/**
 * /home/tarek/CLionProjects/Trie/sources/word.txt
 */
class Trie {
public:
    const string path="/home/tarek/CLionProjects/Trie/sources/word.txt";
    Trie();
    void insert(string english,string arabic);
    string search(string english);

     ~Trie();

private:
    struct Node {
        bool isword= false;
        string Arabic;
        Node *next[26];
    };
    Node *root = new_node();
    int hashing(char s);

    Node* new_node();



};


#endif //TRIE_TRIE_H

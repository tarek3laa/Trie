//
// Created by tarek on 27/11/18.
//

#include "../headers/Trie.h"

/**
 * Fill the trie with data that stored in the file
 */
Trie::Trie() {

    in.open(path);
    string s1, s2;
    while (in >> s1 && getline(in, s2))
        insert(s1, s2);

}

/**
 *
 * @param s char in the string
 * @return index, after hashing the char
 */
int Trie::hashing(char s) {
    s = tolower(s);
    return s >= 'a' && s <= 'z' ? (int) s - 97 : -1;
}

/**
 *  insert element to trie
 *
 * @param english word
 * @param arabic word
 */
void Trie::insert(string english, string arabic) {
    Node *temp = root;
    // for each element in english word, create new node if necessary
    for (char c: english) {
        if (temp->next[hashing(c)] == NULL)
            temp->next[hashing(c)] = new_node();
        // make temp to point to next node
        temp = temp->next[hashing(c)];
    }
    temp->Arabic = arabic;
    temp->isword = true;

}

Trie::~Trie() {
    in.close();
    out.close();
    freeTrie(root);

}

/**
 *
 * @param english word
 * @return arabic word or "word not found "
 */
string Trie::search(string english) {
    Node *temp = root;
    for (char c : english) {
        if (temp->next[hashing(c)] != NULL)
            temp = temp->next[hashing(c)];
        else
            return "word not found";

    }
    if (temp->isword)
        return temp->Arabic;
    else return "word not found";
}

Trie::Node *Trie::new_node() {

    Node *node = new Node;
    for (int i = 0; i < 26; ++i) {
        node->next[i] = NULL;
    }

    return node;
}

void Trie::saveIntoTxt(string english, string arabic) {

    out.open(path, fstream::app);
    out << english << " " << arabic << endl;
}

/**
 * free all element in the trie
 * @param root
 */
void Trie::freeTrie(Node *root) {

    if (root == NULL)return;
    for (int i = 0; i < 26; ++i) {
        freeTrie(root->next[i]);
    }
    free(root);
}


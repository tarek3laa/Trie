//
// Created by tarek on 27/11/18.
//

#include "../headers/Trie.h"

Trie::Trie() {
    ifstream in;
    in.open(path);
    string s1,s2;
    while ( in>>s1>>s2 && s1!="NULL" && s2!="NULL")
            insert(s1,s2);

}

int Trie::hashing(char s) {
    s = tolower(s);
    return s >= 'a' && s <= 'z' ? (int) s - 97 : -1;
}

void Trie::insert(string english, string arabic) {
    Node*temp=root;
    for (char c: english){
        if (temp->next[hashing(c)]==NULL)
            temp->next[hashing(c)]=new_node();

        temp=temp->next[hashing(c)];
    }
    temp->Arabic=arabic;
    temp->isword= true;

}

Trie::~Trie() {

}

string Trie::search(string english) {
    Node*temp=root;
    for (char c : english){
        if (temp->next[hashing(c)]!=NULL)
            temp=temp->next[hashing(c)];
        else
            return "word not found";

    }
    if (temp->isword)
    return temp->Arabic;
    else return "word not found";
}

Trie::Node *Trie::new_node() {

    Node*node=new Node;
    for (int i = 0; i <26 ; ++i) {
        node->next[i]=NULL;
    }


    return node;
}


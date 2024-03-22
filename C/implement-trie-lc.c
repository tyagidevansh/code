#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET 26
typedef struct {
    struct Trie* children[ALPHABET];
    bool endOfWord;
} Trie;


Trie* trieCreate() {
    Trie* newNode = (Trie*)malloc(sizeof(Trie));
    if (newNode) {
        newNode->endOfWord = false;
        for (int i = 0; i < ALPHABET; i++) {
            newNode->children[i] = NULL;
        }
    }
    return newNode;
}

void trieInsert(Trie* obj, char* word) {
    Trie* curr = obj;
    while (*word) {
        int index = *word - 'a';
        if (!curr->children[index]) {
            curr->children[index] = trieCreate();
        }
        curr = curr->children[index];
        word++;
    }
    curr->endOfWord = true;
}

bool trieSearch(Trie* obj, char* word) {
    Trie* curr = obj;
    while (*word) {
        int index = *word - 'a';
        if (!curr->children[index]) {
            return false;
        }
        curr = curr->children[index];
        word++;
    }
    return curr && curr->endOfWord;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    Trie* curr = obj;
    while (*prefix) {
        int index = *prefix - 'a';
        if (!curr->children[index]) {
            return false;
        }
        curr = curr->children[index];
        prefix++;
    }
    return true;
}

void trieFree(Trie* obj) {
    if (obj == NULL) {
        return;
    }

    for (int i = 0; i < ALPHABET; i++) {
        if (obj->children[i] != NULL) {
            trieFree(obj->children[i]);
        }
    }

    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
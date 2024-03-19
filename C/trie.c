#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool endOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode* newNode = (TrieNode*)malloc(sizeof(struct TrieNode));
    if (newNode) {
        newNode->endOfWord = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            newNode->children[i] = NULL;
        }
    }
    return newNode;
}

void insert(TrieNode* root, char* word) {
    TrieNode* current = root;
    while (*word) {
        int index = *word - 'a';
        if (!current->children[index]) {
            current->children[index] = createNode();
        }
        current = current->children[index];
        word++;
    }
    current->endOfWord = true;
}

bool search(TrieNode* root, char* word) {
    TrieNode* current = root;
    while (*word) {
        int index = *word - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
        word++;
    }
    return current && current->endOfWord;
}

int main() {
    TrieNode* root = createNode();

    insert(root, "hello");
    insert(root, "world");

    printf("%s \n", search(root, "hello") ? "Found" : "Not found");
    printf("%s \n", search(root, "hi") ? "Found" : "Not found");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entry {
    char* key;
    int value;
    struct Entry* next;
} Entry;

typedef struct HashTable {
    int size;
    Entry** table;
} HashTable;

Entry* createEntry(const char* key, int value) {
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->key = strdup(key);
    newEntry->value = value;
    newEntry->next = NULL;
    return newEntry;
}
HashTable* createHashTable(int size) {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->table = (Entry**)malloc(size * sizeof(Entry*));
    memset(hashTable->table, 0, size * sizeof(Entry*));
    return hashTable;
}

unsigned int hash(const char* key, int size) {
    unsigned int hashValue = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hashValue = hashValue * 1116 + key[i];
    }
    return hashValue % size;
}

int get(HashTable* hashTable, const char* key) {
    unsigned int index = hash(key, hashTable->size);
    Entry* entry = hashTable->table[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1;
}

void put(HashTable* hashTable, const char* key, int value) {
    unsigned int index = hash(key, hashTable->size);
    Entry* entry = hashTable->table[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value; 
            return;
        }
        entry = entry->next;
    }

    Entry* newEntry = createEntry(key, value);
    newEntry->next = hashTable->table[index];
    hashTable->table[index] = newEntry;
}

void removeEntry(HashTable* hashTable, const char* key) {
    unsigned int index = hash(key, hashTable->size);
    Entry* prev = NULL;
    Entry* entry = hashTable->table[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            if (prev == NULL) {
                hashTable->table[index] = entry->next;
            } else {
                prev->next = entry->next;
            }
            free(entry->key);
            free(entry);
            return;
        }
        prev = entry;
        entry = entry->next;
    }
}

void printHashTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        printf("Index %d: ", i);
        Entry* entry = hashTable->table[i];
        while (entry != NULL) {
            printf("(%s, %d) ", entry->key, entry->value);
            entry = entry->next;
        }
        printf("\n");
    }
}

void freeHashTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        Entry* entry = hashTable->table[i];
        while (entry != NULL) {
            Entry* temp = entry;
            entry = entry->next;
            free(temp->key);
            free(temp);
        }
    }
    free(hashTable->table);
    free(hashTable);
}

int main() {
    HashTable* hashTable = createHashTable(10);

    put(hashTable, "key1", 10);
    put(hashTable, "key2", 20);
    put(hashTable, "key3", 30);
    put(hashTable, "key4", 40);
    put(hashTable, "key5", 40);
    put(hashTable, "key6", 40);
    put(hashTable, "key7", 40);
    put(hashTable, "key8", 40);
    put(hashTable, "key9", 40);
    put(hashTable, "key10", 40);
    put(hashTable, "key11", 40);
    put(hashTable, "key12", 40);
    printHashTable(hashTable);

    int value = get(hashTable, "key3");
    printf("Value: %d\n", value);

    removeEntry(hashTable, "key2");

    printHashTable(hashTable);

    freeHashTable(hashTable);

    return 0;
}

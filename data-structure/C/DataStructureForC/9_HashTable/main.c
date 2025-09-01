#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

typedef struct Element{
    int key;
}* Element;

typedef struct HashTable{   //哈希表底层用的数据结构是数组
    Element * table;
}* HashTable;

void InitHash(HashTable hashTable){
    hashTable->table = malloc(sizeof(Element) * SIZE);
    for (int i = 0; i < SIZE; ++i) {
        hashTable->table[i] = NULL;
    }
}

int hash(int key){
    return key % SIZE;
}

void insert(HashTable hashTable,Element e){ //e为待插入元素
    int hashcode = hash(e->key);    //计算哈希值（存储数组下标）
    hashTable->table[hashcode] = e;
}

_Bool find(HashTable hashTable,int key){
    int hashCode = hash(key);
    if(hashTable->table[hashCode] == NULL)
        return 0;
    return hashTable->table[hashCode]->key == key;
}

Element creat(int key){     //将待插入值封装进Element
    Element element = malloc(sizeof(struct Element));
    element->key=key;
    return element;
}


int main() {
    struct HashTable table;
    InitHash(&table);
    insert(&table, creat(10));
    insert(&table, creat(7));
    insert(&table, creat(13));
    insert(&table, creat(29));
    for (int i = 0; i < SIZE; ++i) {
        if(table.table[i]){
            printf("%3d\n",table.table[i]->key);
        } else{
            printf("NULL\n");
        }
    }
    return 0;
}

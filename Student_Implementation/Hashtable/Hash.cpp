#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#define TABLE_SIZE 10
#define MAX_NAME_LENGTH 20

struct Node
{
    string name;
    int age;

    Node *next; //* for Closed addressing
};

int hash(Node *node)
{
    int length = node->name.length();
    int key = 0;

    for (int i = 0; i < length; i++)
    {
        key += node->name[i];
    }

    return key % TABLE_SIZE;
}

int main()
{
}
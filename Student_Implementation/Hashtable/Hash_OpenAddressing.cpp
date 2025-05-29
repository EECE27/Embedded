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
};

Node* HashTable[TABLE_SIZE] = {0}; // Hash Table Array

        /*Hashing Function*/
int MyHash(string Name)
{
    int length = Name.length();
    int key = 0;

    for (int i = 0; i < length; i++)
    {
        key += Name[i]; 
        // key *= i;        // Additional Hashing
    }

    return key % TABLE_SIZE;
}


    /*Accompanying Functions*/
bool HashInsert(string name, int age)
{
    Node* Data = new Node;
    
    Data->name = name;
    Data->age = age;

    int key = MyHash(Data->name);

    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(HashTable[(i + key) % TABLE_SIZE] == NULL)
        {
            HashTable[(i + key) % TABLE_SIZE] = Data;
            return true;
        }
    }

    cout << "Failed To Insert\n";
    return false;
}

void PrintTable()
{
    Node* Current = NULL;

    cout << "------------START---------------\n";
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(HashTable[i] == NULL)
        {
            printf("%d . 0\n", i);
        }
        else
        {
            printf("%d . %s\n", i, HashTable[i]->name.c_str());
        }
    }

    cout << "------------END---------------\n";
}

bool HashRemove(string Target)
{
    int key = MyHash(Target);

    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(HashTable[(i + key) % TABLE_SIZE]->name == Target)
        {
            delete HashTable[(i + key) % TABLE_SIZE];
            HashTable[(i + key) % TABLE_SIZE] = NULL;
            return true;
        }
    }

    return false;
}

Node* HashSearch(string Target)
{
    int key = MyHash(Target);

    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(HashTable[(i + key) % TABLE_SIZE] != NULL &&
           HashTable[(i + key) % TABLE_SIZE]->name == Target)
        {
            return HashTable[(i + key) % TABLE_SIZE];
        }
    }

    return NULL;
}

int main()
{

    // cout << MyHash("Ameer") << endl;
    // cout << MyHash("Amir") << endl;
    // cout << MyHash("Gendy") << endl;
    // cout << MyHash("Kareem") << endl;
    // cout << MyHash("Omar") << endl;
    // cout << MyHash("Shaimaa") << endl;
    
    HashInsert("Ameer", 20);
    HashInsert("Ameer", 50);
    HashInsert("Amir", 2);
    HashInsert("Gendy", 26);
    HashInsert("Ziad", 40);
    HashInsert("Anas", 30);
    HashInsert("Kareem", 25);
    HashInsert("Omar", 24);
    HashInsert("Nasr", 23);
    HashInsert("Mohamed", 23);
    HashInsert("Khaled", 23);

    PrintTable();

    Node* Dest = HashSearch("Kareem");
    if(Dest != NULL)
    {
        cout << "FOUND:" <<Dest->name << "    " << Dest->age << endl;
    }
    else
    {
        cout << "NOT FOUND";
    }

    HashRemove("Ameer");
    HashRemove("Kareem");

    

    PrintTable();

    Dest = HashSearch("Kareem");
    if(Dest != NULL)
    {
        cout << "FOUND:" <<Dest->name << "    " << Dest->age << endl;
    }
    else
    {
        cout << "NOT FOUND";
    }
}
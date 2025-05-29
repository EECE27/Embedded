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
    Data->next = NULL;

    int key = MyHash(Data->name);

    if(HashTable[key] == NULL)
    {
        HashTable[key] = Data;

        return true;
    }
    else
    {
        Data->next = HashTable[key];
        HashTable[key] = Data;

        return true;
    }
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
        else if(HashTable[i]->next == NULL)
        {
            printf("%d . %s\n", i, HashTable[i]->name.c_str());
        }
        else
        {
            printf("%d . %s", i, HashTable[i]->name.c_str());
            Current = HashTable[i];
            while(Current->next != NULL)
            {
                Current = Current->next;
                printf("-> %s", Current->name.c_str());
            }

            cout << endl;
        }
    }

    cout << "------------END---------------\n";
}

bool HashRemove(string Target)
{
    int key = MyHash(Target);

    if(HashTable[key] == NULL)
    {
        return false;
    }
    else
    {
        Node* Current = HashTable[key];
        Node* temp = Current;

        if(Current->name == Target)
        {
            HashTable[key] = HashTable[key]->next;
            delete temp;

            return true;
        }

        while(Current->next != NULL && Current->name != Target)
        {
            temp = Current;
            Current = Current->next;
        }

        temp->next = Current->next;
        delete Current;
        return true;
    }


}

Node* HashSearch(string Target)
{
    int key = MyHash(Target);
    Node* Current = HashTable[key];

    if(HashTable[key] == NULL)
    {
        return NULL;
    }
    else
    {
        while(Current->name != Target && Current->next != NULL)
        {
            Current = Current->next;
        }

        if(Current->name == Target)
        {
            return Current;
        }
        else
        {
            return NULL;
        }
    }

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

    PrintTable();

    Node* Dest = HashSearch("Amir");
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
#include <string>

//FIX_ME: структура Node 
class Node
{
public:
    //int data;
    //Node* next;

    int Data;
    Node* Next;

    Node(int Value);
};

//FIX_ME: класс LinkedList 
class LinkedList
{
private:
    //Node* head;
    Node* Head;

public:
    //LinkedList() : head(nullptr) {}
    LinkedList();

    //void insertSorted(int value);
    void InsertSorted(int Value);

    //void print();
    void Print();

    //void readFromFile(const std::string& filename);
    void ReadFromFile(const std::string& FileName);

    friend void ReadFromFile(LinkedList& ListObject, const std::string& FileName);
};

//void readFromFile(LinkedList& list, const std::string& filename);
void ReadFromFile(LinkedList& ListObject, const std::string& FileName);
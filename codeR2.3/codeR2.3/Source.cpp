#include "Header.h"
#include <iostream>
#include <fstream>

//FIX_ME: конструктор Node с PascalCase
//Node(int value) : data(value), next(NULL) {}
Node::Node(int Value)
{
    Data = Value;
    Next = NULL;
}

//FIX_ME: конструктор LinkedList с PascalCase
//LinkedList() : head(nullptr) {}
LinkedList::LinkedList()
{
    Head = NULL;
}

//FIX_ME: InsertSorted с PascalCase переменными и методами
/*
void insertSorted(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr || head->data < value) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr && current->next->data > value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}
*/
void LinkedList::InsertSorted(int Value)
{
    Node* NewNode = new Node(Value);

    if (Head == nullptr || Head->Data < Value)
    {
        NewNode->Next = Head;
        Head = NewNode;
    }
    else
    {
        Node* Current = Head;
        while (Current->Next != nullptr && Current->Next->Data > Value)
        {
            Current = Current->Next;
        }
        NewNode->Next = Current->Next;
        Current->Next = NewNode;
    }
}

//FIX_ME: Print с PascalCase
/*
void print() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
*/
void LinkedList::Print()
{
    Node* Current = Head;
    while (Current != nullptr)
    {
        std::cout << Current->Data << " ";
        Current = Current->Next;
    }
    std::cout << std::endl;
}

//FIX_ME:приведение названия к кол стайлу и проверки
/*
void readFromFile(const std::string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    int N;
    file >> N;

    int value;
    for (int i = 0; i < N; ++i) {
        file >> value;
        insertSorted(value);
    }

    file.close();
}
*/
void LinkedList::ReadFromFile(const std::string& FileName)
{
    std::ifstream File(FileName);

    if (!File.is_open())
    {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return;
    }

    int N;
    File >> N;

    if (N <= 0)
    {
        std::cout << "Ошибка: количество элементов должно быть положительным." << std::endl;
        return;
    }

    int Value;
    for (int i = 0; i < N; i++)
    {
        File >> Value;
        if (File.fail())
        {
            std::cout << "Ошибка чтения данных из файла." << std::endl;
            return;
           
        }
        InsertSorted(Value);
        
    }

    File.close();
}

//FIX_ME: приведение к код стайлу
/*
void readFromFile(LinkedList& list, const string& filename) {
    list.readFromFile(filename);
}
*/
void ReadFromFile(LinkedList& ListObject, const std::string& FileName)
{
    ListObject.ReadFromFile(FileName);
}
#pragma once
#include <iostream>

class DoubleList
{
public:

    //FIX_ME: структура Node с PascalCase
    /*
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int val) {
            data = val;
            next = nullptr;
            prev = nullptr;
        }
    };
    */
    // Структура узла двусвязного списка
    struct Node
    {
        int Data;       // Значение элемента
        Node* Next;     // Указатель на следующий элемент
        Node* Prev;     // Указатель на предыдущий элемент

        Node(int Value)
        {
            Data = Value;
            Next = nullptr;
            Prev = nullptr;
        }
    };

    Node* Head; // Указатель на первый элемент списка

    DoubleList()
    {
        Head = nullptr;
    }

    ~DoubleList(); // Деструктор для очистки памяти

    // Добавление элемента в конец списка
    void PushBack(int Value);

    // Вывод всех элементов списка на экран
    void PrintList();

    // Удаление конкретного узла и возвращение следующего элемента
    Node* DeleteNode(Node* NodeToDelete);

    // Удаление всех элементов, у которых левый и правый сосед совпадают
    Node* RemoveSides();
};
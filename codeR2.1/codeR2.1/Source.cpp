#include "Header.h"
#include <iostream>
#include <cctype>


//FIX_ME: приводим имена переменных и методов к стандарту Epic Games.
// В исходном коде использовались имена data, next, top и методы push/pop.
// Меняем их на PascalCase.


Node::Node(int Value)
{
    //data(value), next(nullptr)

    Data = Value;
    Next = nullptr;
}


Stack::Stack()
{
    //top(nullptr)

    Top = nullptr;
}


// Метод добавления элемента в стек
void Stack::Push(int Value)
{
    /*
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    cout << "Элемент " << value << " добавлен в стек." << endl;
    */

    Node* NewNode = new Node(Value);

    NewNode->Next = Top;
    Top = NewNode;

    std::cout << "Элемент " << Value << " добавлен в стек." << std::endl;
}


// Метод удаления элемента
void Stack::Pop()
{
    /*
    if (top == nullptr) {
        cout << "Стек пуст! Невозможно удалить элемент." << endl;
        return;
    }
    */

    if (Top == nullptr)
    {
        std::cout << "Стек пуст! Невозможно удалить элемент." << std::endl;
        return;
    }

    /*
    Node* temp = top;
    top = top->next;
    cout << "Элемент " << temp->data << " удален из стека." << endl;
    delete temp;
    */

    Node* Temp = Top;
    Top = Top->Next;

    std::cout << "Элемент " << Temp->Data << " удален из стека." << std::endl;

    delete Temp;
}


// Вывод элементов стека
void Stack::Print()
{
    /*
    if (top == nullptr) {
        cout << "Стек пуст!" << endl;
        return;
    }
    */

    if (Top == nullptr)
    {
        std::cout << "Стек пуст!" << std::endl;
        return;
    }

    //Node* current = top;

    Node* Current = Top;

    std::cout << "Элементы стека: ";

    while (Current != nullptr)
    {
        //cout << current->data << " ";

        std::cout << Current->Data << " ";

        //current = current->next;

        Current = Current->Next;
    }

    std::cout << std::endl;
}


// Очистка стека
void Stack::ClearStack()
{
    while (Top != nullptr)
    {
        /*
        Node* temp = top;
        top = top->next;
        delete temp;
        */

        Node* Temp = Top;
        Top = Top->Next;

        delete Temp;
    }

    std::cout << "Стек очищен." << std::endl;
}


// Получение вершины стека
Node* Stack::GetTop()
{
    return Top;
}


// Функция из условия задачи
void AddElementAndPrintAddress(Stack& StackObject, int D)
{
    /*
    stack.push(D);
    cout << "Адрес новой вершины стека: " << stack.getTop() << endl;
    */

    StackObject.Push(D);

    std::cout << "Адрес новой вершины стека: "
        << StackObject.GetTop()
        << std::endl;
}


// Проверка строки на число
bool IsNumber(const std::string& Str)
{
    if (Str.empty())
    {
        return false;
    }

    for (char c : Str)
    {
        if (!std::isdigit(c))
        {
            return false;
        }
    }

    return true;
}
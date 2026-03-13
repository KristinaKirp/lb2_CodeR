#include "Header.h"
#include <iostream>
#include <cctype>

//FIX_ME: приводим названия переменных и структуры к стандарту Epic Games.
// В исходном коде использовались транслитерированные имена.

/*
struct Uzel {
    int Znachenie;
    Uzel* Sleduyushiy;
};
*/


void Queue::Initialize()
{
    //Nachalo = nullptr;
    //Konec = nullptr;

    Head = nullptr;
    Tail = nullptr;
}


void Queue::AddElement(int Number)
{
    //FIX_ME: изменяем название структуры и переменных под код-стайл

    /*
    Uzel* Noviy = new Uzel;
    Noviy->Znachenie = Chislo;
    Noviy->Sleduyushiy = nullptr;
    */

    Node* NewNode = new Node;
    NewNode->Value = Number;
    NewNode->Next = nullptr;

    /*
    if (Nachalo == nullptr) {
        Nachalo = Noviy;
        Konec = Noviy;
    }
    */

    if (Head == nullptr)
    {
        Head = NewNode;
        Tail = NewNode;
    }
    else
    {
        /*
        Konec->Sleduyushiy = Noviy;
        Konec = Noviy;
        */

        Tail->Next = NewNode;
        Tail = NewNode;
    }
}


void Queue::RemoveElement()
{
    /*
    if (Nachalo == nullptr) {
        cout << "Очередь пуста!" << endl;
        return;
    }
    */

    if (Head == nullptr)
    {
        std::cout << "Очередь пуста!" << std::endl;
        return;
    }

    /*
    Uzel* Vremenny = Nachalo;
    Nachalo = Nachalo->Sleduyushiy;
    delete Vremenny;
    */

    Node* Temp = Head;
    Head = Head->Next;
    delete Temp;

    if (Head == nullptr)
    {
        Tail = nullptr;
    }
}


void Queue::PrintElements()
{
    /*
    Uzel* Tekushiy = Nachalo;
    */

    Node* Current = Head;

    while (Current != nullptr)
    {
        //cout << Tekushiy->Znachenie << " ";

        std::cout << Current->Value << " ";

        //Tekushiy = Tekushiy->Sleduyushiy;

        Current = Current->Next;
    }

    std::cout << std::endl;
}


void Queue::PrintPointers()
{
    /*
    cout << "Адрес начала: " << Nachalo;
    if (Nachalo != nullptr) cout << " (значение: " << Nachalo->Znachenie << ")";
    */

    std::cout << "Адрес начала: " << Head;

    if (Head != nullptr)
    {
        std::cout << " (значение: " << Head->Value << ")";
    }

    std::cout << std::endl;

    /*
    cout << "Адрес конца:  " << Konec;
    if (Konec != nullptr) cout << " (значение: " << Konec->Znachenie << ")";
    */

    std::cout << "Адрес конца:  " << Tail;

    if (Tail != nullptr)
    {
        std::cout << " (значение: " << Tail->Value << ")";
    }

    std::cout << std::endl;
}


// Проверяет, что строка состоит только из цифр
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
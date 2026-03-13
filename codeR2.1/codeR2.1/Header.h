#include <string>

// Структура узла стека.
// Каждый элемент содержит значение и указатель на следующий элемент.
class Node
{
public:

    int Data;
    Node* Next;

    Node(int Value);
};

// Класс стека.
// Вершина стека — первый элемент связанного списка.
class Stack
{
private:

    Node* Top;

public:

    Stack();

    // Добавление элемента в стек
    void Push(int Value);

    // Удаление элемента из стека
    void Pop();

    // Вывод элементов стека
    void Print();

    // Очистка стека
    void ClearStack();

    // Получение указателя на вершину
    Node* GetTop();

    friend void AddElementAndPrintAddress(Stack& StackObject, int D);
};

// Проверка строки на число
bool IsNumber(const std::string& Str);

// Функция из условия задачи.
// Добавляет элемент в стек и выводит адрес новой вершины.
void AddElementAndPrintAddress(Stack& StackObject, int D);
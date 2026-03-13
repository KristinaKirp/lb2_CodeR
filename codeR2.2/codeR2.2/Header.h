#include <string>

// Структура узла очереди.
// Каждый элемент хранит значение и указатель на следующий элемент.
struct Node
{
    int Value;
    Node* Next;
};

// Класс очереди.
// Хранит указатели на начало и конец для быстрого добавления элементов.
class Queue
{
private:

    Node* Head;
    Node* Tail;

public:

    // Инициализация очереди
    void Initialize();

    // Добавление элемента в конец очереди
    void AddElement(int Number);

    // Удаление первого элемента
    void RemoveElement();

    // Вывод всех элементов очереди
    void PrintElements();

    // Вывод указателей начала и конца очереди
    void PrintPointers();
};

// Проверка строки на то, является ли она числом
bool IsNumber(const std::string& Str);
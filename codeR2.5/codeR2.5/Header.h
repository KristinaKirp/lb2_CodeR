#include <list>
#include <string>
#include <fstream>
#include <iostream>

// Класс с функциями работы с контейнером list<int>
class ListOperations
{
public:

    // Заполняет список L различными способами: клавиатура, рандом, файл
    static void Input(std::list<int>& L, int N);

    // Вывод элементов списка
    static void Print(const std::list<int>& L);

    // Перемещает средний элемент списка L1 в конец списка L2
    static void MoveMiddleToEnd(std::list<int>& L1, std::list<int>& L2);
};
#include "Header.h"
#include <ctime>

//FIX_ME: старый код Input
/*
void Input(list<int>& L, int n) { ... }
*/
// Заполнение списка различными способами
void ListOperations::Input(std::list<int>& L, int N)
{
    int Choice, Value;
    std::cout << "Выберите способ заполнения контейнера:" << std::endl;
    std::cout << "1) Ввод с клавиатуры" << std::endl;
    std::cout << "2) Случайные числа" << std::endl;
    std::cout << "3) Ввод из файла" << std::endl;

    std::cin >> Choice;

    switch (Choice)
    {
    case 1: // Ввод с клавиатуры
    {
        for (int i = 0; i < N; i++)
        {
            std::cout << "Введите элемент " << i + 1 << ": ";
            std::cin >> Value;
            if (std::cin.fail())
            {
                std::cout << "Ошибка: введено не число!" << std::endl;
                exit(1);
            }
            L.insert(L.end(), Value);
        }
        break;
    }

    case 2: // Рандомные числа
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        for (int i = 0; i < N; i++)
            L.insert(L.end(), std::rand() % 101 - 50); // числа от -50 до 50
        break;
    }

    case 3: // Из файла
    {
        std::ifstream File("a.txt", std::ios::in);
        if (!File)
        {
            std::cout << "Ошибка: файл не открыт!" << std::endl;
            exit(1);
        }
        for (int i = 0; i < N; i++)
        {
            File >> Value;
            if (File.fail())
            {
                std::cout << "Ошибка: некорректные данные в файле!" << std::endl;
                exit(1);
            }
            L.insert(L.end(), Value);
        }
        File.close();
        break;
    }

    default:
        std::cout << "Ошибка ввода." << std::endl;
        exit(1);
    }
}

//FIX_ME: старый код Print
/*
void Print(const list<int> L) { ... }
*/
// Вывод элементов списка
void ListOperations::Print(const std::list<int>& L)
{
    for (auto it = L.begin(); it != L.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

//FIX_ME: старый код Splice
/*
void Splice(list<int>& L1, list<int>& L2) { ... }
*/
// Перемещает средний элемент списка L1 в конец списка L2
void ListOperations::MoveMiddleToEnd(std::list<int>& L1, std::list<int>& L2)
{
    auto It = L1.begin();
    int Size = static_cast<int>(L1.size());
    for (int i = 0; i < Size / 2; i++)
        ++It;

    L2.splice(L2.end(), L1, It);
}
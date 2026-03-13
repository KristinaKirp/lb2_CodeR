/*Дан текстовый файл, в первой строке которого хранится число N, а во второй строке N целых чисел. 
Необходимо создать упорядоченный по убыванию список, в который поместить все эти элементы, при этом очередной элемент
вставлять в список так, чтобы не нарушалась его упорядоченность. Для каждой динамической структуры должен быть 
предусмотрен стандартный набор методов - добавления/удаления/вывода элементов. Во всех задачах обязательно
наличие дружественного интерфейса. Ввод данных с клавиатуры. */

#include "Header.h"
#include <iostream>
#include <string>

int main()
{
    std::setlocale(LC_ALL, "rus");

    //FIX_ME: имя переменной list должно быть в PascalCase
    /*LinkedList list;*/

    LinkedList ListObject;

    //FIX_ME: ввод файла с проверкой
    std::string filename;
    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    if (filename.empty())
    {
        std::cout << "Ошибка: имя файла не может быть пустым." << std::endl;
        return 1;
    }

    //FIX_ME: вызов функции чтения файла 
    //readFromFile(list, filename);

    ReadFromFile(ListObject, filename);

    //FIX_ME: вызов метода вывода в PascalCase
    /*std::cout << "Упорядоченный список: ";
    list.print();*/

    ListObject.Print();

    return 0;
}
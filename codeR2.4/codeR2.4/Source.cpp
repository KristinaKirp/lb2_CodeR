#include "Header.h"
//FIX_ME: деструктор с PascalCase
/*
~DoubleList() {
    if (!head)
        return;
    Node* curr = head;
    while (true) {
        Node* tmp = curr;
        curr = curr->next;
        delete tmp;
        if (curr == head)
            break;
    }
}
*/
// удаляем 
DoubleList::~DoubleList()
{
    if (!Head)
        return;

    Node* Curr = Head;
    while (true)
    {
        Node* Tmp = Curr;
        Curr = Curr->Next;
        delete Tmp;
        if (Curr == Head)
            break;
    }
}

//FIX_ME: PushBack с PascalCase
/*
void push_back(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else {
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}
*/
// Добавление элемента в конец циклического двусвязного списка
void DoubleList::PushBack(int Value)
{
    Node* NewNode = new Node(Value);

    if (!Head) // Если список пуст
    {
        Head = NewNode;
        NewNode->Next = NewNode;
        NewNode->Prev = NewNode;
    }
    else // Вставка в конец существующего списка
    {
        Node* Tail = Head->Prev;
        Tail->Next = NewNode;
        NewNode->Prev = Tail;
        NewNode->Next = Head;
        Head->Prev = NewNode;
    }
}

//FIX_ME: PrintList с PascalCase
/*
void printList() {
    Node* curr = head;
    while (true) {
        cout << curr->data << " ";
        curr = curr->next;
        if (curr == head)
            break;
    }
    cout << endl;
}
*/
// Вывод всех элементов списка
void DoubleList::PrintList()
{
    if (!Head)
    {
        std::cout << "Список пуст." << std::endl;
        return;
    }

    Node* Curr = Head;
    while (true)
    {
        std::cout << Curr->Data << " ";
        Curr = Curr->Next;
        if (Curr == Head)
            break;
    }
    std::cout << std::endl;
}

//FIX_ME: DeleteNode с PascalCase
/*
Node* deleteNode(Node* node) {
    if (!node)
        return nullptr;
    if (node->next == node && node->prev == node) {
        if (node == head)
            head = nullptr;
        delete node;
        return nullptr;
    }
    Node* nextNode = node->next;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    if (node == head)
        head = nextNode;
    delete node;
    return nextNode;
}
*/
// Удаляет конкретный узел и возвращает следующий элемент
DoubleList::Node* DoubleList::DeleteNode(Node* NodeToDelete)
{
    if (!NodeToDelete)
        return nullptr;

    if (NodeToDelete->Next == NodeToDelete && NodeToDelete->Prev == NodeToDelete)
    {
        if (NodeToDelete == Head)
            Head = nullptr;
        delete NodeToDelete;
        return nullptr;
    }

    Node* NextNode = NodeToDelete->Next;
    NodeToDelete->Prev->Next = NodeToDelete->Next;
    NodeToDelete->Next->Prev = NodeToDelete->Prev;

    if (NodeToDelete == Head)
        Head = NextNode;

    delete NodeToDelete;
    return NextNode;
}

//FIX_ME: RemoveSides с PascalCase
/*
Node* removeSides() {
    ...
}
*/
// Удаляет все узлы, у которых левый и правый сосед совпадают
DoubleList::Node* DoubleList::RemoveSides()
{
    if (!Head)
        return nullptr;

    bool AnyDeletion = false;

    while (true)
    {
        AnyDeletion = false;

        if (!Head || Head->Next == Head)
            break;

        Node* Start = Head;
        Node* Curr = Head;
        bool CompletedCycle = false;

        while (!CompletedCycle)
        {
            int LeftData = Curr->Prev->Data;
            int RightData = Curr->Next->Data;

            if (LeftData == RightData)
            {
                AnyDeletion = true;

                Node* NextNode = Curr->Next;

                if (Curr == Head)
                    Head = NextNode;

                Curr = DeleteNode(Curr);

                if (!Curr)
                    return nullptr;

                Start = Head; // Начать цикл заново после удаления
                continue;
            }
            else
            {
                Curr = Curr->Next;
            }

            if (Curr == Start)
                CompletedCycle = true;
        }

        if (!AnyDeletion)
            break; // Если удалений нет — цикл завершен
    }

    if (!Head)
        return nullptr;

    Node* Tail = Head->Prev;
    return Tail; // Возвращаем последний элемент
}
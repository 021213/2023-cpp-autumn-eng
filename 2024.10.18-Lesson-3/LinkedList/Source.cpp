#include <iostream>
#include <string>
#include <vector> //TODO: do not use vector library, use the LinkedList<string> instead
#include "LinkedList.h"
/* task
TODO: do not use <vector> library, use the LinkedList<string> instead
TODO: Use an array of functions in process_choice instead of if-s
TODO: implement all unimplemented methods in LinkedList.h
TODO: move all available implementations to LinkedList.cpp
*/

using namespace std;

void print_menu()
{
    system("cls");
    vector<string> items{
        "exit",
        "add element to tail",
        "add element to head",
        "insert element",
        "extract element from tail",
        "extract element from head",
        "extract element at index",
        "assign element at index"
    };
    for (int i = 0; i < items.size(); ++i)
    {
        cout << i << " - " << items[i] << "\n";
    }
}

int get_input()
{
    int choice = 0;
    cin >> choice;
    return choice;
}

template<class T>
void add_to_tail(LinkedList<T>& list)
{
    T element = 0;
    cout << "input element : ";
    cin >> element;
    list.push_back(element);
}
template<class T>
void add_to_head(LinkedList<T>& list)
{
    T element = 0;
    cout << "input element : ";
    cin >> element;
    list.push_front(element);
}
template<class T>
void insert_at_index(LinkedList<T>& list)
{
    int index = 0;
    cout << "input index: ";
    cin >> index;
    int element = 0;
    cout << "input element : ";
    cin >> element;
    list.insert(index, element);
}

template<class T>
void extract_from_tail(LinkedList<T>& list)
{
    cout << "extracted : " << list.pop_back() << "\n";
}
template<class T>
void extract_from_head(LinkedList<T>& list)
{
    cout << "extracted : " << list.pop_front() << "\n";
}
template<class T>
void extract_from_index(LinkedList<T>& list)
{
    int index = 0;
    cout << "input index: ";
    cin >> index;
    cout << "extracted : " << list.extract(index) << "\n";
}

template<class T>
void assign_element(LinkedList<T>& list)
{
    int index = 0;
    cout << "input index: ";
    cin >> index;
    int element = 0;
    cout << "input element : ";
    cin >> element;
    list[index] = element;
}


//typedef void (*FunctionPointer[8]) (LinkedList<T>& list);

template<class T>
bool process_choice(LinkedList<T>& list)
{

    /*TODO: Use an array of functions here instead of if-s*/
    int c = get_input();
    //FunctionPointer funcs[8]{ add_to_tail, add_to_head, ... };
    //funcs[c](list);
    if (c == 0)
    {
        return false;
    }
    if (c == 1)
    {
        add_to_tail(list);
    }
    if (c == 2)
    {
        add_to_head(list);
    }
    if (c == 3)
    {
        insert_at_index(list);
    }
    if (c == 4)
    {
        extract_from_tail(list);
    }
    if (c == 5)
    {
        extract_from_head(list);
    }
    if (c == 6)
    {
        extract_from_index(list);
    }
    if (c == 7)
    {
        assign_element(list);
    }
    cout << list << endl;
    system("pause");
    return true;
}

void demo()
{
    LinkedList<int> list;
    std::cout << list << std::endl;
    list.push_front(2);
    list.push_front(1);
    list.push_back(4);
    list.push_back(5);
    list.insert(0, 0);
    list.insert(3, 3);
    std::cout << list << std::endl;
    std::cout << "EXTRACT 4: " << list.extract(4) << std::endl;
    std::cout << "EXTRACT 1: " << list.extract(1) << std::endl;
    std::cout << "POPPED FRONT: " << list.pop_front() << std::endl;
    std::cout << "POPPED FRONT: " << list.pop_front() << std::endl;
    std::cout << "POPPED BACK: " << list.pop_back() << std::endl;
    std::cout << "POPPED BACK: " << list.pop_back() << std::endl;
    std::cout << list << std::endl;
}

int main(int argc, char* argv[])
{
    //demo();
    LinkedList<int> list;
    bool cont = true;

    while (cont)
    {
        print_menu();
        cont = process_choice(list);
    }
    return 0;
}

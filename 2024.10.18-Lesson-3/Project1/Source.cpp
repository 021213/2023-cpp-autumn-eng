#include <iostream>
#include <string>
#include <vector>
#include "ArrayList.h"

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

void add_to_tail(ArrayList& list)
{
    int element = 0;
    cout << "input element : ";
    cin >> element;
    list.push_back(element);
}
void add_to_head(ArrayList& list)
{
    int element = 0;
    cout << "input element : ";
    cin >> element;
    list.push_front(element);
}
void insert_at_index(ArrayList& list)
{
    int index = 0;
    cout << "input index: ";
    cin >> index;
    int element = 0;
    cout << "input element : ";
    cin >> element;
    list.insert(index, element);
}

void extract_from_tail(ArrayList& list)
{
    cout << "extracted : " << list.pop_back() << "\n";
}
void extract_from_head(ArrayList& list)
{
    cout << "extracted : " << list.pop_front() << "\n";
}
void extract_from_index(ArrayList& list)
{
    int index = 0;
    cout << "input index: ";
    cin >> index;
    cout << "extracted : " << list.extract(index) << "\n";
}

void assign_element(ArrayList& list)
{
    int index = 0;
    cout << "input index: ";
    cin >> index;
    int element = 0;
    cout << "input element : ";
    cin >> element;
    list[index] = element;
}

bool process_choice(ArrayList& list)
{
    int c = get_input();
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

int main(int argc, char* argv[])
{
    ArrayList list;
    bool cont = true;

    while (cont)
    {
        print_menu();
        cont = process_choice(list);
    }

    return 0;
}

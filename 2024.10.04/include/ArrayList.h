#pragma once
#include<ostream>

class ArrayList
{
    public:
        ArrayList();
        ArrayList(const ArrayList& list);
        /*ArrayList(ArrayList&& list);*/
        ~ArrayList();

        void push_front(int element);
        void push_back(int element);
        void insert(int index, int element);

        int pop_front();
        int pop_back();
        int extract(int index);

        int& operator[](int index);
        ArrayList& operator=(ArrayList& list);
        ArrayList& operator+(ArrayList& list);
        ArrayList& operator+(int element);
        bool operator==(ArrayList& list);
        friend std::ostream& operator<<(std::ostream& stream, ArrayList& list);

    private:
        int length;
        int count;
        int* data;
        int spare;
        void expand(int added_count);
        bool index_valid(int index);
};


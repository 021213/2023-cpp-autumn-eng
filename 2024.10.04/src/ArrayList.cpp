#include "ArrayList.h"

ArrayList::ArrayList()
            :length(10), count(0), data(new int[10]), spare(0) {};
ArrayList::ArrayList(const ArrayList& list)
            :length(list.count), count(list.count), data(new int[list.count]), spare(0)
{
    for(int i = 0; i < count; ++i)
    {
        data[i] = list.data[i];
    }
}
/*
ArrayList::ArrayList(ArrayList&& list)
            :length(list.count), count(list.count), data(list.data), spare(0)
{
}
*/

ArrayList::~ArrayList()
{
    delete[] data;
    count = 0;
    length = 0;
    spare = 0;
}

void ArrayList::push_front(int element)
{
    if (length == count)
    {
        expand(length);
    }
    for(int i = count; i > 0; --i)
    {
        data[i] = data[i - 1];
    }
    data[0] = element;
    ++count;
}
void ArrayList::push_back(int element)
{
    if (length == count)
    {
        expand(length);
    }
    data[count] = element;
    ++count;
}
void ArrayList::insert(int index, int element)
{
    if (length == count)
    {
        expand(length);
    }
    for(int i = count; i > index; --i)
    {
        data[i] = data[i - 1];
    }
    data[index] = element;
    ++count;
}

int ArrayList::pop_front()
{
    if (count == 0)
    {
        return spare;
    }
    int res = data[0];
    for(int i = 0; i < count - 1; ++i)
    {
        data[i] = data[i + 1];
    }
    --count;
    return res;
}
int ArrayList::pop_back()
{
    if (count == 0)
    {
        return spare;
    }
    int res = data[count - 1];
    --count;
    return res;
}
int ArrayList::extract(int index)
{
    if (!index_valid(index))
    {
        return spare;
    }
    int res = data[index];
    for(int i = index; i < count - 1; ++i)
    {
        data[i] = data[i + 1];
    }
    --count;
    return res;
}

int& ArrayList::operator[](int index)
{
    if (!index_valid(index))
    {
        return spare;
    }
    return data[index];
}
//ArrayList& ArrayList::operator=(ArrayList& list);
//ArrayList& ArrayList::operator+(ArrayList& list);
//ArrayList& ArrayList::operator+(int element);
bool ArrayList::operator==(ArrayList& list)
{
    if (count != list.count)
    {
        return false;
    }
    for(int i = 0; i < count; ++i)
    {
        if (data[i] != list[i])
        {
            return false;
        }
    }
    return true;
}
std::ostream& operator<<(std::ostream& stream, ArrayList& list)
{
    stream << "[" << list.count << " / " << list.length << "] : { ";
    for(int i = 0; i < list.count; ++i)
    {
        stream << list[i] << " ";
    }
    stream << "}";
}
void ArrayList::expand(int added_count)
{
    int* newdata = new int[count + added_count];
    for(int i = 0; i < count + added_count; ++i)
    {
        newdata[i] = (i < count ? data[i] : 0);
    }
    length += added_count;
    delete[] data;
    data = newdata;
}
bool ArrayList::index_valid(int index)
{
    return (index >= 0 && index < count);
}

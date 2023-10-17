/*
* Set.cpp
* Author: Noel Mrowiec
* CSCI 221 FHSU
* 17APR2023
* 
* Template-based class that implements a set of items. 
* A set is a collection of items in which no item occurs 
* more than once. The items in the set shouldn't be pointer.
* If the user uses pointers, the user must deallocate those pointers. 
* The set assumes that the type of items in the set are not dynamically
* allocated. 
* C++20 compiler required
*/
#ifndef SET_CPP
#define SET_CPP


#include "Set.h"

using namespace myset;


template<class T>
Set<T>::Set() : items{}
{
}

// Copy constructor. Doesn't handle pointers because does shallow copy of set
//  (copy by value in set)
template<class T>
Set<T>::Set(const Set<T>& set)
{
    for (T item : set.items)
    {
        this->items.push_back(item);
    }
}

//Adds a new item to the set. If the item is already in the set then nothing happens.
template<class T>
void Set<T>::add(T item)
{
    if (!this->contains(item)) 
    {
        //item not in set, so add
        items.push_back(item);
    }
}

//Removes an item from the set. If the item is not in the set then nothing happens.
template<class T>
void Set<T>::remove(T item)
{
    if (int i = getIndex(item); i != -1)
    {
        //item in set, so remove
        items.erase(items.begin() + i);
    }
}

// Determines if an item is a member of the set.
// Returns true is item in set, else false
template<class T>
bool Set<T>::contains(T item) const
{
    if (getIndex(item) != -1)
        return true;
    else
        return false;
}

// Retuns number of items in set
template<class T>
int Set<T>::size() const
{
    return items.size();
}

// Returns a pointer to a dynamically created array containing each item
//  in the set.The caller of this function is responsible for deallocating
//  the memory.
template<class T>
T* myset::Set<T>::toArray() const
{
    T* arr = new T[items.size()];
    std::copy(items.begin(), items.end(), arr);
    return arr;
}

//Helper function to find item in the set and returns the index
//Returns index of item in set or -1 if not found
template<class T>
int Set<T>::getIndex(T item) const
{
    auto it = find(items.begin(), items.end(), item);

    // If element was found
    if (it != items.end())
    {
        // calculating the index of item
        int index = it - items.begin();
        return index;
    }
    else {
        // If the element is not
        // present in the vector
        return -1;
    }
}
#endif // !SET_CPP

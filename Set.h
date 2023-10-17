/*
* Set.h
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

#ifndef MYSET_H
#define MYSET_H

#include <iostream>
#include <vector>

namespace myset
{
    template<class T>
    class Set
    {
    public:
        Set();
        Set(const Set<T>& set);
        // Copy constructor. Doesn't handle pointers because does shallow copy of 'set' 
        //(meaning, copy values in 'set')
        auto operator<=>(const Set<T>&) const = default;
        // Overload comparison operator. Performs all 6 compares. 
        // Not implemented because default
        void add(T item);
        //Adds a new item to the set. If the item is already in the set then nothing happens.
        void remove(T item);
        //Removes an item from the set. If the item is not in the set then nothing happens.
        bool contains(T item) const;
        // Determines if an item is a member of the set.
        int size() const;
        // Retuns number of items in set
        T* toArray() const;
        // Returns a pointer to a dynamically created array containing each item
        //  in the set.The caller of this function is responsible for deallocating
        //  the memory.

       friend std::ostream& operator <<(std::ostream& out, const Set<T>& set)
        {
            for (int i = 0; i < set.size(); ++i)
                out << set.items[i] << std::endl;

            return out;
        }
    private:
        std::vector<T> items;
        //vector is used to store items in the set
        int getIndex(T item) const;
        //Helper function to find item in the set and returns the index
        //Returns index of item in set or -1 if not found
    };
}

#endif
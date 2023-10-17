// Project 8.cpp : This file contains the 'main' function. 
// Tests all functions of Set class, including printing items
// to the console, on int, double, char, and string

#include "Set.cpp"
#include <assert.h> 
#include <iostream>

template<class T>
bool mytest_if_equal(Set<T> set1, Set<T> set2)
{
    if (set1 != set2)
        return false;
    else if (set1 < set2)
        return false;
    else if (!(set1 <= set2))
        return false;
    else if (set1 > set2)
        return false;
    else if (!(set1 >= set2))
        return false;
    else if (!(set1 == set2))
        return false;
    else
        return true;
}

bool test_set_str()
{
    //Constructors test
    Set<std::string> set_1{};
    if (set_1 != Set<std::string>{})
        return false;
    if (set_1.size() != 0)
        return false;

    set_1.add("asdf");
    set_1.add("aa");
    set_1.add("DOG");
    set_1.add("Cat1");
    set_1.add("(GAME)");
    set_1.add("hello");
    set_1.add("LIP");


    Set<std::string> set_2{ set_1 };

    if (set_1 != set_2)
        return false;
    if (set_1.size() != 7)
        return false;
    //end constructors test

        //copy assinment test
    Set<std::string> set_3 = set_1;
    if (set_3 != set_1)
        return false;
    else if (set_3.size() != set_1.size())
        return false;

                //test compare equal
    if (!mytest_if_equal(set_1, set_2))
        return false;

    //test remove and not equal compare
    set_2.remove("Cat1");       //now sets aren't equal
    if (mytest_if_equal(set_1, set_2))
        return false;

    //test contains
    if (!set_1.contains("Cat1"))
        return false;
    if (set_2.contains("Cat1"))
        return false;

    //test remove on item on in set
    set_2.remove("Cat");
    if (set_2.size() != 6)
        return false;

    //test size todo make sure num correct
    if (set_1.size() != 7)
        return false;
    if (set_2.size() != 6)
        return false;

    //test toArray
    std::string* setPtr = set_1.toArray();
    if (setPtr[0] != "asdf")
        return false;
    else if (setPtr[1] != "aa")
        return false;
    delete[] setPtr;

    std::cout << "First set=" << "\n";
    std::cout << set_1 << "\n";
    std::cout << "Copy constructed set=" << "\n";
    std::cout << set_2 << "\n";

    return true;
}

bool test_set_char()
{
    //Constructors test
    Set<char> set_1{};
    if (set_1 != Set<char>{})
        return false;
    if (set_1.size() != 0)
        return false;

    set_1.add('a');
    set_1.add('r');
    set_1.add('#');
    set_1.add('W');
    set_1.add('^');


    Set<char> set_2{ set_1 };

    if (set_1 != set_2)
        return false;
    if (set_1.size() != 5)
        return false;
    //end constructors test

    //copy assinment test
    Set<char> set_3 = set_1;
    if (set_3 != set_1)
        return false;
    else if (set_3.size() != set_1.size())
        return false;

      //test compare equal
    if (!mytest_if_equal(set_1, set_2))
        return false;

    //test remove and not equal compare
    set_2.remove('W');       //now sets aren't equal
    if (mytest_if_equal(set_1, set_2))
        return false;

    //test contains
    if (!set_1.contains('W'))
        return false;
    if (set_2.contains('W'))
        return false;

    //test remove on item on in set
    set_2.remove('=');
    if (set_2.size() != 4)
        return false;

    //test size todo make sure num correct
    if (set_1.size() != 5)
        return false;
    if (set_2.size() != 4)
        return false;

    //test toArray
    char* setPtr = set_1.toArray();
    if (setPtr[0] != 'a')
        return false;
    else if (setPtr[1] != 'r')
        return false;
    delete[] setPtr;

    std::cout << "First set=" << "\n";
    std::cout << set_1 << "\n";
    std::cout << "Copy constructed set=" << "\n";
    std::cout << set_2 << "\n";

    return true;
}

bool test_set_double()
{
    //Constructors test
    Set<double> set_1{};
    if (set_1 != Set<double>{})
        return false;
    if (set_1.size() != 0)
        return false;

    set_1.add(2.2);
    set_1.add(30.4);
    set_1.add(4);
    set_1.add(50.0);
    set_1.add(66.222);
    set_1.add(7.4);

    Set<double> set_2{ set_1 };

    if (set_1 != set_2)
        return false;
    if (set_1.size() != 6)
        return false;

    //end constructors test

    //copy assinment test
    Set<double> set_3 = set_1;
    if (set_3 != set_1)
        return false;
    else if (set_3.size() != set_1.size())
        return false;

        //test compare equal
    if (!mytest_if_equal(set_1, set_2))
        return false;

    //test remove and not equal compare
    set_2.remove(66.222);       //now sets aren't equal
    if (mytest_if_equal(set_1, set_2))
        return false;

    //test contains
    if (!set_1.contains(66.222))
        return false;
    if (set_2.contains(66.222))
        return false;
    
    //test remove on item on in set
    set_2.remove(-99);
    if (set_2.size() != 5)
        return false;

    //test size todo make sure num correct
    if (set_1.size() != 6)
        return false;
    if (set_2.size() != 5)
        return false;

    //test toArray
    double* setPtr = set_1.toArray();
    if (setPtr[0] != 2.2)
        return false;
    else if (setPtr[1] != 30.4)
        return false;
    delete[] setPtr;

    std::cout << "First set=" << "\n";
    std::cout << set_1 << "\n";
    std::cout << "Copy constructed set=" << "\n";
    std::cout << set_2 << "\n";

    return true;
}

bool test_set_ints()
{
    //Constructors test
    Set<int> set_ints {};
    if (set_ints != Set<int>{})
        return false;
    if (set_ints.size() != 0)
        return false;

    set_ints.add(2);
    set_ints.add(30);
    set_ints.add(4);
    set_ints.add(50);
    set_ints.add(66);
    set_ints.add(7);
    
    Set<int> set_2{ set_ints };

    if (set_ints != set_2)
        return false;
    if (set_ints.size() != 6)
        return false;

    //end constructors test

        //copy assinment test
    Set<int> set_3 = set_ints;
    if (set_3 != set_ints)
        return false;
    else if (set_3.size() != set_ints.size())
        return false;

    //test compare equal
    if (!mytest_if_equal(set_ints, set_2))
        return false;

    //test remove and not equal compare
    set_2.remove(66);       //now sets aren't equal
    if (mytest_if_equal(set_ints, set_2))
        return false;

    //test contains
    if (!set_ints.contains(66))
        return false;
    if (set_2.contains(66))
        return false;

    //test remove on item on in set
    set_2.remove(-99);
    if (set_2.size() != 5)
        return false;

    //test size todo make sure num correct
    if (set_ints.size() != 6)
        return false;
    if (set_2.size() != 5)
        return false;

    //test toArray
    int* setPtr = set_ints.toArray();
    if (setPtr[0] != 2)
        return false;
    else if (setPtr[1] != 30)
        return false;
    delete [] setPtr;


    std::cout << "First set=" << "\n";
    std::cout << set_ints << "\n";
    std::cout << "Copy constructed set=" << "\n";
    std::cout << set_2 << "\n";

    return true;
}

int main()
{
    if(!test_set_ints())
        std::cout << "Tests failed\n";
    else if (!test_set_double())
        std::cout << "Tests failed\n";
    else if (!test_set_char())
        std::cout << "Tests failed\n";
    else if (!test_set_str())
        std::cout << "Tests failed\n";
    else
        std::cout << "All tests passed\n";
}




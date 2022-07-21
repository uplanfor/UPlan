#include <vector>
#include <stack>
#include "test.hpp"
#include "UPlan/UVector.hpp"


static void test01()
{
    UVector<int> mv(5, 6);
    UVector<int> mv2(5);
    UVector<int> mv3(mv);
    UVector<int> mv4 = {1, 3, 5, 7, 9, 10, 15};
    for (int i = 1; i != 20; ++i)
    {
        mv2.push_back(i * 5);
    }
    mv2.swap(mv4);
    print_container(mv);
    print_container(mv2);
    print_container(mv3);
    print_container(mv4);
}

static void test02()
{
    // test for UVector<T>::insert
    printf("test for UVector<T>::insert \n");

    UVector<int> v = {1, 3, 5, 7, 9};
    UVector<int> v2 = {-1, -3, -5, -7, -9};
    print_container(v);
    v.insert(++v.begin(), 2);
    print_container(v);
    v.insert(++++++v.begin(), 4, 8);
    print_container(v);
    v.insert(++++v.begin(), ++v2.begin(), v2.end());
    print_container(v);

    printf("end test \n");
}

static void test03()
{    
    // test for UVector<T>::erase
    printf("test for UVector<T>::insert \n");

    UVector<int> v = {1, 3, 5, 7, 9};
    UVector<int> v2 = {-1, -3, -5, -7, -9};
    print_container(v);
    v.erase(++v.begin());
    print_container(v);
    v.erase(++++v.begin(), --v.end());
    print_container(v);

    printf("end test \n");
}
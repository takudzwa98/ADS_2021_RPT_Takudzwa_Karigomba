#include <iostream>
#include "OrderedArray.h"
using namespace std;

int main()
{
    OrderedArray<int> array(6);
    //push method
    array.push(9);
    array.push(5);
    array.push(3);
    array.push(10);
    array.push(7);
    array.push(2);

    cout << "Array: ";
    for (int i = 0; i < array.length(); i++)
    {
        cout << array.getElement(i) << " ";
    }
    cout << endl;


    //remove index
    cout << "Remove 5 in array: " << array.remove(2) << endl;
   
    cout << "Array: ";
    for (int i = 0; i < array.length(); i++)
    {
        cout << array.getElement(i) << " ";
    }
    cout << endl;



    //clear method
    array.clear();
    cout << "Clear Array: ";
    for (int i = 0; i < array.length(); i++)
    {
        cout << array.getElement(i) << " ";
    }
    cout << endl;
    return 0;

}

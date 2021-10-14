#include "My_Array.h"

using namespace std;

int main()
{
    MyArray<char> arr1(4, 'e');
    MyArray<char> arr2 = arr1;

    try
    {
        cout << "Array1:" << endl;
        arr1.PrintArr();
        cout << "Array2 received by using assignment operator:" << endl;
        arr2.PrintArr();

        arr1.resize(7, 'p');
        cout << "Resized array1:" << endl;
        arr1.PrintArr();
        arr2.resize(2);
        cout << "Resized array2:" << endl;
        arr2.PrintArr();

        arr1.pop_back();
        cout << "Array1 after using \"pop_back\":" << endl;
        arr1.PrintArr();

        arr1.push_back('a');
        arr1.push_back('m');
        cout << "Array1 after using \"push_back\":" << endl;
        arr1.PrintArr();

        arr2 = MyArray<char>(8, 'C');
        cout << "Array1 after using assignment operator with move-semantic:" << endl;
        arr2.PrintArr();
    }
    catch (string &ex)
    {
        cout << ex << endl;
    }

    return 0;
}
//10 Write a function which throws a division by zero exception and catch it in catch block. Write a C++ program to demonstrate usage of try, catch and throw to handle exception. 

#include <iostream>
using namespace std;

void divide(int a, int b) {
    if (b == 0)
        throw "Division by zero error!";
    else
        cout << "Result: " << (a / b) << endl;
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    try {
        divide(x, y);
    } catch (const char* msg) {
        cout << "Exception caught: " << msg << endl;
    }

    cout << "Program continues normally..." << endl;
    return 0;
}

//11 Write a C++ program function which handles array of bounds exception using C++. 
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int index;

    cout << "Enter index to access (0–4): ";
    cin >> index;

    try {
        if (index < 0 || index >= 5)
            throw index;
        cout << "Value at index " << index << " = " << arr[index] << endl;
    } catch (int e) {
        cout << "Array Index Out of Bounds Exception! Invalid index: " << e << endl;
    }

    cout << "Program executed successfully." << endl;
    return 0;
}

#include "factory.h"
#include <iostream>

using namespace std;

bool test()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if ((num > static_cast<int>(TYPE::BLUE)) || (num < static_cast<int>(TYPE::RED))) {
        cout << "Invalid input. Please enter a number between 0 and 2." << endl;
        return false;
    }

    auto instance = MyFactory::GetInstance(KeyType(num));
    if (instance == nullptr) {
        cout << "No instance found." << endl;
        return false;
    }

    instance->FunTodo();
    return true;
}

int main()
{
    test();
    return 0;
}
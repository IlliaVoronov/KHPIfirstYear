#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> numbers;
    //numbers.push_back(0); adds new ellement to the vector

    for (int i = 1; i <= 10; i++){
        numbers.push_back(i); // add an item to the vector
    }

    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;
    // iterating through the vector
    // numbers.begin(); is the beginning iterator
    // numbers.end(); is the end iterator
    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }
    // cbegin and cend are the const versions of begin and end
    // for (auto it = numbers.cbegin(); it != numbers.cend(); it++) {
    //     *it = 20; you can't change the value of a const iterator
    //     cout << *it << endl;
    // }

    


    // how to insert (додати) and erase (зтерти) elements
    numbers.insert(numbers.begin() + 5, 88);
    numbers.erase(numbers.begin() + 5);
    numbers.pop_back(); // removes element from the back

    // // arithmetic operations on vectors
    // auto it = numbers.begin();
    // cout << *(it + 5) << endl;

    // cout << "Size: " << numbers.size() << endl;
    // cout << "Max size: " << numbers.max_size() << endl;
    // cout << "Capacity: " << numbers.capacity() << endl;
    // numbers.resize(5);
    // cout << "Size: " << numbers.size() << endl;
    // if (numbers.empty()) {
    //     cout << "Vector is empty\n";
    // } else {
    //     cout << "Vector is not empty\n";
    // }
    // cout << "Element [0] is: " << numbers[0] << endl;
    // cout << "Element at(0) is: " << numbers.at(0) << endl;
    // cout << "Front: " << numbers.front() << endl;
    // cout << "Back: " << numbers.back() << endl;
    // numbers.clear(); 
    // cout << "Size: " << numbers.size() << endl;
    

    return 0;
}


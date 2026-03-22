#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

// PART 1: FUNCTION TEMPLATES

// Bubble sort template
template <class T>
void bubbleSort(T array[], size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                T temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Get maximum of two values
template <class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

// Get maximum in array
template <class T>
T getMax(T array[], size_t size) {
    T maxVal = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > maxVal) maxVal = array[i];
    }
    return maxVal;
}

// Specialization for char* (strings)
char* getMax(char* a, char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

// PART 2: CUSTOM CLASS FOR DEMONSTRATION

class Money {
private:
    long dollars;
    int cents;

public:
    Money() : dollars(0), cents(0) {}
    Money(long d, int c) : dollars(d), cents(c) {}
    
    bool operator>(const Money& other) const {
        if (dollars != other.dollars) return dollars > other.dollars;
        return cents > other.cents;
    }
    
    friend ostream& operator<<(ostream& os, const Money& m) {
        os << "$" << m.dollars << "." << (m.cents < 10 ? "0" : "") << m.cents;
        return os;
    }
};

// PART 3: TEMPLATE CLASS TSTACK

template <class T>
class TStack {
private:
    T* items;
    int topIdx;
    int capacity;

public:
    TStack(size_t size = 100) : capacity(size), topIdx(-1) {
        items = new T[capacity];
    }
    
    ~TStack() {
        delete[] items;
    }
    
    bool isEmpty() const { return topIdx == -1; }
    bool isFull() const { return topIdx == capacity - 1; }
    int size() const { return topIdx + 1; }
    
    void push(T item) {
        if (!isFull()) items[++topIdx] = item;
    }
    
    T pop() {
        if (!isEmpty()) return items[topIdx--];
        return T();
    }
    
    T peek() const {
        if (!isEmpty()) return items[topIdx];
        return T();
    }
    
    void print() const {
        cout << "[";
        for (int i = 0; i <= topIdx; i++) {
            cout << items[i];
            if (i < topIdx) cout << ", ";
        }
        cout << "]";
    }
};

// PART 4: TRAIN SORTING PROBLEM

void sortTrain(vector<int> input, vector<int>& output) {
    TStack<int> siding(input.size());
    int expected = 1;
    output.clear();
    
    cout << "Input: ";
    for (int v : input) cout << v << " ";
    cout << endl;
    
    for (size_t i = 0; i < input.size(); i++) {
        int curr = input[i];
        
        if (curr == expected) {
            output.push_back(curr);
            expected++;
            
            while (!siding.isEmpty() && siding.peek() == expected) {
                output.push_back(siding.pop());
                expected++;
            }
        } else {
            siding.push(curr);
        }
    }
    
    while (!siding.isEmpty()) {
        int fromSiding = siding.pop();
        if (fromSiding == expected) {
            output.push_back(fromSiding);
            expected++;
        } else {
            cout << "ERROR: Cannot sort!" << endl;
            output.clear();
            return;
        }
    }
    
    cout << "Output: ";
    for (int v : output) cout << v << " ";
    cout << (output.size() == input.size() ? " [OK]" : " [FAIL]") << endl;
}

int main() {
    cout << "LAB9\n";
    
    // ========== 1. FUNCTION TEMPLATES ==========
    cout << "1. FUNCTION TEMPLATES\n";
    
    int a = 10, b = 20;
    cout << "max(10, 20) = " << getMax(a, b) << endl;
    
    double c = 3.14, d = 2.71;
    cout << "max(3.14, 2.71) = " << getMax(c, d) << endl;
    
    char s1[] = "apple", s2[] = "banana";
    cout << "max(apple, banana) = " << getMax(s1, s2) << endl;
    
    int nums[] = {5, 2, 8, 1, 9, 3};
    cout << "max in array = " << getMax(nums, 6) << endl;
    
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    cout << "Before bubbleSort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    bubbleSort(arr, 7);
    cout << "After bubbleSort:  ";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";
    
    // ========== 2. SORTING USER TYPE ==========
    cout << "2. SORTING USER TYPE (Money)\n";
    
    Money money[] = {Money(19,10), Money(99,99), Money(99,95), Money(19,95)};
    cout << "Before: ";
    for (int i = 0; i < 4; i++) cout << money[i] << " ";
    cout << endl;
    
    bubbleSort(money, 4);
    cout << "After:  ";
    for (int i = 0; i < 4; i++) cout << money[i] << " ";
    cout << "\n\n";
    
    // ========== 3. TEMPLATE CLASS TSTACK ==========
    cout << "3. TEMPLATE CLASS TSTACK\n";
    
    TStack<int> intStack(10);
    cout << "Integer stack:\n";
    for (int i = 1; i <= 5; i++) {
        intStack.push(i * 10);
        cout << "  push(" << i*10 << ") -> ";
        intStack.print();
        cout << endl;
    }
    
    cout << "  peek() = " << intStack.peek() << endl;
    cout << "  size() = " << intStack.size() << endl;
    
    while (!intStack.isEmpty()) {
        cout << "  pop() -> " << intStack.pop() << ", stack: ";
        intStack.print();
        cout << endl;
    }
    
    TStack<string> strStack(10);
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("C++");
    cout << "\nString stack: ";
    strStack.print();
    cout << "\n\n";
    
    // ========== 4. TRAIN SORTING PROBLEM ==========
    cout << "4. TRAIN SORTING PROBLEM\n";
    
    vector<int> train1 = {3, 1, 2, 4, 5};
    vector<int> result1;
    cout << "Example 1: ";
    sortTrain(train1, result1);
    
    vector<int> train2 = {4, 3, 2, 1, 5};
    vector<int> result2;
    cout << "Example 2: ";
    sortTrain(train2, result2);
    
    vector<int> train3 = {2, 5, 1, 4, 3};
    vector<int> result3;
    cout << "Example 3: ";
    sortTrain(train3, result3);
    
    cout << "Finish\n";
    
    return 0;
}
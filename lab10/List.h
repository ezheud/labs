// List.h - шаблонный класс односвязного списка
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

// Узел списка
template <class T>
struct Node {
    T data;
    Node<T>* next;
    
    Node() : next(nullptr) {}
    Node(const T& d, Node<T>* n = nullptr) : data(d), next(n) {}
};

// Шаблонный класс односвязного списка
template <class T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    List();
    List(const List<T>& other);
    ~List();
    
    List<T>& operator=(const List<T>& other);
    T& operator[](int index);
    const T& operator[](int index) const;
    
    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void pop_front();
    bool remove(const T& value);
    
    Node<T>* find(const T& value) const;
    Node<T>* findByNumber(int number) const;
    
    bool isEmpty() const { return head == nullptr; }
    int getSize() const { return size; }
    void clear();
    void print() const;
    
    Node<T>* begin() const { return head; }
    Node<T>* end() const { return nullptr; }
};

// ========== КОНСТРУКТОРЫ И ДЕСТРУКТОР ==========

template <class T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

template <class T>
List<T>::List(const List<T>& other) : head(nullptr), tail(nullptr), size(0) {
    Node<T>* current = other.head;
    while (current != nullptr) {
        push_back(current->data);
        current = current->next;
    }
}

template <class T>
List<T>::~List() {
    clear();
}

// ========== ОПЕРАТОРЫ ==========

template <class T>
List<T>& List<T>::operator=(const List<T>& other) {
    if (this != &other) {
        clear();
        Node<T>* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }
    return *this;
}

template <class T>
T& List<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <class T>
const T& List<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

// ========== ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ==========

template <class T>
void List<T>::push_back(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <class T>
void List<T>::push_front(const T& value) {
    Node<T>* newNode = new Node<T>(value, head);
    head = newNode;
    if (tail == nullptr) {
        tail = head;
    }
    size++;
}

// ========== УДАЛЕНИЕ ЭЛЕМЕНТОВ ==========

template <class T>
void List<T>::pop_back() {
    if (isEmpty()) return;
    
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node<T>* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    size--;
}

template <class T>
void List<T>::pop_front() {
    if (isEmpty()) return;
    
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    
    if (head == nullptr) {
        tail = nullptr;
    }
    size--;
}

template <class T>
bool List<T>::remove(const T& value) {
    if (isEmpty()) return false;
    
    if (head->data == value) {
        pop_front();
        return true;
    }
    
    Node<T>* current = head;
    while (current->next != nullptr && !(current->next->data == value)) {
        current = current->next;
    }
    
    if (current->next == nullptr) return false;
    
    Node<T>* temp = current->next;
    current->next = temp->next;
    
    if (temp == tail) {
        tail = current;
    }
    
    delete temp;
    size--;
    return true;
}

// ========== ПОИСК ==========

template <class T>
Node<T>* List<T>::find(const T& value) const {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Поиск по номеру (требует метод getNumber())
template <class T>
Node<T>* List<T>::findByNumber(int number) const {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data.getNumber() == number) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// ========== ОЧИСТКА ==========

template <class T>
void List<T>::clear() {
    while (!isEmpty()) {
        pop_front();
    }
}

// ========== ВЫВОД ==========

template <class T>
void List<T>::print() const {
    Node<T>* current = head;
    int index = 0;
    while (current != nullptr) {
        cout << "  [" << index++ << "] " << current->data << endl;
        current = current->next;
    }
}

#endif // LIST_H
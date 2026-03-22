// List.cpp - реализация шаблонного класса List
#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"

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
    while (current->next != nullptr && current->next->data != value) {
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

// ========== ПОИСК И ОЧИСТКА ==========

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

#endif // LIST_CPP
/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
#include <string>

using namespace std;

Node* list_init(int val[], int n) {
    Node* head = nullptr;
    Node* rear = nullptr;
    for (int i = 0; i < n; i++) {
        Node* node = new Node(val[i], nullptr);
        if (rear != nullptr) {
            rear->next = node;
            rear = node;
        } else {
            head = node;
            rear = node;
        }
    }
    return head;
}

void list_free(Node* list) {
    if (list == nullptr) {
        return;
    }
    Node* del = list;
    while (del != nullptr) {
        Node* save = del->next;
        delete del;
        del = save;
    }
}

void list_print(Node* list) {
    Node* p;
    cout << "[";
    for (p = list; p != nullptr && p->next != nullptr; p = p->next) {
        cout << p->value << " ";
    }
    if (p != nullptr) {
        cout << p->value;
    }
    cout << "]";
}

void test(string test_name, int val[], int n) {
    Node* list = list_init(val, n);
    cout << test_name << " ----------" << endl;
    cout << "origin list: ";
    list_print(list);

    Node* odds = nullptr;
    Node* evens = nullptr;
    split(list, odds, evens);

    cout << "    ";
    cout << "odd list: ";
    list_print(odds);
    cout << "    ";
    cout << "even list: ";
    list_print(evens);
    cout << endl;
    cout << endl;

    list_free(odds);
    list_free(evens);
}

int main(int argc, char* argv[]) {
    int arr1[] = {};
    test("test1", arr1, 0);
    int arr2[] = {1};
    test("test2", arr2, 1);
    int arr3[] = {1, 3};
    test("test3", arr3, 2);
    int arr4[] = {1, 3, 4};
    test("test4", arr4, 3);
    int arr5[] = {1, 2, 3, 4, 5, 6};
    test("test5", arr5, 6);
    int arr6[] = {1, 2, 4, 6, 8, 9};
    test("test6", arr6, 6);

    return 0;
}

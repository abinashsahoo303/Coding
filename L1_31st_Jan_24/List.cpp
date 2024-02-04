#include<iostream>
#include<memory>

using namespace std;

template <typename T>
struct Node{
    T data;
    Node* next;
    Node(const T)
};


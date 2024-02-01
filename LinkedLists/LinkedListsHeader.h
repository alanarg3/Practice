// only include the declarations and class methods
#include <cmath>

#include <iostream>
using std::cin;
using std::cout;

#include <memory>
using std::make_shared;
using std::shared_ptr;

#include <vector>
using std::vector;

#include <cassert>

#ifndef LINKEDLISTSHEADER_H
#define LINKEDLISTSHEADER_H

class Node; // forward definition
class List {
private:
    shared_ptr<Node> head{ nullptr };
public:
    List() {};
    auto headnode(); //{ return head; };
    void insert(int value);
    int length();
    int length_iterative();
    bool contains_value(int v);
    void print();
};

class Node {
private:
    int datavalue{ 0 }, datacount{ 0 };
    shared_ptr<Node> next{ nullptr };
public:
    Node(int value, int count, shared_ptr<Node> next);
    int value(); 
    
    auto nextnode() {return next;};
    
    int length();
    
    int count();

    bool has_next();

    void insert(int value);
    void print();
    bool contains_value(int v);
};

#endif

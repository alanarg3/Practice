#include "LinkedListsHeader.h"
#ifndef LINKEDLISTSIMPLEMENTATION_CPP
#define LINKEDLISTSIMPLEMENTATION_CPP

Node::Node(int value, int count = 1, shared_ptr<Node> next = nullptr)
{
    this->datavalue = value;
    this->datacount = count;
    this->next = next;
};

int List::length() {
    int count = 0;
    if (head == nullptr)
        return 0;
    else
        return head->length();
};

int Node::length() {
    if (!has_next())
        return 1;
    else
        return 1 + next->length();
};

/*
 * Iterative alternative
 * to recursive computation
 */
int List::length_iterative() {
    int count = 0;
    if (head != nullptr) {
        auto current_node = head;
        while (current_node->has_next()) {
            current_node = current_node->nextnode(); count += 1;
        }
    }
    return count;
};

/*
 * Auxiliary functions
 */
void Node::print() {
    cout << datavalue << ":" << datacount;
    if (has_next()) {
        cout << ", "; next->print();
    }
};

void List::print() {
    cout << "List:";
    if (head != nullptr)
        cout << " => "; head->print();
    cout << '\n';
};

void List::insert(int value)
{
    if (head == nullptr)
    {
        head = make_shared<Node>(value);                    // adds a node with the initial value
    }
    else
    {
        if (value < head->value())
        {
            head = make_shared<Node>(value, 1, head);       // sets the next node to be the old head node to insert it at the begining
        }
        else
        {
            head->insert(value);                            // sets the head to be the first node >= value
        }
    }
}

void Node::insert(int value)
{
    if (datavalue == value)                             // Checks if you are trying to insert a value already contained in the list
    {
        datacount += 1;
    }
    else if (next == nullptr)                           // Checks if the value should be at the end of the list 
    {
        next = make_shared<Node>(value);                // adds the new node to the end of the list
        return;
    }
    else if (next->value() > value)                     // Checks if the given value is lower than the next value
    {
        next = make_shared<Node>(value, 1, next);       // sets the new "next" to a pointer with the datavalue of "value" which points to the old "next"
        return;
    }
    else
    {
        next->insert(value);                            // calls the function recursively
        return;
    }
}

bool List::contains_value(int value)
{
    if (head == nullptr)
    {
        return false;
    }
    else
    {
        return head->contains_value(value);
    }
}

bool Node::contains_value(int value)
{
    // if I contain this value, true
    if (datavalue == value)
    {
        return true;
    }
    // else if there is no next, then return false
    else if (next == nullptr)
    {
        return false;
    }
    // check recursively
    else
    {
        next->contains_value(value);
    }
};

auto List::headnode() 
{ 
    return head; 
}

int Node::value() { return datavalue; };

int Node::count() { return datacount; };

bool Node::has_next()
{
    return next != nullptr;
};

#endif

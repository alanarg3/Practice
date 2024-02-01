// name: Alana Gaughan

#include "LinkedListsHeader.h"
#include "LinkedListsImplementation.cpp"

int main() {

    List mylist;
    cout << "Empty list has length: "
        << mylist.length() << '\n';
    cout << '\n';

    // Exercise 5
    mylist.insert(3);
    cout << "After inserting 3 the length is: "
        << mylist.length() << '\n';
    if (mylist.contains_value(3))
        cout << "Indeed: contains 3" << '\n';
    else
        cout << "Hm. Should contain 3" << '\n';
    if (mylist.contains_value(4))
        cout << "Hm. Should not contain 4" << '\n';
    else
        cout << "Indeed: does not contain 4" << '\n';
    cout << '\n';

    // Exercise 6
    mylist.insert(3);
    cout << "Inserting the same item gives length: "
        << mylist.length() << '\n';
    if (mylist.contains_value(3)) {
        cout << "Indeed: contains 3" << '\n';
        auto headnode = mylist.headnode();
        cout << "head node has value " << headnode->value()
            << " and count " << headnode->count() << '\n';
    }
    else
        cout << "Hm. Should contain 3" << '\n';
    cout << '\n';

    // Excersize 7
    mylist.insert(2);
    cout << "Inserting 2 goes at the head;\nnow the length is: "
        << mylist.length() << '\n';
    if (mylist.contains_value(2))
        cout << "Indeed: contains 2" << '\n';
    else
        cout << "Hm. Should contain 2" << '\n';
    if (mylist.contains_value(3))
        cout << "Indeed: contains 3" << '\n';
    else
        cout << "Hm. Should contain 3" << '\n';
    cout << '\n';

    // Excersize 8
    mylist.insert(6);
    cout << "Inserting 6 goes at the tail;\nnow the length is: "
        << mylist.length()
        << '\n';
    if (mylist.contains_value(6))
    {
        cout << "Indeed: contains 6" << '\n';
    }
    else
    {
        cout << "Hm. Should contain 6" << '\n';
    }
    if (mylist.contains_value(3))
        cout << "Indeed: contains 3" << '\n';
    else
        cout << "Hm. Should contain 3" << '\n';
    cout << '\n';

    //Excersize 9
    mylist.insert(4);
    cout << "Inserting 4 goes in the middle;\nnow the length is: "
        << mylist.length()
        << '\n';
    if (mylist.contains_value(4))
        cout << "Indeed: contains 4" << '\n';
    else
        cout << "Hm. Should contain 4" << '\n';
    if (mylist.contains_value(3))
        cout << "Indeed: contains 3" << '\n';
    else
        cout << "Hm. Should contain 3" << '\n';
    cout << '\n';

    cout << "List has length: " << mylist.length() << '\n';
    cout << '\n';

    // Uncomment below to reveal the second check in the skeleton
    /*cout << "Another check.\n";
    List mylist2;
    int iteration = 1;
    for (auto i : { 15,23,11,75,11,65,3 }) {
        cout << "insert: " << i << '\n';
        mylist2.insert(i);
        cout << "List at step " << iteration << ": ";
        mylist2.print();
        iteration += 1;
    }
    mylist2.print();*/

    // Slide 31: Linked List excersize
    bool in_loop = true;
    List excerise_10_list;
    while (in_loop)         // Loops to accept user input until the user decides to exit
    {
        int user_number;
        cout << "Enter an integer (Enter 0 to STOP): ";
        cin >> user_number;
        if (user_number == 0)
        {
            in_loop = false;
            break;          // exit because 0 should not be counted
        }
        
        excerise_10_list.insert(user_number);       //inserts the user's input
        excerise_10_list.print();
    }
}

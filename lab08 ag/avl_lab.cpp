//Assignment Identifier: EAA16B5C3724FBFD78F132136AABBBBA4952E261


// LAB 8: Ro-Tater Tots
// Tree Tester File

#include "avl_lab.h"

using namespace std;

int main() {

    AVL increasing_tree;
    AVL decreasing_tree;
    AVL randomish_tree;
    for (int i = 0; i < 10; i++) {
        increasing_tree.insert(i);
        decreasing_tree.insert(10 - i);
    }
    //
    vector<int> example = { 1, 19, 2, 4, 7, 3, 28, 30, 18, 13, 10, 64, 65, 66, 67, 70, 68, 69, 50, 43, 60 };
    for (int v : example) {
        randomish_tree.insert(v);
        randomish_tree.print_diagram();
    }
    cout << "test tree (increasing_tree)" << endl;
    increasing_tree.print_diagram();
    // should look like:
    //test tree (increasing_tree) //
    //     - 3-----               //
    //    /        \              //
    //   1         - 7            //
    //  / \       /   \           //
    // 0   2     5     8          //
    //          / \     \         //
    //         4   6     9        //

    cout << endl;

    cout << "test tree (decreasing_tree)" << endl;
    decreasing_tree.print_diagram();
    // should look like:
    // test tree (decreasing_tree) //
    //       ----- 7-              //
    //      /        \             //
    //     3-          9           //
    //    /  \        / \          //
    //   2     5     8  10         //
    //  /     / \                  //
    // 1     4   6                 //

    cout << endl;

    cout << "test tree (randomish_tree)" << endl;
    randomish_tree.print_diagram();
    // should look like:
    // test tree (randomish_tree)                 //
    //               -----30-------               //
    //              /              \              //
    //         ---13-            ---65-           //
    //        /      \          /      \          //
    //     - 4        19      50-       67-       //
    //    /   \       / \     /  \      /  \      //
    //   2     7    18  28  43    64  66    69    //
    //  / \     \                 /         / \   //
    // 1   3    10              60        68  70  //
    cout << endl;

    cout << endl;
    cout << "SUBMISSION RESULTS:" << endl;
    //
    // actual part you need to submit for:
    AVL bigtree;
    for (int i = 0; i < 2000; i++) {
        // producing magic numbers
        unsigned int x = (unsigned int)i;
        // borrowed from http://stackoverflow.com/a/12996028/409054
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = (x >> 16) ^ x;
        bigtree.insert(x % 2017);
    }

    // search string ends with 'X' if found, 'M' if missing

    cout << "search for 201:" << endl;
    bigtree.search(201, true); // should be LLLRLLRLRX
    cout << "search for 745:" << endl;
    bigtree.search(745, true); // should be LRLLLLRLLX
    cout << "search for 1983:" << endl;
    bigtree.search(1983, true); // should be RRRRRX
    cout << "search for 2017:" << endl;
    bigtree.search(2017, true); // should be RRRRRRRRRRRM

}
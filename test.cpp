// #include <iostream>
// #include <cassert>
// using namespace std;

// struct Node
// {
//     int   data;
//     Node* child[3];
// };

// // SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// // COMMENT AT THE END OF THE countLessers FUNCTION

// int countLessers(const Node* p)
// {
//     return -999; // DELETE THIS COMMENT AND REPLACE THIS ENTIRE LINE WITH YOUR SOLUTION
// }

// // SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// // COMMENT AT THE START OF THE countLessers FUNCTION

// Node* makeNode(int d)
// {
//      Node* p = new Node;
//      p->data = d;
//      for (int k = 0; k < 3; k++)
//          p->child[k] = nullptr;
//      return p;
// }

// int main()
// {
//       // Build the 3-tree pictured in the problem as an example

//     Node* n8 = makeNode(8);
//     n8->child[2] = makeNode(3);
 
//     Node* n2 = makeNode(2);
//     n2->child[1] = n8;
     
//     Node* n5 = makeNode(5);
//     n5->child[0] = makeNode(8);
//     n5->child[2] = makeNode(9);
     
//     Node* n7 = makeNode(7);
//     n7->child[1] = n5;
 
//     Node* root = makeNode(4);
//     root->child[0] = n2;
//     root->child[1] = makeNode(1);
//     root->child[2] = n7;
    
//       // Test countLessers with that tree
 
//     assert(countLessers(root) == 3);
//     assert(countLessers(root->child[2]) == 1);
//     assert(countLessers(nullptr) == 0);
//     cout << "All tests succeeded" << endl;

//       // Clean up the tree

//     delete n8->child[2];
//     delete n8;
//     delete n2;
//     delete root->child[1];
//     delete n5->child[0];
//     delete n5->child[2];
//     delete n5;
//     delete n7;
//     delete root;
// }

#include <iostream>
#include <cassert>
using namespace std;

// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// COMMENT AT THE END OF THE product FUNCTION

int product(int a, int b)
{
    if (a < b)
        return product(b, a);
    else if (b != 0)
        return (a + product(a, b - 1));
    else
        return 0;
}


// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// COMMENT AT THE START OF THE product FUNCTION

int main()
{
    assert(product(7, 5) == 35);
    assert(product(-4, 8) == -32);

    cout << "All tests succeeded" << endl;
}
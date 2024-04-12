#include <iostream>
#include "Tree.h"
using namespace std;
int main()
{
    Tree<int> copac(100);
    copac.add_node(nullptr, 1);
    copac.add_node(copac.root, 2);
    copac.add_node(copac.root, 3);
    copac.add_node(copac.root->children[1], 4);
    copac.add_node(copac.root, 5);
    copac.add_node(copac.root, 6);
    copac.delete_node(copac.root->children[1]);
    copac.sort(copac.root,compara);
    copac.printNodes(copac.root);
    cout << endl;
    cout << copac.count(nullptr);
    return 0;
}

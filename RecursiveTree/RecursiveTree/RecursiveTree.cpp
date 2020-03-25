#include <iostream>
#include "MyTree.h"
using namespace std;


int main()
{
    MyTree<int> tree;
    int a[] = { 5,3,1,2,7,6,8 };
    for (int i = 0; i < 7; i++)
    {
        tree.AddElement(a[i]);
    }
    tree.PrintAll();
    cout << (tree.Find(1) ? "We have -1" : "We dont have -1(") << endl;

    tree.DeleteTree();
}

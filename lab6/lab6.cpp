#include"Tree.h"

int main()
{
    Tree tree;
    cout << "Enter how many numbers you want: ";
    int size; cin >> size;
    
    for (int i = 0; i < size; i++)
    {
        double val = input();
        tree.add_node(val);
    }

    tree.print();
    cout << endl <<"Average = " << tree.average_num() << endl;
}


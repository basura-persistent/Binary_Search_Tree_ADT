#include <iostream>
#include <fstream>
#include "BinSearchTree.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    // create a tree and then print the values of its nodes
    // from the smallest to the largest.
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " nameOfAnInputFile\n";
        exit(1);
    }
    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);
    if (!inputStream.is_open()) {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        exit(1);
    }

    ifstream inputStream2;
    inputStream2.open(argv[1], std::ios::in);
    if(!inputStream2.is_open()){
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        exit(1);    
    }
    
    auto *bst1 = new BinSearchTree();//pointer to the class of BinSearchTree
    int v;
    int g;
    while (inputStream >> v) {
        bst1->insert(v);
    }
    
    //cout<<"max depth"<<bst1->maxDepth()<<endl;
    cout<<"recursive max depth"<<bst1->MaxDepth()<<endl;
    cout<<"size"<<bst1->size()<<endl;
    cout<<"In order Dump"<<endl;
    bst1->inorderDump();
    cout<<"level order Dump"<<endl;

    // if(bst1->areIdentical(bst2)){
    //     cout<<"The two trees are identical"<<endl;
    // }else{
    //     cout<<"The two trees are not Identical"<<endl;
    // }




    // At this point, we have a tree that contains the contents of
    // the input file and is ready for use. You should be able to call
    // any of the operations that are defined in BinSearchTree. An
    // example is maxDepth.

    //%% ./a.out | sort -nc make sure to use this to test if values are in increasing order. 
    //If they are sorted then nothing will be printed out but if it is not sorted then it will print the first value not sorted
    //tree->levelOrderDump();
    //tree->inorderDump();
    //std::cout << "max depth = " << tree->maxDepth() << std::endl;
    //cout<<"size"<<tree->size();
    return 0;
}
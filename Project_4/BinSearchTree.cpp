#include<vector>
#include<iostream>
#include "BinSearchTree.hpp"
#include "TreeNode.hpp"
#include <queue>


using namespace std;

BinSearchTree::BinSearchTree(): root{nullptr} {} 

void BinSearchTree::insert(int v ) {
    // You will have to write a solution to find in order to use this function.
    //if the integer we are trying to add is not already a node in the tree insert it 
    if( ! find(v)) 
        root = insert(root, v);//now root is equal to the node index at which we inserted our last item
}

TreeNode *BinSearchTree::insert( TreeNode *root, int v ) {//root gives us our current index and this is a pointer to the node list from TREENODE so we can make our comparisons to create bin search tree
    if( root == nullptr )//if we have reached the end of the list(null ptr) return the tree node since we are at the end of the list
        return new TreeNode( v );// we are now storing the value in this newly created TreeNode
    if( root->value() < v )//if v is greater than our current root value then insert to the rightsubtree
        root->rightSubtree( insert( root->rightSubtree(), v ) );
    else
        root->leftSubtree( insert( root->leftSubtree(), v ) );//else if v is less than then insert to the left sub value
    return root;//if root is not declared in TreeNode why are we able to return this?
}

void BinSearchTree::iterInsert( int v){//fix this 
    if(!iterFind(v)){
        root = iterInsert(root, v);
    }

}

TreeNode *BinSearchTree::iterInsert(TreeNode*& root, int v){
    TreeNode *curr = root;
    TreeNode *parent = nullptr;

    if(root == nullptr){
        return new TreeNode(v);
    }

    while (curr != nullptr){
        parent = curr;

        if(v < curr->value()){
            curr = curr ->leftSubtree();
        }
        else{
            curr = curr->rightSubtree();
        }
    }

    if(v < parent->value()){
        parent->leftSubtree( new TreeNode(v));
    }
    else{
        parent->rightSubtree(new TreeNode(v));
    }
    return root;
}


bool BinSearchTree::find( int v ){
    return find(root, v);
}

bool BinSearchTree::find( TreeNode *root, int v ) {//root gives us our current index and this is a pointer to the node list from TREENODE so we can make our comparisons to create bin search tree
    bool value = false;
    if( root == nullptr )//if we have reached the end of the list(null ptr) return the tree node since we are at the end of the list
        return false;// we are now storing the value in this newly created TreeNod
    if(root->value() == v){
        return true;
    }
    if( root->value() < v ){//if v is greater than our current root value then insert to the rightsubtree
        value = find(root->rightSubtree(), v);
    }
    else if (root->value() > v){
        value = find(root->leftSubtree(), v);//else if v is less than then insert to the left sub value
    }
    return value;//if root is not declared in TreeNode why are we able to return this?
    
}

bool BinSearchTree::iterFind( int v){//fix this //returns true if v is a member of the values stored in the tree. Otherwise, it returns false. You should write an iterative implementation for this function.
    TreeNode *curr = root;
    while(curr != nullptr ){
        if(curr->value() == v){
           return true;
        }
        if(curr->value() > v){
            curr = curr->leftSubtree();
        }
       else{
           curr = curr->rightSubtree();
       }
    }
    return false;
}


int BinSearchTree::size() {
    return size(root);
}

int BinSearchTree::size(TreeNode *root){
    if(root == nullptr){
        return 0;
    }
    int leftCount = size(root->leftSubtree());
    int rightCount = size(root->rightSubtree());
    return leftCount+rightCount+1;
}



int BinSearchTree::MaxDepth(){
    return MaxDepth(root);
}

int BinSearchTree::MaxDepth(TreeNode *root){
    if(root == nullptr){
        return 0;
    }
    else{
        int lDepth = MaxDepth(root->leftSubtree());
        int rDepth = MaxDepth(root->rightSubtree());

        if(lDepth > rDepth){
            return lDepth+1;
        }
        else return (rDepth+1);
    }
}




int BinSearchTree::iterMaxDepth(){
    return iterMaxDepth(root);
}

int BinSearchTree::iterMaxDepth(TreeNode *root){
    if(root == nullptr){
        return 0;
    }
    
    queue<TreeNode *> levellist;
    levellist.push(root);//print the root node first 
    TreeNode *currlevel;
    int height = 0;
    while(1){//unless this section of the while loop returns something keep running this code after every outer loop
        int nodecount = levellist.size();
        if(nodecount == 0){
            return height;
        }
        height++;

    while(nodecount > 0){
        TreeNode *Node = levellist.front();
        levellist.pop();
        if(Node->leftSubtree() != nullptr){
            levellist.push(Node->leftSubtree());
        }
        if(Node->rightSubtree() != nullptr){
            levellist.push(Node->rightSubtree());
        }
        nodecount--;
    }
}
}


void BinSearchTree::inorderDump(){
    return inorderDump(root);
}

void BinSearchTree::inorderDump(TreeNode *root){
    if (root == nullptr){
        return;
    }
    inorderDump(root->leftSubtree());
    cout<<root->value()<<endl;
    inorderDump(root->rightSubtree());
}

void BinSearchTree::levelOrderDump(){
    return levelOrderDump(root);
}

void BinSearchTree::levelOrderDump(TreeNode *root){
    queue<TreeNode*> list;
    list.push(root);//print the root node first 
    TreeNode *curr;
    while(!list.empty()){
        curr = list.front();
        list.pop();
        cout<<curr->value()<<endl;
        if(curr->leftSubtree() != nullptr){
            list.push(curr->leftSubtree());
        }
        if(curr->rightSubtree() != nullptr){
            list.push(curr->rightSubtree());
        }
    }
}

bool BinSearchTree::areIdentical(BinSearchTree *bst){
    //bst->root is root maintained by the callee
    //root is the local root 
    return areIdentical(bst->root, root);
}

bool BinSearchTree::areIdentical(TreeNode *rootOfBST1,TreeNode *rootOfBST2){
    if(rootOfBST1 == nullptr && rootOfBST2 == nullptr){
        return 1;
    }
    else if (rootOfBST1 == nullptr && rootOfBST2 != nullptr){
        return 0;
    }
    else if(rootOfBST1 != nullptr && rootOfBST2 == nullptr){
        return 0;
    }
    else{
        if(rootOfBST1->value() == rootOfBST2->value() && areIdentical(rootOfBST1->leftSubtree(), rootOfBST2->leftSubtree()) && areIdentical(rootOfBST1->rightSubtree(),rootOfBST2->rightSubtree())){
            return 1;
        }
        else{
            return 0;
        } 
    }

}

void BinSearchTree::deleteTree(){
    deleteTree(root);
}

void BinSearchTree::deleteTree(TreeNode *root){
    if(root == nullptr) return;

    deleteTree(root->leftSubtree());//will recursively run until we hit base case;
    deleteTree(root->rightSubtree());

    cout<<"Deleting node"<<root->value()<<endl;
    delete root;
}







// int iterMaxDepth(){
//     //if root == nullp
//         //depth equals 0
//     //d = 1 +return [maxdepthright() compare to 1+ maxdepthleft()]
// }

//questions
//* Is *BinSearchTree::insert( TreeNode *root, int v ) is this referring to the tree node structure defined in the class?
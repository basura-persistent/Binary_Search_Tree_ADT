
#include<stdlib.h>
#include "TreeNode.hpp"

class BinSearchTree {
public:
    BinSearchTree();
    void insert( int v );//adds v to the search tree so that after the insertion find(v) returns true
    TreeNode *iterInsert(TreeNode*& root, int v );// The semantics of this function is the same as that of recursive insert. 
    void iterInsert(int v);
    bool find( int v );// same as iterFind except this one is to be implemented recursively.--
    bool find(TreeNode *root, int v );
    bool iterFind( int v );//returns true if v is a member of the values stored in the tree. Otherwise, it returns false. You should write an iterative implementation for this function.
    int size();// returns the number of values in the tree. Write your solution recursively.
    void inorderDump();//prints (one value per output line) the values in the tree using an in-order traversal.
    int iterMaxDepth(); //returns the depth of the tree.-- The depth of a tree that doesn't have any nodes is zero. The root of the tree is at depth 1. The depth of each of the child nodes of the root, if it exists, is 2. etc. Write a solution for this function.  
    int MaxDepth(); //The semantics of this function is the same as that of iterMaxDepth. Except, you write this one recurisvelu
    void levelOrderDump();//prints the values in the tree, one value per line, using a level-order traversal. You must write an iterative solution for this function, using a FCFS queue.   
    bool areIdentical(BinSearchTree *bst1);//returns true if the tree in bst is structurally identical to that of the tree maintained by the callee. Otherwise, it returns false. Write a recursive solution for this function.
    void deleteTree();
    ~BinSearchTree();//must delete each of the two subtrees recursively;
private:
    TreeNode *insert(TreeNode *, int v);
    int size(TreeNode *root);
    int maxDepth(TreeNode *root);
    void inorderDump(TreeNode *root);
    void levelOrderDump(TreeNode *root);
    bool areIdentical(TreeNode *root1, TreeNode *root2);
    int iterMaxDepth(TreeNode *root);
    int iterSizeHelper(TreeNode *root);
    int MaxDepth(TreeNode *root);
    void deleteTree(TreeNode* node);


    TreeNode *root;
};


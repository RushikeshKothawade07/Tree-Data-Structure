// C++ program for different tree traversals
//and all tree questions from leetcode and gfg

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// Function to print the postorder traversal 
// of a Binary Tree
void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    cout << node->data << " ";
}

// Function to print the Inorder traversal
// of a Binary Tree
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->data << " ";

    /* now recur on right child */
    printInorder(node->right);
}

// Function to print the PreOrder traversal 
// of a Binary Tree
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    cout << node->data << " ";

    /* then recur on left sutree */
    printPreorder(node->left); 

    /* now recur on right subtree */
    printPreorder(node->right);
} 
    //levelorder traversal
vector<vector<int>> levelOrder(struct Node* root) {
    vector<vector<int>>levels;
    if(root==NULL)
        return levels;
    queue<Node*>q;
    q.push(root);
    while(q.empty()==false)
    {
        int size=q.size();
        vector<int>v;
        while(size--)
        {    
            Node* node=q.front();
            v.push_back(node->data);
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        levels.push_back(v);
        
    }
    return levels;
}

void printLevelOrder(struct Node* root)
{
    vector<vector<int>>vec=levelOrder(root);
    for (int i=0;i<vec.size();i++) {
        for (int j=0;j<vec[i].size();j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
void rightSideView(Node* root,int level,vector<int>&v)
{
    if(root==NULL)
        return;
    if(v.size()==level)
        v.push_back(root->data);

    rightSideView(root->right,level+1,v);
    rightSideView(root->left,level+1,v);
}
void printRightSideView(Node*root)
{
    vector<int>v;
    rightSideView(root,0,v);
    for(auto i : v)
        cout<<i<<" ";
}

void leftSideView(Node* root,int level,vector<int>&v)
{
    if(root==NULL)
        return;
    if(v.size()==level)
        v.push_back(root->data);

    leftSideView(root->left,level+1,v);
    leftSideView(root->right,level+1,v);
}
void printleftSideView(Node*root)
{
    vector<int>v;
    leftSideView(root,0,v);
    for(auto i : v)
        cout<<i<<" ";
}
int dfsheight(Node* root)
{
    if(root==NULL)
        return 0;
    int lh=dfsheight(root->left);
    if(lh==-1) return -1;
    int rh=dfsheight(root->right);
    if(rh==-1) return -1;

    if(abs(lh-rh)>1)
        return -1;
    
    return max(lh,rh)+1;
}
void isBalanced(Node* root)
{
    int x=dfsheight(root);
    if(x==-1){
         cout<<"False"; 
         return;
    }
    cout<<"True";
}
int height(Node* root)
{
    if(root==NULL)
    return 0;
    return max(height(root->left),height(root->right))+1;
}
int ans=0;
int heightForDiameter(Node* root)
{
    if(root==NULL)
        return 0;

    int lh=heightForDiameter(root->left);
    int rh=heightForDiameter(root->right);

    ans=max(1+lh+rh,ans);

    return 1+max(lh,rh);
}
int diameter(Node* root)
{
    int dummy=heightForDiameter(root);
    return ans-1;

}

int isSumProperty(Node* root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return 1;
    int leftsum=0,rightsum=0;
    if(root->left!=NULL)
        leftsum=root->left->data;
    if(root->right!=NULL)
        rightsum=root->right->data;

    if(root->data == (leftsum+rightsum) && isSumProperty(root->left) && isSumProperty(root->right))
        return 1;
    else    
        return 0;
    
}
int maximumInTree(Node* root)
{
    if(root==NULL)
    return INT_MIN;
    else
        return max(root->data,max(maximumInTree(root->left),maximumInTree(root->right)));
}
int getSize(Node* root)
{
    if(root==NULL)
    return 0;
    else
    return 1+getSize(root->left)+getSize(root->right);
}
// Driver Code
int main()
{
    // Contruct the Tree
    //      1
    //     /  \
    //    2    3
    //   / \   / 
    //  4   5  8
    //      \
    //      6
    //     
    system("CLS"); 
    struct Node *root = new Node(1);
    root->left    = new Node(2);
    root->right    = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 
    root->left->right->right = new Node(6); 
    // root->left->right->right->left = new Node(7); 
    root->right->left = new Node(8); 

    cout << "Preorder traversal of binary tree is \n";
    printPreorder(root);

    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root); 

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);

    cout << "\nLevelorder traversal of binary tree is \n";
    printLevelOrder(root);

    cout << "\nRight Side view of binary tree is \n";
    printRightSideView(root);

    cout << "\nLeft Side view of binary tree is \n";
    printleftSideView(root);

    cout << "\nIs the binary tree balanced?  \n";
    isBalanced(root);

    cout << "\nHeight of the binary tree is \n";
    cout<<height(root);

    cout << "\nDiameter of the binary tree is \n";
    cout<<heightForDiameter(root);

    cout << "\nDoes this binary tree follow children sum property? \n";
    string ans=isSumProperty(root)?"True":"False";
    cout<<ans;

    cout << "\nMaximum value in the binary tree is \n";
    cout<<maximumInTree(root);

    cout << "\nSize of the binary tree is \n";
    cout<<getSize(root);



    return 0;
}
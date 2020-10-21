#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

// A Binary Tree Node
struct Node {
    struct Node *left, *right;
    int key;
};

Node *newNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = data;
    node->left = node->right = NULL;
    return (node);
}

// Function to insert nodes in level order
Node *insertLevelOrder(int arr[], Node *root, int i, int n) {
    // Base case for recursion
    if (i < n) {
        Node *temp = newNode(arr[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

// Function to print tree nodes in
// InOrder fashion
void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        // std::cout << root->key << " ";
        inOrder(root->right);
    }
}

// Returns level of key k if it is present in tree,
// otherwise returns -1
int findLevel(Node *root, int k, int level) {
    // Base Case
    if (root == NULL)
        return -1;

    // If key is present at root, or in left subtree
    // or right subtree, return true;
    if (root->key == k)
        return level;

    int l = findLevel(root->left, k, level + 1);
    return (l != -1) ? l : findLevel(root->right, k, level + 1);
}

// This function returns pointer to LCA of two given
// values n1 and n2. It also sets d1, d2 and dist if
// one key is not ancestor of other
// d1 --> To store distance of n1 from root
// d2 --> To store distance of n2 from root
// lvl --> Level (or distance from root) of current node
// dist --> To store distance between n1 and n2
Node *findDistUtil(Node *root, int n1, int n2, int &d1, int &d2, int &dist,
                   int lvl) {
    // Base case
    if (root == NULL)
        return NULL;

    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->key == n1) {
        d1 = lvl;
        return root;
    }
    if (root->key == n2) {
        d2 = lvl;
        return root;
    }

    // Look for n1 and n2 in left and right subtrees
    Node *left_lca = findDistUtil(root->left, n1, n2, d1, d2, dist, lvl + 1);
    Node *right_lca = findDistUtil(root->right, n1, n2, d1, d2, dist, lvl + 1);

    // If both of the above calls return Non-NULL, then
    // one key is present in once subtree and other is
    // present in other. So this node is the LCA
    if (left_lca && right_lca) {
        dist = d1 + d2 - 2 * lvl;
        return root;
    }

    // Otherwise check if left subtree or right subtree
    // is LCA
    return (left_lca != NULL) ? left_lca : right_lca;
}

// The main function that returns distance between n1
// and n2. This function returns -1 if either n1 or n2
// is not present in Binary Tree.
int findDistance(Node *root, int n1, int n2) {
    // Initialize d1 (distance of n1 from root), d2
    // (distance of n2 from root) and dist(distance
    // between n1 and n2)
    int d1 = -1, d2 = -1, dist;
    Node *lca = findDistUtil(root, n1, n2, d1, d2, dist, 1);

    // If both n1 and n2 were present in Binary
    // Tree, return dist
    if (d1 != -1 && d2 != -1)
        return dist;

    // If n1 is ancestor of n2, consider n1 as root
    // and find level of n2 in subtree rooted with n1
    if (d1 != -1) {
        dist = findLevel(lca, n2, 0);
        return dist;
    }

    // If n2 is ancestor of n1, consider n2 as root
    // and find level of n1 in subtree rooted with n2
    if (d2 != -1) {
        dist = findLevel(lca, n1, 0);
        return dist;
    }

    return -1;
}

// Convert string to int
int stringToInt(std::string s) {
    int newint = 0;
    std::stringstream string1(s);
    string1 >> newint;
    return newint;
}

// Convert string to double
double stringToDouble(std::string s) {
    double newdouble = 0.0;
    newdouble = atof(s.c_str());
    return newdouble;
}

std::string getInputFileData() {
    std::string line, inputData;
    inputData = "";

    // Fetch the data from our the inputData file
    // Store the data in the string called lin
    std::ifstream file("input.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            inputData = inputData + line + "\n";
        }
        file.close();
    }
    return inputData;
}

int nthSubstr(int n, const std::string &s, const std::string &p) {
    std::string::size_type i = s.find(p); // Find the first occurrence
    int j;
    for (j = 1; j < n && i != std::string::npos; ++j) {
        i = s.find(p, i + 1); // Find the next occurrence
    }
    if (j == n) {
        return (i);
    } else {
        return (-1);
    }
}

void calculateResult(std::string inputData) {

    int m = 1;
    int numOfQueries = 0;
    int maxNumber = 0;

    std::string s = inputData.substr(0, inputData.find_first_of("\n"));
    numOfQueries = stringToInt(s);

    // std::cout << numOfQueries << std::endl;
    for (int i = 1; i <= numOfQueries; i++) {
        std::string s = inputData.substr(nthSubstr(m, inputData, "\n"),
                                         nthSubstr(m + 1, inputData, "\n"));
        m = m + 1;

        int a = stringToInt(s.substr(0));
        int b = stringToInt(s.substr(nthSubstr(1, s, " ")));

        if (a <= b)
            maxNumber = b;
        else
            maxNumber = a;
        int arr[maxNumber];
        for (int i = 0; i < maxNumber; i++) {
            arr[i] = i + 1;
            // std::cout << arr[i] << std::endl;
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        Node *root = insertLevelOrder(arr, root, 0, n);
        inOrder(root);
        std::cout << findDistance(root, a, b) << std::endl;
    }
}

int main(int argc, const char *argv[]) {

    std::string inputData = "";

    inputData = getInputFileData();
    calculateResult(inputData);

    return 0;
}

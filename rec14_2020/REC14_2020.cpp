// Saimanasa Juluru
// CS2124
// Rec 14
// 8 May 2020

#include <iostream>
using namespace std;

// task 1
bool isEvenOnes(int n) {
    if (n <= 0) {
        return true;
    }
    bool isTrue = (n % 2 == 0);
    return (isEvenOnes(n/2) == isTrue);
}
// task 2
struct Node{
    Node(int data, Node* next = nullptr): data(data), next(next) {};
    int data;
    Node* next;
};

Node* sumofLists(const Node* first, const Node* second) {
    if (first == nullptr && second == nullptr) {
        return nullptr;
    }
    if (first == nullptr) {
        return new Node(second->data, sumofLists(first->next, second));
    }
    if (second == nullptr) {
        return new Node(first->data, sumofLists(first->next, second));
    }
    return new Node(first->data + second->data, sumofLists(first->next, second->next));
}

// task 3
struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
            : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};

int max(TNode* root) {

    if (root == nullptr) {
        throw invalid_argument("This tree is empty.");
    }

    int maxValue = root->data;
    
    if (root->left != nullptr) {
        int leftMax = max(root->left);
        if (leftMax > maxValue) {
            maxValue = leftMax;
        }
    }
    if (root->right != nullptr) {
        int rightMax = max(root->right);
        if (rightMax > maxValue) {
            maxValue = rightMax;
        }
    }
    return maxValue;
}

// task 4
bool palindrome(char arr[], int size) {
    if (size <= 1){
        return true;
    }
    else if (arr[0] != arr[size-1]){
        return false;
    }
    else {
        return palindrome(arr+1, size-2);
    }
}

// task 5
int towers(int disks, char starting, char spare, char target){
    if (disks == 1){
        return 1;
    }
    int first = towers(disks-1, starting, target, spare);
    int second = towers(1, starting, spare, target);
    int third = towers(disks-1, spare, starting, target);
    return first + second + third;
}

// task 6
void mystery(int n) {
    if (n > 1) {
        cout << 'a';
        mystery(n/2);
        cout << 'b';
        mystery(n/2);
    }
    cout << 'c';
}

int main() {
    // task 1 tests
    // should return 0
    cout << isEvenOnes(111110) << endl;
    // should return 1
    cout << isEvenOnes(1111) << endl;
    // this should also return 1
    cout << isEvenOnes(0000) << endl;

    // task 4
    char s[] = "racecar";
    if (palindrome(s, 7)) { cout << "Yes!\n"; }

    char a[] = "apple";
    if (!palindrome(a, 5)) { cout << "Bro what.\n";}

//    // task 3
//    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
//    cout << max(&f) << endl;

    // task 5
    for (int i = 1; i < 11; ++i){
        cout << "towers(" << i << ", 'a', 'b', 'c'): ";
        cout << towers(i, 'a', 'b', 'c') << endl;
    }

    // task 6
    for (int i = 0; i < 11; i++) {
        cout << "n = " << i << " : ";
        mystery(i);
        cout << endl;
}


}

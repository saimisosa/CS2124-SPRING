/*
  functions for use with CS2124 rec11
  -jbs
*/
// Saimanasa Juluru
// CS2124
// Rec 11
// 17 April 2020
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Node to be used a part of linked list
struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

// listAddHead: adds a data item to the beginning of a [possibly empty] list
void listAddHead(Node*& headPtr, int entry) {
    headPtr = new Node(entry, headPtr);
}

// listClear: frees up all the nodes in a list
void listClear(Node*& headPtr) {
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
}

// listBuild: constructs a list from a vector of data items. Note that
// you can use a curly-braced sequence.
// This may be useful for setting up test cases. Feel free to use it
// or not as you like. 
// Example of using would be:
//    Node* myList = listBuild({1, 4, 9, 16}); // builds a list of: 1 4 9 16
Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
        listAddHead(result, vals[index-1]);
    }
    return result;
}

void splice(Node* newList, Node*& prev){
    if (prev == nullptr || newList == nullptr) return;

    if (prev->next == nullptr){
        prev->next = newList;
        return;
    }
    Node* prevNext = prev->next;
    prev->next = newList;
    while (newList->next != nullptr){
        newList = newList->next;
    }
    newList->next = prevNext;
}

Node* isSubList(Node* subList, Node* superList) { //dont pass pointer by ref if you dont wanna change it
    while (superList != nullptr){
        if (subList->data == superList->data){
            Node* temp = superList;
            Node* sub = subList;
            while (temp->data == sub->data && sub->next != nullptr){
                if (temp->next == nullptr){
                    return nullptr;
                }
                temp = temp->next;
                sub = sub->next;
            }
            if (temp->data == sub->data && sub->next == nullptr){
                return superList;
            }
        }
        superList = superList->next;
    }
    return nullptr;
}


int main(){
    cout << "====================="<<endl;
    cout << "PART ONE:" << endl;
    cout << "====================="<<endl;

    Node* lst1 = listBuild({1,2,3,4});
    Node* lst2 = listBuild({5,6,7,8});

    Node* orgLst = lst1;
    Node* spliceLst = lst2;

    cout << "Original List: ";

    while (orgLst != nullptr){
        cout << orgLst->data << " ";
        orgLst = orgLst->next;
    }

    cout << endl;

    cout << "New List: ";
    while (spliceLst != nullptr){
        cout << spliceLst->data << " ";
        spliceLst = spliceLst->next;
    }

    splice(lst2, lst1->next);
    Node* testList = lst1;
    cout << endl;
    cout << "Spliced List: ";
    while (testList != nullptr){
        cout << testList->data << " ";
        testList = testList->next;
    }
    cout<<endl;

    cout << "====================="<<endl;
    cout << "PART TWO"<<endl;
    cout << "====================="<<endl;

    Node* bigList = listBuild({1,2,3,2,3,2,4,5,6});
    Node* smallList = listBuild({2,3,2,4});

    Node* attempt1 = isSubList(smallList, bigList);

    if (attempt1 != nullptr){
        while (attempt1 != nullptr){
            cout << attempt1->data << " ";
            attempt1 = attempt1->next;
        }
    }
    else{
        cout << "Match Failed" <<endl;
    }



}
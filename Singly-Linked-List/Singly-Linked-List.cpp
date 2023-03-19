#include <iostream>

using namespace std;

class Node {
public:
    int Value;
    Node* Next;
};

void PrintList(Node* Head) {
    while (Head != NULL) {
        cout << Head->Value << endl;
        Head = Head->Next;
    }
}

void InsertAtBeginning(Node*& Head, int Value) {

    Node* Node1;
    Node1 = new Node();

    Node1->Value = Value;
    Node1->Next = Head;

    Head = Node1;

}

Node* Find(Node* Head, int Value) {
    while (Head != NULL) {
        if (Head->Value == Value) return Head;

        Head = Head->Next;
    }
    return NULL;
}

int main()
{
   Node* Head = NULL;

   InsertAtBeginning(Head, 1);
   InsertAtBeginning(Head, 2);
   InsertAtBeginning(Head, 3);
   InsertAtBeginning(Head, 4);
   InsertAtBeginning(Head, 5);

   PrintList(Head);
    

   //Searching for a node
   Node* NewNode = Find(Head, 4);

   if (NewNode == NULL) cout << "Node was not found :-(" << endl;
   else cout << "Node was found :-)" << endl;
}

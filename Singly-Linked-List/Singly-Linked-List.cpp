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

void InsertAfter(Node* PrevNode, int Value) {
    if (PrevNode == NULL) {
        cout << "Can not insert, node was not found" << endl;
        return;
    }
    
    Node* NewNode = new Node();

    NewNode->Value = Value;
    NewNode->Next = PrevNode->Next;
    
    PrevNode->Next = NewNode;
}

void InsertAtEnd(Node*& Head, int Value) {
    Node* NewNode = new Node();

    NewNode->Value = Value;
    NewNode->Next = NULL;

    if (Head == NULL) {
        Head = NewNode;
        return;
    }

    Node* LastNode = Head;

    while (LastNode->Next != NULL)
    {
        LastNode = LastNode->Next;
    }

    LastNode->Next = NewNode;

}

void Delete(Node*& Head, int Value) {
    if (Head == NULL) return;

    Node* Current = Head, * Prev = Head;

    if (Current->Value == Value) {
        delete Current;
        return;
    }

    while (Current->Value != Value) {
        Prev = Current;
        Current = Current->Next;
    }

    Prev->Next = Current->Next;

    delete Current;

}

void DeleteFirstNode(Node*& Head) {
    if (Head == NULL) return;

    Node* Current = Head;

    Head = Current->Next;
    delete Current;
}

void DeleteLastNode(Node*& Head) {
    if (Head == NULL) return;

    Node* Current = Head, * Prev = Head;

    if (Current->Next == NULL) {
        delete Current;
        return;
    }

    while (Current->Next != NULL) {
        Prev = Current;
        Current = Current->Next;
    }

    Prev->Next = NULL;

    delete Current;

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
   Node* Node = Find(Head, 4);

   if (Node == NULL) cout << "Node was not found :-(" << endl;
   else cout << "Node was found :-)" << endl;


   //Insert after this node
   InsertAfter(Node, 12);

   //Print list
   PrintList(Head);

   cout << endl;
   //Insert at end
   InsertAtEnd(Head, 19);

   //Print list
   PrintList(Head);

   cout << endl;
   //Delete
   Delete(Head, 12);

   //Print list
   PrintList(Head);

   cout << endl;
   //Delete first node
   DeleteFirstNode(Head);

   //Print list
   PrintList(Head);

   cout << endl;
   //Delete lasr node
   DeleteLastNode(Head);

   //Print list
   PrintList(Head);
}

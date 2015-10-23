#ifndef DBL_LINKED_LIST_H
#define DBL_LINKED_LIST_H
#include "Point.h"
// Make a type for a node's data item.
typedef Point NodeData;
//----- c l a s s D b l L I n k e d L i s t -----
class DblLinkedList
{
private:
    // List node class definition
    struct Node
    {
        NodeData data; // The "contents" of the node
        Node *pred; // Link to the predecessor node
        Node *succ; // Link to the successor node
        // Node Constructor Functions
        Node(){}
        Node(const NodeData &theData, const Node *prd = 0, const Node *suc = 0) :
        data(theData), pred((Node *) prd), succ((Node *) suc) { }
    };
public:
    // Constructor: Create an empty list.
    DblLinkedList();
    // True if the list is empty
    bool Empty() const;
    // True if the current position is beyond the last item.
    bool AtEnd() const;
    // Rewind the current item to the beginning of the list.
    void Rewind() { current = first; }
    // Advance to the next item in the list.
    void Forward();
    // Move back to the previous entry.
    void Backward();
    // Get the contents of the current list item.
    NodeData CurrentItem();
    // Get the contents of the first list item.
    NodeData FirstItem();
    // Get the contents of the last list item.
    NodeData LastItem();
    // Insert a new list item before the current item.
    void InsertItem(const NodeData &d);
    // Delete the current item.
    // The new current item was the successor of the deleted item.
    void DeleteItem();
private:
    Node *first; // Points to the first node in the list
    Node *last; // Points to the last node in the list
    Node *current; // Points to the current node
};
#endif
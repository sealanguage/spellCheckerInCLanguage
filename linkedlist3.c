#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    // variable for the data in a node
    int data;
    // link to the next item
    struct Node *next;     // Node here completes the struct Node
} Node;       //  use Node to complete the typedef Node


void push(int, struct Node*);
int pop(struct Node*);
int peek(struct Node*);
void freeList(Node*);    // free the memory of the list

int main(void)
{
    // this is making a
    printf("hello\n");
    Node* list = NULL;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = 5;
    newNode->next = NULL;

    // error here---------
    list = newNode;

    push(3, list);
    push(12, list);
    printf("%i\n", pop(list));
    push(14, list);
    printf("%i\n", pop(list));
    freeList(list);

    // int result = pop(head);

    // keep tract of the head of the Node
    // // remove after setting head to NULL above
    // struct Node* head = NULL;      //  pointer to a node
    // struct Node* second = NULL;     //  pointer to a node
    // struct Node* third = NULL;     //  pointer to a node

    // head = (struct Node*)malloc(sizeof(struct Node));   //  struct Node* is pointer to memory of Node
    // second = (struct Node*)malloc(sizeof(struct Node));
    // third = (struct Node*)malloc(sizeof(struct Node));

    //  give head data and have it point to the next node in the linked list
    // head->data = 5;
    // head->next = second;
    // second->data = 9;
    // second->next = third;
    // third->data = 3;
    // third->next = NULL;

    //  another way to do the same thing as above
    // head->next->data = 7;
    // head->next->next = third;
    // head->next->next->data = 0;
    // head->next->next->next = NULL;
}

// writing a function to dynamically add data to the linked list
// creating the box
void addNode(int data, struct Node* head)
{
    struct Node* trav = head;

    while(trav != NULL && trav->next != NULL)
    {
        trav = trav->next;
    }

    // go to the end of the list
    while(trav->next != NULL)
    {
        trav = trav->next;
    }
    // // pointing to the new box created above
    // trav->next = (struct Node*)malloc(sizeof (struct Node)
    // trav->next->data = data;
    // rav->next->next = NULL;

    // alternate way to do above
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    //  initialize the next to null
    if (trav == NULL)
    {
        head = newNode;
        return;
    }
    trav->next = newNode;
    // at end of list, create a new npde
}

int pop(struct Node* head)
{
    // create the traveller
    struct Node* trav = head;

    if (trav == NULL)
    {
        return -1;
    }
    // int counter = 0;

    // make a case for what happens for one node list
    // trav->next == NULL means this is a single item list
      if (trav->next == NULL)
    {
        // make a data variable at the node
        int data = trav->data;
        // free the node
        free(trav);
        return data;
    }

    // find the second to last node
    while(trav->next->next != NULL)
    {
        // printf("%i", counter++);
        trav = trav->next;
    }
    // store the data from the last item in the list
    int data = trav->next->data;
    // free the last block of memory
    free(trav->next);
    // set the new last node to NULL
    trav->next = NULL;
    // returns the data that was in the node
    return data;

}

// go to last item, looks at last number and returns it
int peek(struct Node* head)
{
    struct Node* trav = head;

    //  code to deal with single node list,
    if(trav->next == NULL)
    {
        int data = trav->data;
        return data;
    }

    //  as long as the next pointer is not null
    while(trav->next != NULL)
    {
        // travel down the list
        trav = trav->next;
    }
    // gather the data at the last node
    int data = trav->data;
    // return that data
    return data;
}

// every version of this function believes it is the root
void freeList(Node* root)
{
    // pointing at the top item in the list. base case looks for second to last item or call function till we are on second last item
    struct Node* trav = root;

    //  for the case where a header pointer exists but there is nothing in it.
    if (trav == NULL)
    {
        return;
    }

    // if we are on a single item, list code runs, frees the memory for the node effectively erasing it, else it moves to the next statement
    if (trav->next == NULL)
    {
        // removes the single item
        free(trav);
        return;
    }

    //  if we are on second last item
    if (trav->next->next == NULL)
    {
        //  free the last item from memory
        free(trav->next);
        // have the node erase itself and move to current node
        free(trav);
        // //  set final pointer to null, but will give false positive
        // trav->next = NULL;
        // go back up the list of function calls use RETURN
        return;
    }
    // rerun freeList function to find what is now second last items
    freeList(trav->next);
    // recursively removes current nodes till it gets back to noce 1
    free(root);
    return;
}

void freeListNew(Node* trav)
{
    // check if we are on last node
    if(trav->next == NULL)
    {
        free(trav);
        return;
        // this recursion is like doing a factorialize (fac 5 = 5 x 4, fac 4 = 4 x 3)
        freeListNew(trav->next);
        free(trav);
    }
}



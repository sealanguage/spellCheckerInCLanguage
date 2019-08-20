#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct listNode
{
    int data;
    // link to the next item
    struct listNode *next;     // Node here completes the struct Node
} listNode;       //  use Node to complete the typedef Node


//  challenge create a binary Node Struct
typedef struct BinaryNode
{
    int data;
    struct BinaryNode *smaller;
    struct BinaryNode *larger;
} BinaryNode;

// common syntax at the top of a binary tree
BinaryNode* root = NULL;
// declare the functions here
void add(int);
int seek(int);  //  true 1 or false 0 if item exists in tree
void freeTree(BinaryNode*);

// function to run to see if add and seek will work
void testTree()
{
    add(5);
    assert(seek(5) == 1 && "tree contains the number 5");  //modify the true to use seek
    add(3);
    add(4);
    assert(seek(9) == 0 && "tree does not contain 9");

}

void testAdd()
{
    add(5);
    assert(seek(5) && "found the added 5");
    add(2);
    assert(seek(2) && "found the new number 2");
    assert(seek(5) && "5 still exists");
    add(1);
    assert(seek(1) && "1 was added successfully");
    assert(seek(2) && "2 still exists");
    add(8);
    assert(seek(8) && "8 was found");
    add(9);
    add(3);
    assert(seek(9) && seek(3) && "9 and 3 were found");
    assert(seek(8) && "8 still exists");

}

void testFree()
{
    add(5);
    assert(seek(5) && "5 was added");
    add(2);
    add(1);
    add(8);
    add(3);
    add(9);
    freeTree(root);
    assert(!seek(5) && "5 was cleared");
    assert(!seek(2) && "2 was cleared");
    assert(!seek(1) && "1 was cleared");
    assert(!seek(8) && "8 was cleared");


}

void bruteForceTree()
{
    root = malloc(sizeof(BinaryNode));
    root->data = 5;

    BinaryNode* leftNode = malloc(sizeof(BinaryNode));
    leftNode->data = 2;
    leftNode->smaller = NULL;
    leftNode->larger = NULL;

    BinaryNode* rightNode = malloc(sizeof(BinaryNode));
    rightNode->data = 8;
    rightNode->smaller = NULL;
    rightNode->larger = NULL;

    // root node needs to point to left and right
    root->smaller = leftNode;
    root->larger = rightNode;
}

void testSeek()
{
    bruteForceTree();
    assert(seek(5) && "found 5");
    assert(seek(2) && "found 2");
    assert(!seek(1) && "confirm 1 does not exist");
    assert(seek(8) && "found 8");
    assert(!seek(9) && "confirm 9 does not exist right right");
    assert(!seek(3) && "confirm 3 does not exist left right");
    assert(!seek(7) && "confirm 7 does not exist right left");
}


int main(void)
{
    // this is making a
    printf("hello\n");
    // int data[] = {5, 8, 2, 9, 4, 1, 3};
    // testTree();
    // testSeek();
    // testAdd();
    testFree();
}


int seek(int query)
{
    //  seek will scan the tree for number sent.
    // returns 0 if number is not found in the tree
    // returns 1 if number is found in the tree

    // printf("%i\n", data);

    // create traveler to travel the tree
    // start at the top
    BinaryNode* nav = root;

    // this is like creating an event loop waiting for an event - repeat the code till it reaches a conditional
    while(true && "Not at the end of a branch or haven't found the data yet")
    {
        // c sees while true because string is truthy


        // do we have the number?

        // how to find
        // check current node's data
        if (nav->data == query)
        {
            return 1;
        }
        // if found 1
        // else
        if (query < nav->data)
        // is current node larger or smaller than query searched number
        {
            // go smallersmaller route
            // check if there is a node in that direction

            // if there is no node (NULL) return 0
            if (nav->smaller == NULL)
            {
                return 0;
            }
            // if there is a node, continue seeking
            nav = nav->smaller;
            continue;
        }
        // based on the logic and coding above, the only way the code reaches this line, the query is greater than
        if (nav->larger == NULL)
        {
            return 0;
        }
        nav = nav->larger;
        continue;


    }


    return 0;
}

// ***********
void add(int item)
{
    // add the item to the node base of the following rules
    // it item is larger than current node move to right (larger) route
    // if item is smaller than current node move to the left (smaller route

    // creates the node
    BinaryNode* newNode = malloc(sizeof(BinaryNode));
    // set the content to null
    newNode->data = item;
    newNode->smaller = NULL;
    newNode->larger = NULL;
    // printf("%i\n", item);

    // if there is no tree yet, this added item is the root node
    if (root == NULL)
    {
        // create the root of the new node
        root = newNode;
        return;
    }
    // a template for the add function
    // while(true)
    // {
    //     // get add working
    //     printf("%i\n", item);
    //     return;
    // }

    // create a navigator for the add function
    BinaryNode* nav = root;

    // iterate through the tree comparing nodes with the value of item
    while("end of branch not found")  //  this text string is truthy because it is a string not empty
    {
        // if item is smaller than root
        if (item < nav->data)
        {
            // if there is no node on the smaller route
            if (nav->smaller != NULL)
            {
                //  look before you leap
                // travel to the left
                nav = nav->smaller;
                // because of continue the loop won't
                continue;

            }
            nav->smaller = newNode;
            return;
        }

            // add the larger item to the right
        if (item > nav->data)
        {

            // go larger
            if (nav->larger != NULL)
            {
                nav = nav->larger;
                continue;
            }
            nav->larger = newNode;
            return;
        }
        return;
    }
}

// finish this code: 19 feb
void freeTree(BinaryNode* nav)
{
    // free all the nodes in the tree
    // navigate through the tree and start freeing from the end of the branches


    // BinaryNode* nav = root;
    if (nav->smaller == NULL && nav->larger == NULL)
    {
        free(nav);
        return;
    }
    // if code gets here, we know the node has childrn
    if (nav->smaller != NULL)
    {
        freeTree(nav->smaller);

    }
    if (nav->larger != NULL)
    {
        freeTree(nav->larger);
    }
    free(nav);
    return;

}

// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 

// Represents number of children for each node in a trie
#define N 27
// const int CASE = 'a';

// Represents a node in a trie
typedef struct trieNode
{
    bool is_word;
    struct trieNode *children[N];
    //  struct node* next is single list, struct node* children is the way to do the same thing for the trie
    
    int nodeValue;      //  the value of the letter to put in the node
    struct trieNode *next;
    int occurrences;      //  probably will be misspellings later
}trieNode;

// Represents a trie ******* is this needed
// trieNode *newNode;
trieNode *rootNode;
//  parent = NULL;
int occurrences = 0;    //  probably will be misspellings later
int nodeValue;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize trie
   trieNode *newNode = malloc(sizeof(trieNode));
        for (int i = 0; i < N; i++)
        {
            newNode->children[i] = NULL;    //   all set 27 pointers to NULL
        }

        if (newNode == NULL)
        {
            rootNode = newNode;
            newNode->is_word = false;
            return false;
        }
    // set the is_word boolean to false for all the childern of the node
    
    //  create 27 children pointers of [N]
    
    // Open dictionary
    FILE *file = fopen(dictionary, "r");
//     printf("dictionary is here\n");
    if (file == NULL)
    {
        unload();
        return false;
    }
    printf("\nfile %s\n", dictionary);

    // Buffer for a word  // // this is where the words are held
    char word[LENGTH + 1];
   
    // Insert words into trie
    // for each word in dictionary iterate through the trie
    while (fscanf(file, "%s", word) != EOF)   //  while the dictionary has words in it get words
    {
        printf("\nthe word is %s\n\n", word);
//         printf("get a letter from the word %s\n", word);
        // TODO
        // 
        // 
        // HERE HERE HERE HERE HERE HERE TO MALLOC NEW NODES AND INSERT THE VALUE, MOVE TRAV
        int letterPosition; 
        int wordLength = strlen(word); 
        int theLetter = 0; 
        //  assign a traveller to the root
        trieNode* trav = rootNode;
        //  create a variable to create new nodes called newNode
//          trieNode *navig = root;
//          trieNode* newNode = (trieNode*)malloc(sizeof(trieNode));
        //  for the first node in the trie,  |  for each letter in the word  |  iterate through the letters in the word
        for(letterPosition = 0; letterPosition < wordLength; letterPosition++)
        {
            //////////
            //  set the ascii value of the letters to index at 0
            theLetter = (word[letterPosition] - 'a'); 
            //  printf("theLetter %d\n", theLetter);
            printf("the letter is %c\n", word[letterPosition]);
            printf("the ascii value is %d\n", (word[letterPosition] - 'a'));
            printf("letterPosition index is %d\n", (letterPosition));
            
            //  if no node exists at the alphaPointer location 
            if (newNode->children[theLetter] == NULL)
            {
                printf("newNode->children[theLetter] conditional started\n");
                newNode = malloc(sizeof(trieNode));     //  malloc a new trieNode
                bool is_word = false;
                printf("is word = false\n");
                for (int i = 0; i < N; i++)      //  put in 27 pointers and s
                {
                     newNode->children[i] = NULL;     //   all set to NULL   
                    //  this is making 27 null pointers on the node
                }   
                //  put the value of the letter position into the node
                printf("!!!    new trie node made here      !!!\n");
                                
                //  move the trav to point to the new Node
                trav = newNode->children[theLetter];
                printf("the value of theLetter is %d\n", theLetter);
                // print statement shows that the loop iterates through the different letters of the dictionary
                printf("trav is %d\n\n", theLetter);
                

                
                // NEED TO PUT THE CHARACTER INTO THE NEWNODE OF THE TRIE
                //  THEN CYCLE BACK UP TO ROOT TO START FOLLOWING THE TRIE AGAIN
                continue;
                
                    //    
                    if (newNode->children[theLetter] != NULL)
                    {
                        printf("moving to next letter");
                        continue;
                    }
            }
            bool is_word = true;
            printf("is_word = true");
          
        //  

            
        }
            
    }
        
// printf("\nContents of a structure %s are:\trieNode: %d\nis_word: %d\n", trieNode->name, trieNode->, trieNode->is_word);
    
    
    
    
//      for every word in the dictionary
//          for each letter in the word
//              if (the node alpha pointer points to NULL)
//                  malloc a new trieNode
//                      Have children[i] point to it
//                          
         

//             
// Inserting a key into Trie is a simple approach. 
// Every character of the input key is inserted as an individual Trie node.
// Note that the children is an array of pointers (or references) to next level trie nodes. 
// The key character acts as an index into the array children. 
// If the input key is new or an extension of the existing key, we need to construct non-existing nodes of the key, and mark end of the word for the last node. 
// If the input key is a prefix of the existing key in Trie, we simply mark the last node of the key as the end of a word. 
// The key length determines Trie depth.

//     }     

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    
//     check should return true for words in the dictionary
    // TODO
    // Searching for a key is similar to insert operation, 
    // we only compare the characters and move down. 
    // search can terminate due to the end of a string if the isEndofWord field of the last node is true, then the key exists in the trie. 
    // 
    // search can terminate due to lack of key in the trie, the search terminates without examining all the characters of the key, since the key is not present in the trie.
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO

    return false;
}

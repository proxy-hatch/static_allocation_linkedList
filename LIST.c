//
// Created by Shawn on 23/05/17.
//

#pragma once
#ifndef DEBUG
#define DEBUG

#include <stdio.h>  // for listPrint();

#endif

#include "LIST.h"
//#include <stdint.h> //type (intptr_t)
#include <string.h> //memset()



//-------------------------------------------------------------------------------------------------
//---------------------------------- Data Structure Definitions -----------------------------------
//-------------------------------------------------------------------------------------------------

// initialize lists array
// note: memset or any procedural initialization is prohibited outside a func (int main for example)
// to maintain encapsulation this workaround syntax that is ONLY AVAILABLE in gcc is employed
// https://stackoverflow.com/a/207702
list lists[MAXLISTCOUNT] = {[0 ... MAXLISTCOUNT - 1].head=NULL, [0 ... MAXLISTCOUNT - 1].tail=NULL,
        [0 ... MAXLISTCOUNT - 1].curr=NULL, [0 ... MAXLISTCOUNT - 1].nodeCount=0, [0 ... MAXLISTCOUNT -
                                                                                         1].boolActive=0};

// variable to keep the number of lists USED
int numLists = 0;

// initialize nodePool array
// TWO extra slots in the end are reserved to represent BEFORE and AFTER status of list::curr
// e.g., if(aList.curr==aList.head){ *ListPrev(aList) results in aList.curr=&(nodePool[MAXLISTCOUNT * MAXLISTSIZE + 1]) }
// these last two slots should be IMMUTABLE
node nodePool[MAXLISTCOUNT * MAXLISTSIZE + 2] = {[0 ... MAXLISTCOUNT * MAXLISTSIZE + 1].data=NULL,
        [0 ... MAXLISTCOUNT * MAXLISTSIZE + 1].next=NULL, [0 ... MAXLISTCOUNT * MAXLISTSIZE + 1].prev=NULL,
        [0 ... MAXLISTCOUNT * MAXLISTSIZE + 1].boolActive=0};

// variable to keep the number of nodes USED
int numNodes = 0;

//-------------------------------------------------------------------------------------------------
//---------------------------------- Implementation Definitions ----------------------------------
//-------------------------------------------------------------------------------------------------

// makes a new, empty list, and returns its reference on success. Returns a NULL pointer on failure.
list *ListCreate() {
    // error check
    if (numLists >= MAXLISTCOUNT)
        return NULL;

    lists[numLists].boolActive = 1;
    return &(lists[numLists++]);
}

// returns the number of items in list.
int ListCount(const list *aList) {
    // Error Check: -1 indicates node is uninitialized
    if (!aList->boolActive)
        return -1;
    return aList->nodeCount;
}

// returns a pointer to the first item in list and makes the first item the current item.
void *ListFirst(list *aList) {
    aList->curr = aList->head;
    if (aList->head)
        return aList->head->data;
    else
        return NULL;
}

// returns a pointer to the last item in list and makes the last item the current one.
void *ListLast(list *aList) {
    aList->curr = aList->tail;
    if (aList->tail)
        return aList->tail->data;
    else
        return NULL;
}

// advances list's current item by one, and returns a pointer to the new current item.
// If this operation advances the current item beyond the end of the list, a NULL pointer is returned.
void *ListNext(list *aList) {
    // error check
    if (!aList->boolActive || (!aList->head != !aList->tail) ||
        ((aList->curr < nodePool || aList->curr > nodePool + MAXLISTCOUNT * MAXLISTSIZE + 1) && aList->curr))
        return (void *) 1;

    // declare ptr variable to return
    void *returnVar;

    // if curr is NULL: unset to anything, ignore
    if (!aList->curr)
        returnVar = NULL;
        // curr at tail, make curr go out of bounds in the tail direction
    else if (aList->curr == aList->tail) {
        aList->curr = nodePool + MAXLISTCOUNT * MAXLISTSIZE + 1;
        returnVar = NULL;
    }// if curr was out of bounds in the head direction, bring it back to head
    else if (aList->curr == nodePool + MAXLISTCOUNT * MAXLISTSIZE) {
        aList->curr = aList->head;
        if (aList->head)
            returnVar = aList->head->data;
        else
            returnVar = NULL;
    }// if curr was out of bounds in the tail direction, keep the curr ptr there and return NULL
    else if (aList->curr == nodePool + MAXLISTCOUNT * MAXLISTSIZE + 1) {
        returnVar = NULL;
    } else {
        if (aList->curr == aList->tail) {
            // set it to go out of bounds in the tail direction
            aList->curr = nodePool + MAXLISTCOUNT * MAXLISTSIZE + 1;
            returnVar = NULL;
        } else {
            aList->curr = aList->curr->next;
            returnVar = aList->curr->data;
        }
    }
    return returnVar;
}

// backs up list's current item by one, and returns a pointer to the new current item.
// If this operation backs up the current item beyond the start of the list, a NULL pointer is returned.
void *ListPrev(list *aList) {
    // error check
    if (!aList->boolActive || (!aList->head != !aList->tail) ||
        ((aList->curr < nodePool || aList->curr > nodePool + MAXLISTCOUNT * MAXLISTSIZE + 1) && aList->curr))
        return (void *) 1;

    // declare ptr variable to return
    void *returnVar;

    // if curr is NULL: unset to anything, ignore
    if (!aList->curr)
        returnVar = NULL;
        // curr at head, make curr go out of bounds in the head direction
    else if (aList->curr == aList->head) {
        aList->curr = nodePool + MAXLISTCOUNT * MAXLISTSIZE;
        returnVar = NULL;
    }// if curr was out of bounds in the tail direction, bring it back to tail
    else if (aList->curr == nodePool + MAXLISTCOUNT * MAXLISTSIZE + 1) {
        aList->curr = aList->tail;
        if (aList->tail)
            returnVar = aList->tail->data;
        else
            returnVar = NULL;
    }// if curr was out of bounds in the head direction, keep the curr ptr there and return NULL
    else if (aList->curr == nodePool + MAXLISTCOUNT * MAXLISTSIZE) {
        returnVar = NULL;
    } else {
        if (aList->curr == aList->head) {
            // set it to go out of bounds in the head direction
            aList->curr = nodePool + MAXLISTCOUNT * MAXLISTSIZE;
            returnVar = NULL;
        } else {
            aList->curr = aList->curr->prev;
            returnVar = aList->curr->data;
        }
    }
    return returnVar;
}

// returns a pointer to the current item in list.
void *ListCurr(list *aList) {
    if (aList->curr)
        return aList->curr->data;
    else return NULL;
}

// adds the new item to list directly after the current item, and makes item the current item.
// If the current pointer is before the start of the list, the item is added at the start.
// If the current pointer is beyond the end of the list, the item is added at the end. Returns 0 on success, -1 on failure.
int ListAdd(list *aList, void *anItem) {
    // error check
    if (!aList->boolActive || (!aList->head != !aList->tail))
        return -1;

    // additional error checks: curr ptr is invalid, but list is not empty: ERROR
    // DONT KNOW WHERE TO INSERT!
    if (!aList->curr && aList->head) // && !aList->tail)
        return -1;
    if ((aList->curr < nodePool || aList->curr > nodePool + MAXLISTCOUNT * MAXLISTSIZE + 1) && aList->curr &&
        aList->head)
        return -1;

    // pull new node from nodePool
    // Check if theres available node (should always be available because nodePool size is determined by MAXLISTCOUNT*MAXLISTSIZE && if list is filled
    if (numNodes > MAXLISTCOUNT * MAXLISTSIZE - 2 || aList->nodeCount >= MAXLISTSIZE)
        return -1;  // No empty node in nodePool
    node *newNodePtr = nodePool + numNodes++;
    newNodePtr->data = anItem;
    newNodePtr->boolActive = 1;

    // decide where to put this new node
    if (!aList->head)    // && !aList->tail, empty list
        // note: aList->curr might also be NULL/invalid, but we don't care
    {
        aList->head = newNodePtr;
        aList->tail = newNodePtr;
        aList->curr = newNodePtr;
    } // out of bounds in the tail direction
    else if (aList->curr == nodePool + MAXLISTCOUNT * MAXLISTSIZE + 1) {
        aList->tail->next = newNodePtr;
        newNodePtr->prev = aList->tail;
        aList->tail = newNodePtr;
        aList->curr = newNodePtr;
    }// out of bounds in the head direction
    else if (aList->curr == nodePool + MAXLISTCOUNT * MAXLISTSIZE) {
        aList->head->prev = newNodePtr;
        newNodePtr->next = aList->head;
        aList->head = newNodePtr;
        aList->curr = newNodePtr;
    } else { // normal case + (when aList->curr == aList->tail)
        newNodePtr->next = aList->curr->next; // could be NULL if aList->curr=aList->tail
        newNodePtr->prev = aList->curr;
        aList->curr->next = newNodePtr;

        if (aList->curr == aList->tail)
            aList->tail = newNodePtr; // set new tail
        else
            newNodePtr->next->prev = newNodePtr;

        aList->curr = newNodePtr;
    }
    aList->nodeCount++;
    return 0;
}

// adds item to list directly before the current item, and makes the new item the current one.
// If the current pointer is before the start of the list, the item is added at the start.
// If the current pointer is beyond the end of the list, the item is added at the end. Returns 0 on success, -1 on failure.
int ListInsert(list *aList, void *anItem) {
    // error check
    if (!aList->boolActive || (!aList->head != !aList->tail))
        return -1;

    // additional error checks: curr is invalid, but list is not empty: ERROR
    // DONT KNOW WHERE TO INSERT!
    if (!aList->curr && aList->head) // && !aList->tail)
        return -1;
    if ((aList->curr < nodePool || aList->curr > nodePool + MAXLISTCOUNT * MAXLISTSIZE + 1) && aList->curr &&
        aList->head)
        return -1;

    // pull new node from nodePool
    // Check if theres available node && if list is filled
    if (numNodes > MAXLISTCOUNT * MAXLISTSIZE - 2 || aList->nodeCount >= MAXLISTSIZE)
        return -1;
    node *newNodePtr = nodePool + numNodes++;
    newNodePtr->data = anItem;
    newNodePtr->boolActive = 1;

    // decide where to put this new node
    if (!aList->head)    // && !aList->tail, empty list
        // note: aList->curr might also be NULL/invalid, but we don't care
    {
        aList->head = newNodePtr;
        aList->tail = newNodePtr;
        aList->curr = newNodePtr;
    } // out of bounds in the tail direction
    else if (aList->curr == nodePool + MAXLISTCOUNT * MAXLISTSIZE + 1) {
        aList->tail->next = newNodePtr;
        newNodePtr->prev = aList->tail;
        aList->tail = newNodePtr;
        aList->curr = newNodePtr;
    }// out of bounds in the head direction
    else if (aList->curr == nodePool + MAXLISTCOUNT * MAXLISTSIZE) {
        aList->head->prev = newNodePtr;
        newNodePtr->next = aList->head;
        aList->head = newNodePtr;
        aList->curr = newNodePtr;
    } else { // normal case + (when aList->curr == aList->head)
        newNodePtr->prev = aList->curr->prev; // could be NULL if aList->curr=aList->tail
        newNodePtr->next = aList->curr;
        aList->curr->prev = newNodePtr;

        if (aList->curr == aList->head)
            aList->head = newNodePtr; // set new tail
        else
            newNodePtr->prev->next = newNodePtr;

        aList->curr = newNodePtr;
    }
    aList->nodeCount++;
    return 0;
}

// adds item to the end of list, and makes the new item the current one. Returns 0 on success, -1 on failure.
int ListAppend(list *aList, void *anItem) {

}

// adds item to the front of list, and makes the new item the current one. Returns 0 on success, -1 on failure.
int ListPrepend(list *aList, void *anItem) {

}

// Return current item and take it out of list. Make the next item the current one.
void *ListRemove(list *aList) {

}

// adds list2 to the end of list1. The current pointer is set to the current pointer of list1.
// List2 no longer exists after the operation.
void ListConcat(list list1, list list2) {

}

// delete list. itemFree is a pointer to a routine that frees an item. It should be invoked (within ListFree) as:
// (*itemFree)(itemToBeFreed)
// Example: https://stackoverflow.com/questions/1789807/function-pointer-as-an-argument
void ListFree(list *aList, void (*itemFree)()) {

}

// Return last item and take it out of list. Make the new last item the current one.
void *ListTrim(list *aList) {

}

// searches list starting at the current item until the end is reached or a match is found.
// In this context, a match is determined by the comparator parameter.
// This parameter is a pointer to a routine that takes as its first argument an item pointer, and as its second argument comparisonArg.
// Comparator returns 0 if the item and comparisonArg don't match, or 1 if they do.
// Exactly what constitutes a match is up to the implementor of comparator.
// If a match is found, the current pointer is left at the matched item and the pointer to that item is returned.
// If no match is found, the current pointer is left beyond the end of the list and a NULL pointer is returned.
void *ListSearch(list *aList, void *comparator, void *comparisonArg) {

}

#ifdef DEBUG

// debugging function used to print list
void listPrint(list *aList) {
    if (!aList) {
        printf("Error: NULL pointer passed into listPrint()!\n");
        return;
    }
    if (aList->boolActive)
        printf("List is activated\n");
    else
        printf("List is NOT activated\n");
    node *tempPtr = aList->head;
    printf("Begin Print: \n");
    int i = 0;
    while (tempPtr) {
        printf("number %d: ", i++);
        if (tempPtr->data)
            printf("%d\n", *(int *) (tempPtr->data));
        tempPtr = tempPtr->next;
    }
    printf("Finished\n");
    node *tempPtr2 = aList->curr;
    int ii = 0;

    while (tempPtr2 != aList->head && tempPtr2 > nodePool && tempPtr2 < nodePool + MAXLISTCOUNT * MAXLISTSIZE + 1 &&
           tempPtr2) {
        tempPtr2 = tempPtr2->prev;
        ii++;
    }
    if (aList->curr)
        printf("list->curr is now at position #%d (value: %d)\n\n", ii, *(int *) aList->curr->data);
    else
        printf("list->curr is INVALID\n\n");
}

#endif
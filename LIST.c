//
// Created by Shawn on 23/05/17.
//

#pragma once

#include "LIST.h"
#include <stdint.h> //type (intptr_t)
#include <string.h> //memset()



//-------------------------------------------------------------------------------------------------
//---------------------------------- Data Structure Definitions -----------------------------------
//-------------------------------------------------------------------------------------------------

// initialize lists array
// TWO extra slots in the end are reserved to represent BEFORE and AFTER status of list::curr
// e.g., if(aList.curr==aList.head){ *ListPrev(aList) results in aList.curr=&(lists[MAXLISTCOUNT+1]) }
// these last two slots should be IMMUTABLE
list lists[MAXLISTCOUNT+2];
// initialize each node in list to NULL
// see https://stackoverflow.com/questions/22465908/how-could-i-initialize-a-array-of-struct-to-null
memset(lists,0,sizeof(lists));
// variable to keep the number of lists USED
int numLists = 0;

// initialize nodePool array
node nodePool[MAXLISTCOUNT * MAXLISTSIZE];

memset(nodePool,0,sizeof(nodePool));
// variable to keep the number of nodes USED
int numNodes;

//-------------------------------------------------------------------------------------------------
//---------------------------------- Implementation Definitions ----------------------------------
//-------------------------------------------------------------------------------------------------

// makes a new, empty list, and returns its reference on success. Returns a NULL pointer on failure.
list *ListCreate() {
    // error check
    if(numLists>=MAXLISTCOUNT)
        return NULL;

    lists[numLists].boolActive=1;
    return &(lists[numLists++]);
}

// returns the number of items in list.
int ListCount(const list aList) {
    // Error Check: -1 indicates node is uninitialized
    if(!aList.boolActive)
        return -1;

    return aList.nodeCount;
}

// returns a pointer to the first item in list and makes the first item the current item.
void *ListFirst(list aList) {
    aList.curr=aList.head;
    return aList.head;
}

// returns a pointer to the last item in list and makes the last item the current one.
void *ListLast(list aList) {
    aList.curr=aList.tail;
    return aList.tail;
}

// advances list's current item by one, and returns a pointer to the new current item.
// If this operation advances the current item beyond the end of the list, a NULL pointer is returned.
void *ListNext(list aList) {
    if (!aList.boolActive||aList.curr<lists||aList.curr>lists+MAXLISTCOUNT+1)
        return -1;

    // declare ptr variable to return
    void *returnVar;

    // workaround to switch on pointers:
    // https://stackoverflow.com/questions/2308323/why-no-switch-on-pointers
    switch((intptr_t)aList.curr)
    {
        // if curr was out of bounds in the head direction, bring it back to head
        case (intptr_t)lists+MAXLISTCOUNT:
            aList.curr=aList.head;
            returnVar=aList.head;
            break;
        // if curr was out of bounds in the tail direction, do nothing and return NULL
        case (intptr_t)lists+MAXLISTCOUNT+1:
            returnVar=NULL;
            break;
        default:
            aList.curr=aList.curr->next;
            returnVar=aList.curr;
            break;
    }
    return returnVar;
}

// backs up list's current item by one, and returns a pointer to the new current item.
// If this operation backs up the current item beyond the start of the list, a NULL pointer is returned.
void *ListPrev(list aList) {
    if(aList.curr)
        aList.curr=aList.curr->prev;
    else
        return NULL;
}

// returns a pointer to the current item in list.
void *ListCurr(list aList) {
    return aList.curr;
}

// adds the new item to list directly after the current item, and makes item the current item.
// If the current pointer is before the start of the list, the item is added at the start.
// If the current pointer is beyond the end of the list, the item is added at the end. Returns 0 on success, -1 on failure.
int ListAdd(list aList, void *anItem) {

}

// adds item to list directly before the current item, and makes the new item the current one.
// If the current pointer is before the start of the list, the item is added at the start.
// If the current pointer is beyond the end of the list, the item is added at the end. Returns 0 on success, -1 on failure.
int ListInsert(list aList, void *anItem) {

}

// adds item to the end of list, and makes the new item the current one. Returns 0 on success, -1 on failure.
int ListAppend(list aList, void *anItem) {

}

// adds item to the front of list, and makes the new item the current one. Returns 0 on success, -1 on failure.
int ListPrepend(list aList, void *anItem) {

}

// Return current item and take it out of list. Make the next item the current one.
void *ListRemove(list aList) {

}

// adds list2 to the end of list1. The current pointer is set to the current pointer of list1.
// List2 no longer exists after the operation.
void ListConcat(list list1, list list2) {

}
// delete list. itemFree is a pointer to a routine that frees an item. It should be invoked (within ListFree) as:
// (*itemFree)(itemToBeFreed){

}// Example: https://stackoverflow.com/questions/1789807/function-pointer-as-an-argument
void ListFree(list aList, void (*itemFree)()) {

}

// Return last item and take it out of list. Make the new last item the current one.
void *ListTrim(list aList) {

}

// searches list starting at the current item until the end is reached or a match is found.
// In this context, a match is determined by the comparator parameter.
// This parameter is a pointer to a routine that takes as its first argument an item pointer, and as its second argument comparisonArg.
// Comparator returns 0 if the item and comparisonArg don't match, or 1 if they do.
// Exactly what constitutes a match is up to the implementor of comparator.
// If a match is found, the current pointer is left at the matched item and the pointer to that item is returned.
// If no match is found, the current pointer is left beyond the end of the list and a NULL pointer is returned.
void *ListSearch(list aList, void *comparator, void *comparisonArg) {

}
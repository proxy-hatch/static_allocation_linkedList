
#include <stdio.h>
#include "LIST.h"

// sample supporting functions
void delStatic(int *dataPtr){}
void delDynamic(int *dataPtr){
    free(dataPtr);
}
int compareInts(int *data1, int *data2){
    return *data1 == *data2 ? 1 : 0;
}

int main() {
    int a = 5;
    int b = 10;
    int c = 15;
    int d = 20;
    int *dataPtr;

    //-----------------------------------------------------------------------------------------------------------------
    // ListCreate() tests
    // normal case - pass
    // MAXLISTCOUNT reached - pass
    puts("ListCreate() tests\n\n");
    list *emptyList1=ListCreate();
    list *emptyList2=ListCreate();
    list *emptyList3;
    list *emptyList4;
    list *emptyList5;
#ifdef DEBUG
    listPrint(emptyList1);
    listPrint(emptyList2);
#endif
    puts("\n-----------------------------------------------------\n");

    //################################################################################################
    //# NOTE: THE FOLLOWING SECTIONS MAY ONLY BE RAN ONE AT A TIME, WHILE #DEBUG MACRO IS TURNED ON  #
    //################################################################################################

    //-----------------------------------------------------------------------------------------------------------------
    // ListNext(list *aList)/ListPrev(list *aList) tests
    puts("ListNext(list *aList)/ListPrev(list *aList) tests\n\n");
    // empty list - pass/pass
    // non-empty - pass/pass
    // at head - pass/pass
    // at tail - pass/pass
    // out of bounds at head direction - pass/pass
    // out of bounds at tail direction - pass/pass
    dataPtr=ListNext(emptyList1);
    if(!dataPtr)
        printf("ListNext() returned NULL!\n");
    else if((int)dataPtr==1)
        printf("ListNext() returned ERROR!\n");
    else
        printf("ListNext() returned %d\n",*dataPtr);
    dataPtr=ListPrev(emptyList1);
#ifdef DEBUG
    listPrint(emptyList1);
#endif
    if(!dataPtr)
        printf("ListPrev() returned NULL!\n");
    else if((int)dataPtr==1)
        printf("ListPrev() returned ERROR!\n");
    else
        printf("ListPrev() returned %d\n",*dataPtr);
#ifdef DEBUG
    listPrint(emptyList1);
#endif
    ListInsert(emptyList1,&c);
    ListInsert(emptyList1,&b);
    ListInsert(emptyList1,&a);
#ifdef DEBUG
    listPrint(emptyList1);
#endif

////    // should go out of bounds in the head direction after this function call
////    dataPtr=ListPrev(emptyList1);
////    if(!dataPtr)
////        printf("ListPrev() returned NULL!\n");
////    else if((int)dataPtr==1)
////        printf("ListPrev() returned ERROR!\n");
////    else
////        printf("ListPrev() returned %d\n",*dataPtr);
////    listPrint(emptyList1);
////    dataPtr=ListPrev(emptyList1);
////    if(!dataPtr)
////        printf("ListPrev() returned NULL!\n");
////    else if((int)dataPtr==1)
////        printf("ListPrev() returned ERROR!\n");
////    else
////        printf("ListPrev() returned %d\n",*dataPtr);
////    listPrint(emptyList1);
//
//
//    dataPtr=ListNext(emptyList1);
//    if(!dataPtr)
//        printf("ListNext() returned NULL!\n");
//    else if((int)dataPtr==1)
//        printf("ListNext() returned ERROR!\n");
//    else
//        printf("ListNext() returned %d\n",*dataPtr);
//    listPrint(emptyList1);
//    dataPtr=ListNext(emptyList1);
//    if(!dataPtr)
//        printf("ListNext() returned NULL!\n");
//    else if((int)dataPtr==1)
//        printf("ListNext() returned ERROR!\n");
//    else
//        printf("ListNext() returned %d\n",*dataPtr);
//    listPrint(emptyList1);
//    // wil go out of bounds in the tail direction after this function call
//    dataPtr=ListNext(emptyList1);
//    if(!dataPtr)
//        printf("ListNext() returned NULL!\n");
//    else if((int)dataPtr==1)
//        printf("ListNext() returned ERROR!\n");
//    else
//        printf("ListNext() returned %d\n",*dataPtr);
//    listPrint(emptyList1);
//    dataPtr=ListNext(emptyList1);
//    if(!dataPtr)
//        printf("ListNext() returned NULL!\n");
//    else if((int)dataPtr==1)
//        printf("ListNext() returned ERROR!\n");
//    else
//        printf("ListNext() returned %d\n",*dataPtr);
//    listPrint(emptyList1);
//    // bring it back to tail
//    dataPtr=ListPrev(emptyList1);
//    if(!dataPtr)
//        printf("ListPrev() returned NULL!\n");
//    else if((int)dataPtr==1)
//        printf("ListPrev() returned ERROR!\n");
//    else
//        printf("ListPrev() returned %d\n",*dataPtr);
//    listPrint(emptyList1);
//    dataPtr=ListPrev(emptyList1);
//    if(!dataPtr)
//        printf("ListPrev() returned NULL!\n");
//    else if((int)dataPtr==1)
//        printf("ListPrev() returned ERROR!\n");
//    else
//        printf("ListPrev() returned %d\n",*dataPtr);
//    listPrint(emptyList1);
//
//    puts("\n-----------------------------------------------------\n");
//    //-----------------------------------------------------------------------------------------------------------------
//    // ListAdd(list *aList, void *anItem) test:
//    puts("ListAdd(list *aList, void *anItem) tests\n\n");
//    // - when list is empty - pass
//    // - when curr!=tail - pass
//    // - when curr==tail - pass
//    // - when curr is invalid & list is not empty - pass
//    // - when list is full - pass
//    // - when nodePool is full - pass
//
//    printf("ListAdd(%d) to emptyList1 returned %d\n",a,ListAdd(emptyList1,&a));
//    listPrint(emptyList1);
//    printf("ListAdd(%d) to emptyList1 returned %d\n",d,ListAdd(emptyList1,&d));
//    listPrint(emptyList1);
//    printf("ListInsert(%d) to emptyList1 returned %d\n",c,ListInsert(emptyList1,&c));
//    listPrint(emptyList1);
//    printf("ListAdd(%d) to emptyList1 returned %d\n",b,ListAdd(emptyList1,&b));
//    listPrint(emptyList1);
////    // test for overflowing nodePool
////    printf("No more empty nodes in nodePool! ListAdd(%d) to emptyList1 returned %d\n",b,ListAdd(emptyList1,&b));
////    listPrint(emptyList1);
////    printNumNodes();
////    printf("No more empty nodes in nodePool! ListInsert(%d) to emptyList1 returned %d\n",b,ListAdd(emptyList1,&b));
////    listPrint(emptyList1);
////    printNumNodes();
//
//    printf("ListAdd(%d) to emptyList2 returned %d\n",b,ListAdd(emptyList2,&b));
//    listPrint(emptyList2);
//
//
//    // scramble list->curr
//    emptyList1->curr= (node *) 312315;
//    printf("ListAdd(%d) returned %d\n",b,ListAdd(emptyList1,&b));
//    listPrint(emptyList1);
//
//    puts("\n-----------------------------------------------------\n");
//
//
//
//
//
//
//    //-----------------------------------------------------------------------------------------------------------------
//    // ListInsert(list *aList, void *anItem) tests:
//    puts("ListInsert(list *aList, void *anItem) tests\n\n");
//    // - when list is empty - pass
//    // - when curr!=head - pass
//    // - when curr==head - pass
//    // - when curr is invalid & list is not empty - pass
//    // - when list is full - pass
//    // - when nodePool is full - should not happen
//
//    printf("ListInsert(%d) returned %d\n",a,ListInsert(emptyList1,&a));
//    listPrint(emptyList1);
//    printf("ListInsert(%d) returned %d\n",d,ListInsert(emptyList1,&d));
//    listPrint(emptyList1);
//    printf("ListAdd(%d) returned %d\n",c,ListAdd(emptyList1,&c));
//    listPrint(emptyList1);
//    printf("ListInsert(%d) returned %d\n",b,ListInsert(emptyList1,&b));
//    listPrint(emptyList1);
//    // scramble list->curr
//    emptyList1->curr= (node *) 312315;
//    printf("ListInsert(%d) returned %d\n",b,ListInsert(emptyList1,&b));
//    listPrint(emptyList1);

//    puts("\n-----------------------------------------------------\n");
//    //-----------------------------------------------------------------------------------------------------------------
//    // ListAppend(list *aList, void *anItem)/ListPrepend(list *aList, void *anItem)/ListRemove(list *aList) tests:
//    puts("ListAppend(list *aList, void *anItem)/ListPrepend(list *aList, void *anItem)/ListRemove(list *aList) tests\n\n");
//    // - when list is empty - pass/pass/pass
//    // - when list has only 1 item - pass/pass/pass
//    // - when nodePool is full - pass/pass
//    // ##for ListRemove(list *aList) ONLY:
//    // ##- when curr==head - pass
//    // ##- when curr==tail - pass
//    // ##- when curr== out of bounds in head/tail/NULL - //
//    // ##- when removal does not require gap filling -pass
//    // ##- when removal requires gap filling, and the swapping does/does not belong to the current list - pass/pass
//
//    // list empty, curr @ NULL
//    printf("list empty, curr @ NULL ListRemove returned: %d\n", ListRemove(emptyList1)?*(int*) ListRemove(emptyList1):0);
//    listPrint(emptyList1);
//    printf("list empty, ListAppend(%d) returned: %d\n", a,ListAppend(emptyList1,&a));
//    listPrint(emptyList1);
//    // list has single node, current @ said node
//    printf("list has single node, current @ said node ListRemove returned: %d\n", *(int*) ListRemove(emptyList1));
//    listPrint(emptyList1);
//    printf("list empty, ListPrepend(%d) returned: %d\n", b,ListPrepend(emptyList1,&b));
//    listPrint(emptyList1);
//    printf("list not empty, ListAppend(%d) returned: %d\n", c,ListAppend(emptyList1,&c));
//    listPrint(emptyList1);
//    printf("list not empty, ListPrepend(%d) returned: %d\n", a,ListPrepend(emptyList1,&a));
//    listPrint(emptyList1);
//    printf("list not empty, ListAppend(%d) returned: %d\n", d,ListAppend(emptyList1,&d));
//    listPrint(emptyList1);
//    // list should be full now
//    printf("list full, ListAppend(%d) returned: %d\n", a,ListAppend(emptyList1,&a));
//    listPrint(emptyList1);
//    printNumNodes();
//    printf("list full, ListPrepend(%d) returned: %d\n", a,ListPrepend(emptyList1,&a));
//    listPrint(emptyList1);
//    printNumNodes();
//    // list full, curr @ tail
//    printf("list full, curr @ tail ListRemove returned: %d\n", *(int*) ListRemove(emptyList1));
//    listPrint(emptyList1);
//    printf("list not empty, ListPrepend(%d) returned: %d\n", a, ListPrepend(emptyList1,&a));
//    listPrint(emptyList1);
//    // list full, curr @ head
//    printf("list full, curr @ head ListRemove returned: %d\n", *(int*) ListRemove(emptyList1));
//    listPrint(emptyList1);
//    printf("list not empty, ListPrepend(%d) returned: %d\n", d, ListPrepend(emptyList1,&d));
//    listPrint(emptyList1);
//    // list full, curr @ second node (regular case)
//    emptyList1->curr=emptyList1->curr->next;
//    printf("list full, curr @ second node (regular case) ListRemove returned: %d\n", *(int*) ListRemove(emptyList1));
//    listPrint(emptyList1);
//    // list not full, curr @ second node (curr turns to tail)
//    emptyList1->curr=emptyList1->curr->next;
//    printf("list not full, curr @ second node (curr turns to tail) ListRemove returned: %d\n", *(int*) ListRemove(emptyList1));
//    listPrint(emptyList1);
//    ListInsert(emptyList2,&a);
//    ListAdd(emptyList2,&b);
//    listPrint(emptyList2);
//    //does not require swapping
//    printf("does not require swapping, ListRemove returned: %d\n", *(int*) ListRemove(emptyList2));
//    listPrint(emptyList2);
//    //swapping an item in another list
//    printf("swapping an item in another list, ListRemove returned: %d\n", *(int*) ListRemove(emptyList1));
//    listPrint(emptyList1);
//    listPrint(emptyList2);  // single item in list rn
//    ListPrev(emptyList2);   // out of bounds in head
//    listPrint(emptyList2);
//    //attempting to remove when curr @ out of bounds in head direction
//    printf("attempting to remove when curr @ out of bounds in head direction, ListRemove returned: %d\n", ListRemove(emptyList2)?*(int*) ListRemove(emptyList2):0);
//    listPrint(emptyList2);
//    ListNext(emptyList2);
//    ListNext(emptyList2);   // out of bounds in head
//    //attempting to remove when curr @ out of bounds in tail direction
//    printf("attempting to remove when curr @ out of bounds in tail direction, ListRemove returned: %d\n", ListRemove(emptyList2)?*(int*) ListRemove(emptyList2):0);
//    listPrint(emptyList2);
//    puts("\n-----------------------------------------------------\n");
//
//
//    //-----------------------------------------------------------------------------------------------------------------
//    // ListConcat(list *list1, list *list2) tests:
//    puts("ListConcat(list *list1, list *list2) tests\n\n");
//    // - when list1 is empty - pass
//    // - when list2 is empty - pass
//    // - when both empty - pass
//    // - when nodePool is full - pass
//    // - when there are other lists and swapping is required/not required - pass
//
//    // list1=list2=empty
//    ListConcat(emptyList1,emptyList2);
//    listPrint(emptyList1);
//    listPrint(emptyList2);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
//    // list1 empty, list2 non-empty
//    emptyList2=ListCreate();
//    ListAdd(emptyList2,&a);
//    listPrint(emptyList1);
//    listPrint(emptyList2);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    ListConcat(emptyList1,emptyList2);
//    listPrint(emptyList1);
//    listPrint(emptyList2);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
//    // list1 non-empty, list2 empty
//    emptyList2=ListCreate();
//    listPrint(emptyList1);
//    listPrint(emptyList2);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    ListConcat(emptyList1,emptyList2);
//    listPrint(emptyList1);
//    listPrint(emptyList2);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
//    //list1=list2=non-empty
//    emptyList2=ListCreate();
//    ListAdd(emptyList2,&b);
//    ListAdd(emptyList2,&c);
//    listPrint(emptyList1);
//    listPrint(emptyList2);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    ListConcat(emptyList1,emptyList2);
//    listPrint(emptyList1);
//    listPrint(emptyList2);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
//    //list1=list2=non-empty, @ the MAXNODECOUNT
//    emptyList2=ListCreate();
//    printf("ListAdd(%d) returned: %d\n", b,ListAppend(emptyList2,&b));
//    printf("ListAdd(%d) returned: %d\n", c,ListAppend(emptyList2,&c));
//    listPrint(emptyList1);
//    listPrint(emptyList2);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    ListConcat(emptyList1,emptyList2);
//    listPrint(emptyList1);
//    listPrint(emptyList2);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
//    //list1=list2=non-empty, other list exist, swapping
//    ListFirst(emptyList1);
//    ListRemove(emptyList1);
//    ListRemove(emptyList1);
//    emptyList2=ListCreate();
//    emptyList3=ListCreate();
//    ListAdd(emptyList2,&b);
//    ListAdd(emptyList3,&d);
//    listPrint(emptyList1);
//    listPrint(emptyList2);
//    listPrint(emptyList3);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    ListConcat(emptyList1,emptyList2);
//    listPrint(emptyList1);
//    listPrint(emptyList2);
//    listPrint(emptyList3);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
////    //list1=list2=non-empty, other list exist, not swapping
////    ListFirst(emptyList1);
////    ListRemove(emptyList1);
////    ListRemove(emptyList1);
////    emptyList3=ListCreate();
////    emptyList2=ListCreate();
////    ListAdd(emptyList2,&b);
////    ListAdd(emptyList3,&d);
////    listPrint(emptyList1);
////    listPrint(emptyList2);
////    listPrint(emptyList3);
////    printNumNodes();
////    printNumLists();
////    printNumSpareLists();
////    ListConcat(emptyList1,emptyList2);
////    listPrint(emptyList1);
////    listPrint(emptyList2);
////    listPrint(emptyList3);
////    printNumNodes();
////    printNumLists();
////    printNumSpareLists();
//
//    // now try to use this spareList
//    ListFirst(emptyList1);
//    ListRemove(emptyList1);
//    listPrint(emptyList1);
//    ListRemove(emptyList1);
//    listPrint(emptyList1);
//    ListRemove(emptyList1);
//    listPrint(emptyList1);
//    emptyList4=ListCreate();
//    emptyList2=ListCreate();
//    ListAdd(emptyList4,&a);
//    ListAdd(emptyList2,&d);
//    listPrint(emptyList1);
//    listPrint(emptyList2);
//    listPrint(emptyList3);
//    listPrint(emptyList4);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    ListConcat(emptyList1,emptyList2);
//    listPrint(emptyList1);
//    listPrint(emptyList2);
//    listPrint(emptyList3);
//    listPrint(emptyList4);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
//    puts("\n-----------------------------------------------------\n");
//
//    //-----------------------------------------------------------------------------------------------------------------
//    // ListFree(list *aList, void (*itemFree)()) tests:
//    puts("ListFree(list *aList, void (*itemFree)()) tests\n\n");
//    // For list is static/non-static
//    // - when list is empty -
//    // - when list has only one item -
//    // - when list have multiple item -
//    int *dynamicIntData=malloc(sizeof(int));
//    *dynamicIntData=2;
//    int *dynamicIntData2=malloc(sizeof(int));
//    *dynamicIntData2=4;
//
//    // free empty static list
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    ListFree(emptyList1,delStatic);
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
//    // free empty dynamic list
//    emptyList1=ListCreate();
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    ListFree(emptyList1,delDynamic);
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
//    // free 1 node static list
//    emptyList1=ListCreate();
//    ListAdd(emptyList1,&b);
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    ListFree(emptyList1,delStatic);
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
//    // free 1 node dynamic list
//    emptyList1=ListCreate();
//    ListAdd(emptyList1,dynamicIntData);
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    ListFree(emptyList1,delDynamic);
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
//    // free multiple node static list
//    emptyList1=ListCreate();
//    ListAdd(emptyList1,&b);
//    ListAdd(emptyList1,&c);
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    ListFree(emptyList1,delStatic);
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
//    // free multiple node dynamic list
//    // recreate the dynamic variable that was deleted
//    dynamicIntData=malloc(sizeof(int));
//    *dynamicIntData=2;
//    emptyList1=ListCreate();
//    ListAdd(emptyList1,dynamicIntData);
//    ListAdd(emptyList1,dynamicIntData2);
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    ListFree(emptyList1,delDynamic);
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
//    puts("\n-----------------------------------------------------\n");
//
//
//    //-----------------------------------------------------------------------------------------------------------------
//    // ListTrim(list *aList) tests:
//    puts("ListTrim(list *aList) tests\n\n");
//    // - when list is empty -
//    // - when list has only one item -
//    // - when list have multiple item -
//
//        // empty list
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    ListTrim(emptyList1);
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
//    // single node list
//    ListAdd(emptyList1,&b);
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    ListTrim(emptyList1);
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
//    // multiple node list
//    // single node list
//    ListAdd(emptyList1,&b);
//    ListAdd(emptyList1,&c);
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    ListTrim(emptyList1);
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
//    puts("\n-----------------------------------------------------\n");
//
//
//    //-----------------------------------------------------------------------------------------------------------------
//    // ListSearch(list *aList, void *comparator, void *comparisonArg) tests:
//    puts("ListSearch(list *aList, void *comparator, void *comparisonArg) tests\n\n");
//    // - when list is empty - pass
//    // - when list has only one item and is/is not what we are looking for - pass/pass
//    // - when list have multiple item and there is/is not what we are looking for - pass/pass
//
//    int z=5;
//    int *listSearchResult;
//    // list is empty
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    listSearchResult=ListSearch(emptyList1,compareInts,&z);
//    if(listSearchResult)
//        printf("ListSearch(emptyList1,compareInts,5) returned: %d\n", *(int *)listSearchResult);
//    else
//        printf("ListSearch(emptyList1,compareInts,5) returned: NULL\n");
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//
////    // list has one item and is not what we are looking for
////    ListAdd(emptyList1,&b);
////    listPrint(emptyList1);
////    printNumNodes();
////    printNumLists();
////    printNumSpareLists();
////    listSearchResult=ListSearch(emptyList1,compareInts,&z);
////    if(listSearchResult)
////        printf("ListSearch(emptyList1,compareInts,5) returned: %d\n", *(int *)listSearchResult);
////    else
////        printf("ListSearch(emptyList1,compareInts,5) returned: NULL\n");    listPrint(emptyList1);
////    listPrint(emptyList1);
////    printNumNodes();
////    printNumLists();
////    printNumSpareLists();
////
////    // list has one item and is what we are looking for
////    ListAdd(emptyList1,&a);
////    listPrint(emptyList1);
////    printNumNodes();
////    printNumLists();
////    printNumSpareLists();
////    listSearchResult=ListSearch(emptyList1,compareInts,&z);
////    if(listSearchResult)
////        printf("ListSearch(emptyList1,compareInts,5) returned: %d\n", *(int *)listSearchResult);
////    else
////        printf("ListSearch(emptyList1,compareInts,5) returned: NULL\n");//    listPrint(emptyList1);
////    listPrint(emptyList1);
////    printNumNodes();
////    printNumLists();
////    printNumSpareLists();
////
////    // list has more than one item and there is not what we are looking for
////    ListAdd(emptyList1,&b);
////    ListAdd(emptyList1,&c);
////    ListAdd(emptyList1,&d);
////    listPrint(emptyList1);
////    printNumNodes();
////    printNumLists();
////    printNumSpareLists();
////    listSearchResult=ListSearch(emptyList1,compareInts,&z);
////    if(listSearchResult)
////        printf("ListSearch(emptyList1,compareInts,5) returned: %d\n", *(int *)listSearchResult);
////    else
////        printf("ListSearch(emptyList1,compareInts,5) returned: NULL\n");
////    listPrint(emptyList1);
////    printNumNodes();
////    printNumLists();
////    printNumSpareLists();
////
//    // list has more than one item and there is what we are looking for
//    ListAdd(emptyList1,&a);
//    ListAdd(emptyList1,&c);
//    ListAdd(emptyList1,&d);
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//    listSearchResult=ListSearch(emptyList1,compareInts,&z);
//    if(listSearchResult)
//        printf("ListSearch(emptyList1,compareInts,5) returned: %d\n", *(int *)listSearchResult);
//    else
//        printf("ListSearch(emptyList1,compareInts,5) returned: NULL\n");
//    listPrint(emptyList1);
//    printNumNodes();
//    printNumLists();
//    printNumSpareLists();
//




    puts("\n-----------------------------------------------------\n");
    return 0;



}


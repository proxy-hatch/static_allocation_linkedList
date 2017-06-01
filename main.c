
#include <stdio.h>
#include "LIST.h"

/*
 * test performed:
 * - Empty list - pass
 * - one node
 * - more than one node
 * - more than
 */
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
    list *emptyList3=ListCreate();
    list *emptyList4=ListCreate();
    list *emptyList5=ListCreate();
    listPrint(emptyList1);
    listPrint(emptyList2);
    listPrint(emptyList3);
    listPrint(emptyList4);
    listPrint(emptyList5);
    puts("\n-----------------------------------------------------\n");
//    //-----------------------------------------------------------------------------------------------------------------
//    // ListNext(list *aList)/ListPrev(list *aList) tests
//    puts("ListNext(list *aList)/ListPrev(list *aList) tests\n\n");
//    // empty list - pass/pass
//    // non-empty - pass/pass
//    // at head - pass/pass
//    // at tail - pass/pass
//    // out of bounds at head direction - pass/pass
//    // out of bounds at tail direction - pass/pass
//    dataPtr=ListNext(emptyList1);
//    if(!dataPtr)
//        printf("ListNext() returned NULL!\n");
//    else if((int)dataPtr==1)
//        printf("ListNext() returned ERROR!\n");
//    else
//        printf("ListNext() returned %d\n",*dataPtr);
//        dataPtr=ListPrev(emptyList1);
//    listPrint(emptyList1);
//    if(!dataPtr)
//        printf("ListPrev() returned NULL!\n");
//    else if((int)dataPtr==1)
//        printf("ListPrev() returned ERROR!\n");
//    else
//        printf("ListPrev() returned %d\n",*dataPtr);
//    listPrint(emptyList1);
//
//    ListInsert(emptyList1,&c);
//    ListInsert(emptyList1,&b);
//    ListInsert(emptyList1,&a);
//    listPrint(emptyList1);
//
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
//    // - when nodePool is full - should not happen
//
//    printf("ListAdd(%d) to emptyList1 returned %d\n",a,ListAdd(emptyList1,&a));
//    listPrint(emptyList1);
//    printf("ListAdd(%d) to emptyList1 returned %d\n",d,ListAdd(emptyList1,&d));
//    listPrint(emptyList1);
//    printf("ListInsert(%d) to emptyList1 returned %d\n",c,ListInsert(emptyList1,&c));
//    listPrint(emptyList1);
//    printf("ListAdd(%d) to emptyList1 returned %d\n",b,ListAdd(emptyList1,&b));
//    listPrint(emptyList1);
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
//    //-----------------------------------------------------------------------------------------------------------------
    // ListInsert(list *aList, void *anItem) tests:
//    puts("ListInsert(list *aList, void *anItem) tests\n\n");
    // - when list is empty - pass
    // - when curr!=head - pass
    // - when curr==head - pass
    // - when curr is invalid & list is not empty - pass
    // - when list is full - pass
    // - when nodePool is full - should not happen
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
//    // - when list is full - pass/pass/pass
//    // - when nodePool is full - should not happen
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
//    printf("list full, ListAppend(%d) returned: %d\n", a,ListPrepend(emptyList1,&a));
//    listPrint(emptyList1);
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





    puts("\n-----------------------------------------------------\n");
    return 0;



}



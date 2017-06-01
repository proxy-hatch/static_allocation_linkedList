#define DEBUG

#ifdef DEBUG
#include <stdio.h>
#endif  //DEBUG

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
    //-----------------------------------------------------------------------------------------------------------------
    // ListNext(list *aList) tests
    puts("ListNext(list *aList) tests\n\n");
    // empty list - pass
    // non-empty
    // at head
    // at tail
    dataPtr=ListNext(emptyList1);
    if(!dataPtr)
        printf("ListNext() returned NULL!\n");
    else if((int)dataPtr==1)
        printf("ListNext() returned ERROR!\n");
    else
        printf("ListNext() returned %d\n",*dataPtr);
    ListInsert(emptyList1,&c);
    ListInsert(emptyList1,&b);
    ListInsert(emptyList1,&a);
    listPrint(emptyList1);

    dataPtr=ListNext(emptyList1);
    if(!dataPtr)
        printf("ListNext() returned NULL!\n");
    else if((int)dataPtr==1)
        printf("ListNext() returned ERROR!\n");
    else
        printf("ListNext() returned %d\n",*dataPtr);
    listPrint(emptyList1);
    dataPtr=ListNext(emptyList1);
    if(!dataPtr)
        printf("ListNext() returned NULL!\n");
    else if((int)dataPtr==1)
        printf("ListNext() returned ERROR!\n");
    else
        printf("ListNext() returned %d\n",*dataPtr);
    listPrint(emptyList1);
    dataPtr=ListNext(emptyList1);
    if(!dataPtr)
        printf("ListNext() returned NULL!\n");
    else if((int)dataPtr==1)
        printf("ListNext() returned ERROR!\n");
    else
        printf("ListNext() returned %d\n",*dataPtr);
    listPrint(emptyList1);
    dataPtr=ListNext(emptyList1);
    if(!dataPtr)
        printf("ListNext() returned NULL!\n");
    else if((int)dataPtr==1)
        printf("ListNext() returned ERROR!\n");
    else
        printf("ListNext() returned %d\n",*dataPtr);
    listPrint(emptyList1);





    puts("\n-----------------------------------------------------\n");
    //-----------------------------------------------------------------------------------------------------------------
//    // ListAdd(*list,*data) test:
//    puts("ListAdd(*list,*data) tests\n\n");
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
//
//    puts("\n-----------------------------------------------------\n");
//    //-----------------------------------------------------------------------------------------------------------------
//    // ListInsert(list *aList) tests:
//    puts("ListInsert(list *aList) tests\n\n");
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

    puts("\n-----------------------------------------------------\n");
    return 0;



}



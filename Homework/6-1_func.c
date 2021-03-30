/* probID: W6-DoublyLinkedList */
#include <stdlib.h>
typedef struct nd node;
struct nd
{
    int value;
    node *NEXT, *PREV;
};

node *list_iterate(node *POS, int k){
    int t = k;
    node *ptr = POS;
    if(t>0){
        while(t--){
            if(ptr->NEXT == 0)
                return 0;
            else ptr = ptr->NEXT;
        }
        return ptr;
    }
    else if(t<0){
        while(t!=0){
            t++;
            if(ptr->PREV == 0)
                return 0;
            else ptr = ptr->PREV;
        }
        return ptr;
    }
    else
        return ptr;
}
node *list_search(node *POS, int val){
    node *ptr = POS;
    while( ptr->value != val){
        if (ptr->NEXT == 0)
            return 0;
        else ptr = ptr->NEXT;
    }
    return ptr;
}
node *list_insert_before(node *HEAD, node *POS, int val){
    node *new_node = malloc(sizeof(node));
    new_node ->value = val;

    if(HEAD==0||POS==0){
        new_node->PREV=0;
        return new_node;
    }

    else if( HEAD == POS ){
        new_node->NEXT = POS;
        POS->PREV = new_node;
        new_node->PREV = 0;
        return new_node;
    }
    else{
        (POS->PREV)->NEXT = new_node;
        new_node->PREV = POS->PREV;
        new_node->NEXT = POS;
        POS->PREV = new_node;
        return HEAD;
    }
}
node *list_insert_after(node *HEAD, node *POS, int val){
    node *new_node = malloc(sizeof(node));
    new_node ->value = val;

    if(HEAD==0||POS==0){
        new_node->PREV=0;
        return new_node;
    }

    if(POS->NEXT==0){
        new_node->NEXT = 0;
        new_node->PREV = POS;
        POS->NEXT = new_node;
        return HEAD;
    }

    else{
    new_node->NEXT = (POS->NEXT);
    (POS->NEXT)->PREV = new_node;
    new_node->PREV = POS;
    POS->NEXT = new_node;
    return HEAD;
    }

}
node *list_delete(node *HEAD, node *POS){
    if(HEAD==POS){
        (POS->NEXT)->PREV = 0;
        return POS->NEXT;
    }
    else if(POS->NEXT==0){
        (POS->PREV)->NEXT = 0;
        return HEAD;
    }
    else{
    (POS->PREV)->NEXT = (POS->NEXT);
    (POS->NEXT)->PREV = (POS->PREV);
    return HEAD;
    }
}

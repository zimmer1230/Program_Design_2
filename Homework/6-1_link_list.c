#include<stdio.h>
#include<stdlib.h>

typedef struct nd node;
struct nd
{
    int value;
    node *NEXT, *PREV;
};

node *list_iterate(node *POS, int k);
node *list_search(node *POS, int val);
node *list_insert_before(node *HEAD, node *POS, int val);
node *list_insert_after(node *HEAD, node *POS, int val);
node *list_delete(node *HEAD, node *POS);

void print_list(node *current)
{
    node *fin;
    while(current != NULL)
    {
        printf("%d ", current->value);
        if(current->NEXT == NULL)
            fin = current;
        current = current->NEXT;
    }
    printf("\n");
    while(fin != NULL)
    {
        printf("%d ", fin->value);
        fin = fin->PREV;
    }
    printf("\n");
}

int main()
{
    int n, m;
    scanf("%d", &n);
    node *first, *current, *previous, *pos;
    int num, num_pos;
    first = NULL;

    // create linked list
    for(int i = 0; i < n; i++)
    {
        current = (node*)malloc(sizeof(node));
        scanf("%d", &(current->value));
        if(i == 0)
        {
            first = current;
            current->PREV = NULL;
        }
        else
        {
            previous->NEXT = current;
            current->PREV = previous;
        }
        current->NEXT = NULL;
        previous = current;
    }

    scanf("%d", &m);
    char com[10];

    for(int i = 0; i < m; i++)
    {
        scanf("%s", com);

        if(com[0] == 'i')
        {
            scanf("%d %s %d", &num, com, &num_pos);
            if(com[0] == 'b')
            {
                pos = list_iterate(first, num_pos);
                first = list_insert_before(first, pos, num);
            }
            if(com[0] == 'a')
            {
                pos = list_iterate(first, num_pos);
                first = list_insert_after(first, pos, num);
            }
            if(com[0] == 'f')
            {
                pos = list_iterate(first, num_pos);
                current = list_iterate(pos, num);
                if(current != NULL)
                    printf("iterate : %d\n", current->value);
                else
                    printf("iterate : NO\n");
            }
        }
        if(com[0] == 's')
        {
            scanf("%d %s %d", &num, com, &num_pos);
            pos = list_iterate(first, num_pos);
            current = list_search(pos, num);
            if(current != NULL && current->value == num)
                printf("search : YES\n");
            else
                printf("search : NO\n");
        }
        if(com[0] == 'd')
        {
            scanf("%d", &num_pos);
            pos = list_iterate(first, num_pos);
            first = list_delete(first, pos);
        }
        if(com[0] == 'p')
            print_list(first);
    }

    return 0;
}

/* probID: W6-DoublyLinkedList */


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

    if( HEAD == POS ){
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

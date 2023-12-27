#include "node.h"

/**
 * main - Entry point
 * 
 * Return Always EXIT_SUCCESS
*/

int main(void)
{
    Node *head = NULL;
    int (*check)(int x, int y);
    check = compare;

    append_node(&head, 20);
    append_node(&head, 10);
    append_node(&head, 30);
    append_node(&head, 40);
    append_node(&head, 12);
    append_node(&head, 33);

    
    sort(&head, check);
    print_list(head);

    return (EXIT_SUCCESS);

}
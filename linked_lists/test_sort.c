#include "node.h"

/**
 * main - Entry point
 * 
 * Return Always EXIT_SUCCESS
*/

int main(void)
{
    Node *head = NULL, *head1 = NULL, *merged = NULL;
    int (*check)(int x, int y);
    check = compare;

    /*The first list*/
    append_node(&head1, 10);
    append_node(&head, 32);
    append_node(&head1, 50);
    append_node(&head1, 20);
    append_node(&head1, -1);
    append_node(&head1, 60);

    /*The second list*/
    append_node(&head, 20);
    append_node(&head, 10);
    append_node(&head, -1);
    append_node(&head, 30);
    append_node(&head, 40);
    append_node(&head, -32);
    append_node(&head, 12);
    append_node(&head, 0);
    append_node(&head, 12);
    append_node(&head, 33);

    
    sort(&head, check);
    sort(&head1, check);
    merged = merge(head, head1);
    print_list(merged);

    return (EXIT_SUCCESS);

}
#include "node.h"

/**
 * sort - Function to sort a linked list
 * @head: pointer to the linked list
 * @compare: node data to compare with. 
 * 
 * Description: The sort function acts as a function that sorts a singly
 * linked list using the bubble sort algorithm.
 * 
 * Return: pointer to the head of the sorted linked list else returns
 * NULL if something happens
*/
Node *sort(Node **head, int (*compare)(int x, int y))
{
    Node *temp = NULL;
    int swapped = 1;

    if (*head == NULL)
        return NULL;

    while (swapped)
    {
        swapped = 0;
        temp = *head;

        while (temp->next != NULL)
        {
            if (compare(temp->data, temp->next->data)  == 0)
            {
                swap(temp, temp->next);

                /*set swapped to 1 (True) if at least one swap happend during*/
                /*entire iteration*/
                swapped = 1;
            }
            temp = temp->next;
        }
    }
    return (*head);

}

/**
 * swap - swaps data of nodes
 * @node1: The first node of the list
 * @node2: The second node of the list
 * 
 * Return: Nothing
*/
void swap(Node *node1, Node *node2)
{
    int temp_data = node1->data;
    node1->data = node2->data;
    node2->data = temp_data;
    
}
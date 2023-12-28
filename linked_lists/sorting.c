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

/**
 * merge - Function that merges two sorted list
 * @list_1 - The first list
 * @list2 - The second list
 *
 * Description: This function merges two sorted linked list @list_1 and
 * @list2. While merging, it also considers the order at which elements occur.
 * That is elements that are lesser, comes first before greater numbers.
 * Return: Pointer to the merged list
 */
Node *merge(Node *list_1, Node *list2)
{
	Node *dummy, *current = NULL;
	int (*check)(int a, int b);

	dummy = create_node();
	current = dummy;

	if (list_1 == NULL)
		return (list2);

	if (list2 == NULL)
		return (list_1);

	if ((list2 == NULL) && (list_1 = NULL))
		return (NULL); /*Both list are empty*/

	while ((list_1 != NULL) && (list2 != NULL))
	{
		if (list_1->data <= list2->data)
		{
			current->next = create_node();
			current->next->data = list_1->data;
			list_1 = list_1->next;
			current = current->next;

		}
		else
		{
			current->next = create_node();
			current->next->data = list2->data;
			list2 = list2->next;
			current = current->next;

		}
		/*Add any remaining elements of list_1 to the dummy list*/
		while (list_1 != NULL)
		{
			current->next = create_node();
			current->next->data = list_1->data;
			list_1 = list_1->next;
			current = current->next;
		}
		/*Add any remaining element of the list2 to the dummy list*/
		while (list2 != NULL)
		{
			current->next = create_node();
			current->next->data = list2->data;
			list2 = list2->next;
			current = current->next;
		}
		
	}
	check = compare;
	sort(&dummy->next, check);

	return (dummy->next);
}

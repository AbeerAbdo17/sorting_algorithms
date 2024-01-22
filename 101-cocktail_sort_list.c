#include "sort.h"
/**
 * swap_nodes - Swap a node in doubly-linked list
 * @head:input
 * @xtail: input
 * @xcurrent:input
 * @xdirection: input
 */
void swap_nodes(listint_t **head, listint_t **xtail, listint_t **xcurrent, int xdirection)
{
	listint_t *xtmp;

	if (xdirection == 1)
	{  /*Swap ahead8*/
		xtmp = (*xcurrent)->next;

		if ((*xcurrent)->prev != NULL)
			(*xcurrent)->prev->next = xtmp;
		else
			*head = xtmp;

		xtmp->prev = (*xcurrent)->prev;
		(*xcurrent)->next = xtmp->next;

		if (xtmp->next != NULL)
			xtmp->next->prev = *xcurrent;
		else
			*xtail = *xcurrent;

		(*xcurrent)->prev = xtmp;
		xtmp->next = *xcurrent;
		*xcurrent = xtmp;
	}
	else if (xdirection == -1)
	{/* Swap behind*/
		xtmp = (*xcurrent)->prev;

		if ((*xcurrent)->next != NULL)
			(*xcurrent)->next->prev = xtmp;
		else
			*xtail = xtmp;

		xtmp->next = (*xcurrent)->next;
		(*xcurrent)->prev = xtmp->prev;

		if (xtmp->prev != NULL)
			xtmp->prev->next = *xcurrent;
		else
			*head = *xcurrent;

		(*xcurrent)->next = xtmp;
		xtmp->prev = *xcurrent;
		*xcurrent = xtmp;
	}
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers using the Cocktail shaker sort.
 * @head: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **head)
{
	listint_t *xtail, *xcurrent;
	bool check = false;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	for (xtail = *head; xtail->next != NULL;)
		xtail = xtail->next;

	while (check == false)
	{
		check = true;
		for (xcurrent = *head; xcurrent != xtail; xcurrent = xcurrent->next)
		{
			if (xcurrent->n > xcurrent->next->n)
			{
				swap_nodes(head, &xtail, &xcurrent, 1);
				print_list((const listint_t *)*head);
				check = false;
			}
		}
		for (xcurrent = xcurrent->prev; xcurrent != *head; xcurrent = xcurrent->prev)
		{
			if (xcurrent->n < xcurrent->prev->n)
			{
				swap_nodes(head, &xtail, &xcurrent, -1);
				print_list((const listint_t *)*head);
				check = false;
			}
		}
	}
}


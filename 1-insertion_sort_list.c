#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion sort
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	if (list != NULL && *list != NULL && (*list)->next != NULL)
	{
		listint_t *xcurr, *xtmp, *temp;

		xcurr = (*list)->next;

		while (xcurr != NULL)
		{
			xtmp = xcurr;
			xcurr = xcurr->next;

			while (xtmp->prev != NULL && xtmp->n < xtmp->prev->n)
			{
				temp = xtmp->prev;

				if (xtmp->next != NULL)
					xtmp->next->prev = temp;

				temp->next = xtmp->next;
				xtmp->prev = temp->prev;
				temp->prev = xtmp;

				if (xtmp->prev != NULL)
					xtmp->prev->next = xtmp;
				else
					*list = xtmp;

				xtmp->next = temp;

				print_list((const listint_t *)*list);
			}
		}
	}
}

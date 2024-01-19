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
		listint_t *xcurr, *xtmp, *temper;

		xcurr = (*list)->next;

		while (xcurr != NULL)
		{
			xtmp = xcurr;
			xcurr = xcurr->next;

			while (xtmp->prev != NULL && xtmp->n < xtmp->prev->n)
			{
				temper = xtmp->prev;

				if (xtmp->next != NULL)
					xtmp->next->prev = temper;

				temper->next = xtmp->next;
				xtmp->prev = temper->prev;
				temper->prev = xtmp;

				if (xtmp->prev != NULL)
					xtmp->prev->next = xtmp;
				else
					*list = xtmp;

				xtmp->next = temper;

				print_list((const listint_t *)*list);
			}
		}
	}
}

#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion sort
 * @list: Pointer
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *xcurr, *xtmp;

	if (list || *list || (*list)->next)
	{

		xcurr = (*list)->next;

		while (xcurr != NULL)
		{
			xtmp = xcurr;

			while (xtmp->prev != NULL && xtmp->n < xtmp->prev->n)
			{
				if (xtmp->next != NULL)
					xtmp->next->prev = xtmp->prev;
				xtmp->prev->next = xtmp->next;
				xtmp->next = xtmp->prev;
				xtmp->prev = xtmp->prev->prev;
				xtmp->next->prev = xtmp;

				if (xtmp->prev != NULL)
					xtmp->prev->next = xtmp;
				else
					*list = xtmp;

				print_list(*list);
			}

			xcurr = xcurr->next;
		}
	}
}


#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion sort
 * @list: Pointer
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *xleadv, *xfllv, *xnwv, *xtmpv;

	if (!list || !(*list) || !((*list)->next))
	{
		xfllv = (*list);
		xleadv = (*list)->next;
		while (xleadv)
		{
			xnwv = xleadv->next;
			while (xfllv && xleadv->n < xfllv->n)
			{
				if (xfllv->prev)
					xfllv->prev->next = xleadv;
				else
					*list = xleadv;
				if (xleadv->next)
					xleadv->next->prev = xfllv;
				xtmpv = xleadv->next;
				xleadv->next = xfllv;
				xleadv->prev = xfllv->prev;
				xfllv->next = xtmpv;
				xfllv->prev = xleadv;
				print_list(*list);
				xfllv = xleadv->prev;
			}
			xleadv = xnwv;
			if (xleadv)
				xfllv = xleadv->prev;
		}
	}
}

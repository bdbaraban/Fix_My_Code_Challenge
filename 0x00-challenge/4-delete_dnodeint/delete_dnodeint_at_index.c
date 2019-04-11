#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		if (*head != NULL)
			(*head)->prev = NULL;
		return (1);
	}

	saved_head = *head;
	for (p = 0; p < (index - 1); p++)
	{
		if ((*head)->next == NULL)
		{
			*head = saved_head;
			return (-1);
		}
		*head = (*head)->next;
	}

	tmp = (*head)->next;
	(*head)->prev->next = tmp;
	if (tmp != NULL)
		tmp->prev = (*head)->prev;
	free(*head);
	*head = saved_head;
	return (1);
}

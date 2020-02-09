#include "lists.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * create_node - creates a new node of type listint_t
 * @number: value of the new node
 *
 * Return: the address of the new node
 */
listint_t *create_node(int number)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	new->n = number;
	new->next = NULL;

	return (new);
}


/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: double pointer to the first node of the linked list
 * @number: integer to insert
 *
 * Return: the address of the new node, or NULL if failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *cur;
	listint_t *p;
	listint_t *new;
	int i = 0;

	cur = *head;
	p = *head;
	new = create_node(number);

	if (!head || !new)
		return (NULL);
	if (!*head)
	{
		*head = new;
		return (new);
	}
	while (cur)
	{
		if (cur->next == NULL)
		{
			cur->next = new;
			new->next = NULL;
		}
		if (cur->n > new->n)
		{
			if (i == 0)
			{
				new->next = cur->next;
				*head = new;
				break;
			}
			new->next = cur;
			p->next = new;
			break;
		}
		p = cur;
		cur = cur->next;
		i++;
	}
	return (new);
}

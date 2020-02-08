#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/*
 * insert_node - Inserts a number into a sorted singly linked list
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

	new = malloc(sizeof(listint_t));
	cur = *head;
	p = *head;
	new->n = number;

	if (!head || !new) {
		return (NULL);
	}

	if (!*head) {
		*head = new;
		return (new);
	}

	while (cur) {
		if (cur->next == NULL) {
			cur->next = new;
			new->next = NULL;
		}
		if (cur->n > new->n) {
			new->next = cur;
			p->next = new;
			return (new);
		}
		p = cur;
		cur = cur->next;
	}
	return (NULL);
}

#include "main.h"

/**
 * get_string_length - Get the length of a string.
 * @str: The input string.
 *
 * This function calculates the length of the input string.
 *
 * Return: The length of the string.
 */

int get_string_length(char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * create_linked_list - Create a linked list from a string.
 * @str: The input string.
 *
 * This function creates a linked list where each node contains a character
 * the input string from.
 *
 * Return: A pointer to the head of the linked list.
 */

Node *create_linked_list(char *str)
{
	int i;
	Node *head = NULL, *tail = NULL;
	int length = get_string_length(str);

	for (i = 0; i < length; i++)
	{
		Node *newNode = (Node *)malloc(sizeof(Node));

		newNode->data = str[i];
		newNode->next = NULL;

		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}

	return (head);
}

/**
 * convert_linked_list_to_array - Convert a linked list to a character array.
 * @head: The head of the linked list.
 * @length: The length of the linked list.
 *
 * This function converts a linked list of characters into a character array.
 *
 * Return: A pointer to the newly allocated character array.
 */

char *convert_linked_list_to_array(Node *head, int length)
{
	char *ptr = (char *)malloc(sizeof(char) * (length + 1));

	Node *current = head;
	int i = 0;

	while (current != NULL)
	{
		ptr[i] = current->data;
		current = current->next;
		i++;
	}

	ptr[i] = '\0';

	return (ptr);
}

/**
 * str_copy - Create a copy of a string.
 * @tx: The input string to be copied.
 *
 * This function creates a copy of the input string using a linked list
 * and then converts it to a character array. It also frees the memory used
 * by the linked list.
 *
 * Return: A pointer to the newly allocated copy of the input string,
 * or NULL if memory allocation fails.
 */

char *str_copy(char *tx)
{
	Node *head = create_linked_list(tx);
	int length = get_string_length(tx);
	char *ptr = convert_linked_list_to_array(head, length);

	Node *current = head;

	while (current != NULL)
	{
		Node *temp = current;

		current = current->next;

		free(temp);
	}

	return (ptr);
}

#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	list_t* tmp =head;
	if(new_element->index < head->index)
	{
		new_element->next = head;
		return new_element;
	}
	while(tmp->next)
	{
	 	if(tmp->next->index > new_element->index)
			{
				new_element->next = tmp->next;
				tmp->next = new_element;
				return head;
			}
		tmp = tmp->next;
	}
	tmp->next = new_element;
	new_element->next = NULL;
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	
	list_t* tmp =head;
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	list_t* new_head = tmp;
	list_t* follow = new_head;
	while(follow != head)
	{
		tmp = head;
		while(tmp->next != follow)
		{
			tmp = tmp->next;
		}
		follow->next = tmp;
		follow = tmp;
	}
	follow->next =NULL;			
	return new_head;
}


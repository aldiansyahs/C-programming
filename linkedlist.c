#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>


struct Link* listInsertionSort(struct Link* head) {

  /*
   * This function should perform an insertion sort on the list whose head is
   * provided as the function's argument, so that the values in the list are
   * sorted in ascending order, starting at the head.
   *
   * The sort should be done without allocating any new Link structs or any
   * other auxiliary data structures.
   *
   * Return a pointer to the new head of the list.
   */
	
	//initialize current pointer
   struct Link* current=head;
   	//initialize insertionPoint the same with current pointer
   struct Link* insertionPoint=head;
   	//initialize another pointer to compare the value
   struct Link* point1;
   	//initialize another pointer to compare the value
   struct Link* point2;
   
   while (current->next != NULL){
   
   		point1=insertionPoint;
   			while (current->next != NULL && point1 != current->next && point1->value < current->next->value)
   				point1=point1->next;
   				
   				
   				if (current->next != point1){
   					point2=current->next;
   					current->next=current->next->next;
   					
   					if (insertionPoint == point2){
   						point2->next=insertionPoint;
   						return point2;
   					}
   					
   					point1=insertionPoint;
   					
   					while(point1->next != point1){
   						point1=point1->next;
   					}
   					
   					point2->next=point1->next;
   					point1->next=point2;
   					
   					printf("cur value: %d\n", current->value);
   					printf("i* value %d\n", insertionPoint->value);
   					printLL(head, "~~~~~~~");
   					
   					return insertionPoint;	

   				
   				} else {
   				
   				current=current->next;
   				
   				}
   				
   			return insertionPoint;
   }
   
   		
  	return head;
   
}


struct Link* reverseList(struct Link* head) {

  /*
   * This function should iteratively reverse the list whose head is provided
   * as the function's argument.
   *
   * The reversal must be done totally in place, i.e. you may not allocate any
   * new Link structs or any other auxiliary data structures.
   *
   * Return a pointer to the new head of the list.
   */
   
   struct Link* prevLink=NULL;
   struct Link* nextLink=NULL;
   struct Link* current= head;
   
   
   while(current != NULL){
   		nextLink=current->next;
   		current->next=prevLink;
   		prevLink=current;
   		current=nextLink;
   }
   
   head=prevLink;
   return head;

}


struct Link* reverseListRecursive(struct Link* head){

  /*
   * Write this function for extra credit.  It should do the exact same thing
   * as reverseList() above, except it should do it recursively instead of
   * iteratively (i.e. no loops allowed).
   *
   * Again, you may not allocate any new Link structs or any other auxiliary
   * data structures.  You may, however, define an auxiliary function to help
   * you do the recursion.
   *
   * Return a pointer to the new head of the list.
   */
   
   if (head == NULL)
   	return NULL;
   	
   	if (head->next == NULL)
   		return head;
   		
   	struct Link* last=reverseListRecursive(head->next);
   	
   	head->next->next=head;
   	head->next=NULL;
   	
   	return last;	
   
   	
  return head;

}

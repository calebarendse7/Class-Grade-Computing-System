/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.

AUTHOR: Caleb Arendse
*/
#include "lab4.h"

/*inserts new student node into list in increasing student id order*/
void insertNode(Node **list_head, Node *newNode){
	Node *currentNode = *list_head;
	Node *priorNode = NULL;

	/*check if list empty*/
	if(list_head == NULL){
		*list_head = newNode;
	}else{
		/*go though each node to find correct postion for new node based student ID*/
		while(currentNode != NULL){

			if((newNode -> Student.student_ID) >= (currentNode -> Student.student_ID)){
				priorNode = currentNode;
				currentNode = currentNode -> next;
			}else{
				break;
			}
		
		}

		/*update the list accordingly based on correct postion found*/
		if(priorNode == NULL){
			newNode -> next = *list_head;
			*list_head = newNode;
		}else{
			newNode -> next = currentNode;
			priorNode -> next = newNode;

		}
		
	}

}

/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.

AUTHOR: Caleb Arendse
*/
#include "lab4.h"

/*removes student from list*/
void deleteStudent(Node **list_head){
	int id;
	
	Node *currentNode = *list_head;
	Node *priorNode = NULL;

	printf("Enter student ID: ");
	scanf("%i", &id);

	/*check if list has nodes*/
	if(list_head == NULL){
		printf("ERROR: List Empty");
	}else{
		/*search for student based on ID*/
		while(currentNode != NULL){

			if((currentNode -> Student.student_ID) != id){
				priorNode = currentNode;
				currentNode = currentNode -> next;
			}else{
				break;
			}
		
		}
		
		/*ensure node to delete is in list*/
		if(currentNode != NULL){

			/*delete node based on postion in list*/
			if(priorNode == NULL){
				free(currentNode);
			}else{
				/*ensure list does not lose any nodes*/
				if((currentNode -> next) != NULL){
					priorNode -> next = currentNode -> next;
					free(currentNode);
				}else{	
					priorNode -> next = NULL;
					free(currentNode);
				}

			}
	}else{
		printf("ERROR: Student Not Found.");
	}
		
	}


}

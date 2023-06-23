/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.

AUTHOR: Caleb Arendse
*/
#include "lab4.h"

/*find and returns student node for given last name*/
void printLastName(Node **list_head, char **categories){
	Node *student = *list_head;
	char *lastName;
	
	/*allocate memory for storeing last name*/
	lastName = malloc(40 * sizeof(char));

	printf("Enter student last name: ");
	scanf("%s", lastName);

	/*search for student node based on last name*/
	while(student != NULL){
	
		if((strstr(student -> Student.student_name, lastName)) != NULL){
			
			break;
			
		}
		
		student = student -> next;

	}


	if(lastName != NULL) free(lastName);

	printStudent(student, categories);
}

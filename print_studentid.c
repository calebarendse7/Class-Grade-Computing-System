/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.

AUTHOR: Caleb Arendse
*/
#include "lab4.h"

/*gets the student node based on student ID #*/
void printStudentID(Node **list_head, char **categories){
	int id = 0;
	Node *student = *list_head;

	printf("Enter student ID #: ");
	scanf("%i", &id);
	
	/*loop to find student based on ID given*/
	while(student != NULL){
		if((student -> Student.student_ID) == id){				
			break;
		}
		student = student -> next;
	}

	printStudent(student, categories);
}

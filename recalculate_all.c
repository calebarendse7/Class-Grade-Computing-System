/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.

AUTHOR: Caleb Arendse
*/
#include "lab4.h"

/*recalculates grades for all stored student data*/
void recalculateAll(Node **list_head, char **categories){
	Node *n = *list_head;
	
	/*recalculate each student grade*/
	while(n != NULL){
		printNewGrades(n, categories);
		n = n -> next;
	}
}

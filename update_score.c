/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.

AUTHOR: Caleb Arendse
*/
#include "lab4.h"

/*updates scores in each category based on user input*/
void updateScore(Node **data, char **categories){
	int category;
	int position;
	int i;
	int id = 0;

	float score;
	float *scorePtr;

	Node *student = *data;
	struct Cat_Grade *cat;

	printf("Enter student ID #: ");
	scanf("%i", &id);

	/*loop to find student based on ID given*/
	while(student != NULL){
		if((student -> Student.student_ID) == id){				
			break;
		}
		student = student -> next;
	}

	if(student != NULL){
	/*save address of first category*/
	cat = &(student -> Student.Cat1);
	
	printf("Which category would you like to update? \n");

	/*print out each category name*/
	for(i = 0; i < 4; i++){
		printf("%i) %s. \n", i + 1, *(categories + i));
	}

	scanf("%i", &category);
	
	
	printf("Which grade in %s would you like to update? (1, 2 or 3) ", *(categories + (category - 1)));
	scanf("%i", &position);
	
	printf("Enter New Score: ");
	scanf("%f", &score);
	/*get location of score based on user input*/
	scorePtr = &((*(cat + (category - 1))).score1);

	/*update score of student*/
	*(scorePtr + (position - 1)) = score;

	printf("Score updated.\n");
	}else{
		printf("Student Not Found.");
	}
}


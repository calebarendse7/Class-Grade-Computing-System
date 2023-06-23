/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.

AUTHOR: Caleb Arendse
*/
#include "lab4.h"

/*adds new student to list based on user input*/
void addStudent(Node **list_head, char **categories){
	int i, k;

	float *grade;

	Node *newNode;
	struct Cat_Grade *cat;
	
	/*allocate new node*/
	newNode = malloc(sizeof(Node));

	/*check if node created successfully*/
	if(newNode != NULL){
		printf("Enter student name: ");
		scanf(" %[^\n]", newNode -> Student.student_name);

		printf("Enter student ID: ");
		scanf("%i", &(newNode -> Student.student_ID));

		/*get location of first catagory*/
		cat = &(newNode -> Student.Cat1);
	
		/*collect the scores for each category*/
		for(i = 0; i < 4; i++){
			/*get location of first score*/
			grade = &((*cat).score1);
			
			for(k = 0; k < 3; k++){
			
				printf("Enter grade %i for %s: ", k + 1, *(categories + i));
				scanf("%f", grade);
	
				/*go to next score*/
				grade++;
			
			}
		/*go to next category*/
		cat++;
		
		}
			
			calculateGrades(newNode);
			insertNode(list_head, newNode);
			printf("Added student.\n");
	}else{
		printf("ERROR: Allocating Node");

	}
	
}

/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.

AUTHOR: Caleb Arendse
*/
#include "lab4.h"

/*prints out all student data from given student node*/
void printStudent(Node *data, char **categories){
	int i, k;
	struct Cat_Grade *cat;
	float *score;


	/*check if student found*/
	if(data != NULL){
	/*get address of first category and first score*/
	cat = &(data -> Student.Cat1);
	score = &((*cat).score1);
	
	/*print header*/
	printf("\nStudent Name\t   Student ID#\t\t%s\t\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t\t Current\tFinal\n",*categories,*(categories + 1),*(categories + 2), *(categories + 3));
	printf("\t\t\t\t  1       2       3       Cum\t   1       2       3     Cum\t 1       2       3       Cum     1       2       3      Cum\tGrade\tGrade\n");

	/*print student name and ID*/		
	printf("%s\t      ", data -> Student.student_name);
	printf("%i\t ", data -> Student.student_ID);
		
	/*print out each score from each category*/	
	for(i = 0; i < 4; i++){
		for(k = 0; k < 4; k++){
			/*check if score is not -1*/
			if((*score) > 0){
				printf("%.2f\t ", *score);
			}else{
				printf("n/a\t ");
			}
			/*go to next score*/
			score++;
		}
		/*go to next category*/
		cat++;
		/*get score address of next category*/
		score = &((*cat).score1);
	}

	/*print out current grade*/
	printf("%.2f\t ", data -> Student.Current_Grade);
		
	/*print out final grade*/
	if((data -> Student.Final_Grade) > 0){
		printf("%.2f\t \n", data -> Student.Final_Grade);
	}else{
		printf("n/a\t \n");

	}
	}else{
		printf("ERROR: Student Not Found.\n");
	}


}

/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.

AUTHOR: Caleb Arendse
*/
#include "lab4.h"

/*prints out recalculated grades for given student data*/
void printNewGrades(Node *data, char **categories){
	int i;
	float *grade;

	struct Cat_Grade *cat;
	
	/*ensure given student data is valid*/
	if(data != NULL){
		/*call function to recalculate grade*/
		calculateGrades(data);

		/*save address of first category and first grade*/
		cat = &(data -> Student.Cat1);
		grade = &((*cat).Cumulative);
		
		/*print out header*/
		printf("\nStudent Name\t   %s\t\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t\t Current\n",*categories,*(categories + 1),*(categories + 2), *(categories + 3));
		printf("\t\t     Cum\t\t\t\t  Cum\t\t\t\t  Cum\t\t\t\t  Cum\t\t\t\t  Grade\n");

		/*print student name*/
		printf("%s\t     ", data -> Student.student_name);

		/*print out the cumulative score for each category*/
		for(i = 0; i < 4; i++){
				
				/*ensure cumulative grade is not -1*/
				if((*grade) > 0){
					printf("%.2f\t\t\t\t", *grade);
				}else{
					printf("n/a\t\t\t\t ");
				}
			/*go to next category*/
			cat++;
			/*goto next score in category*/
			grade = &((*cat).Cumulative);
		}
		/*print current grade*/
		printf("%.2f\t\t \n", data -> Student.Current_Grade);
	}else{
		printf("ERROR: Student Not Found.");
	}
}






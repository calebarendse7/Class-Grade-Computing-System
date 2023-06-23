/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.

AUTHOR: Caleb Arendse
*/
#include "lab4.h"

/*saves student data to file*/
void saveData(Node *list_head, char **categories, char *outputName){
	int i = 0; 
	int k = 0;

	float *grade;
	struct Cat_Grade *cat;

	Node *n = list_head;
	
	FILE *out = fopen(outputName, "w");
	
	/*print out categories to file*/
	for(i = 0; i < 4; i++){
		fputs(*(categories + i), out);
		fputs(" ", out);
	}
		
	fputs("\n", out);

	/*print out each student data to file*/
	while(n != NULL){
	
	fputs(n -> Student.student_name, out);
	fputs("\n", out);
	
	fprintf(out, "%i", n -> Student.student_ID);
	fputs("\n", out);

	/*get location of first catagory*/
	cat = &(n -> Student.Cat1);
	
		/*print out each score for each category to file*/
		for(i = 0; i < 4; i++){

			/*get location of first score*/
			grade = &((*cat).score1);
			
			for(k = 0; k < 3; k++){
				/*save score*/
				fprintf(out, "%.1f", *grade);
				fputs(" ", out);

				/*go to next score*/
				grade++;
			
			}

		fputs("\n", out);

		/*go to next category*/
		cat++;
		
		}
		n = n -> next;
	}
	printf("Successfully saved data to: %s.\n", outputName);

}

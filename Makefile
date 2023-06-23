all:lab4

lab4: lab4main.o read_data.o insert_node.o calculate_grades.o print_studentid.o print_lastname.o print_student.o print_gradebook.o print_newgrades.o update_score.o add_student.o delete_student.o recalculate_all.o calculate_final.o save_data.o recalculate_one.o
	gcc lab4main.o read_data.o insert_node.o calculate_grades.o print_studentid.o print_lastname.o print_student.o print_gradebook.o print_newgrades.o update_score.o add_student.o delete_student.o  recalculate_all.o calculate_final.o save_data.o recalculate_one.o -o lab4

lab4main.o: lab4main.c lab4.h
	gcc -ansi -pedantic -g -c -o lab4main.o lab4main.c

read_data.o: read_data.c lab4.h
	gcc -ansi -pedantic -c read_data.c -o read_data.o

insert_node.o: insert_node.c lab4.h
	gcc -ansi -pedantic -c insert_node.c -o insert_node.o

calculate_grades.o: calculate_grades.c lab4.h
	gcc -ansi -pedantic -c calculate_grades.c -o calculate_grades.o

print_studentid.o: print_studentid.c lab4.h
	gcc -ansi -pedantic -c print_studentid.c -o print_studentid.o

print_lastname.o: print_lastname.c lab4.h
	gcc -ansi -pedantic -c print_lastname.c -o print_lastname.o

print_student.o: print_student.c lab4.h
	gcc -ansi -pedantic -c print_student.c -o print_student.o

print_gradebook.o: print_gradebook.c lab4.h
	gcc -ansi -pedantic -c print_gradebook.c -o print_gradebook.o

print_newgrades.o: print_newgrades.c lab4.h
	gcc -ansi -pedantic -c print_newgrades.c -o print_newgrades.o

update_score.o: update_score.c lab4.h
	gcc -ansi -pedantic -c update_score.c -o update_score.o

add_student.o: add_student.c lab4.h
	gcc -ansi -pedantic -c add_student.c -o add_student.o

delete_student.o: delete_student.c lab4.h
	gcc -ansi -pedantic -c delete_student.c -o delete_student.o

recalculate_all.o: recalculate_all.c lab4.h
	gcc -ansi -pedantic -c recalculate_all.c -o recalculate_all.o

calculate_final.o: calculate_final.c lab4.h
	gcc -ansi -pedantic -c calculate_final.c -o calculate_final.o

save_data.o: save_data.c lab4.h
	gcc -ansi -pedantic -c save_data.c -o save_data.o

recalculate_one.o: recalculate_one.c lab4.h
	gcc -ansi -pedantic -c recalculate_one.c -o recalculate_one.o
clean:
	rm -rf *.o lab4

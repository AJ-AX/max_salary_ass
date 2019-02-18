CC = gcc
CFLAGS = -Wall -std=gnu99

salary: is_better.o max_salary_greedy.o max_salary_naive.o test.o
	$(CC) $(CFLAGS) is_better.o max_salary_greedy.o max_salary_naive.o test.o -o salary
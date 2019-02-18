CC = gcc
CFLAGS = -Wall -std=gnu99

msg: is_better.o max_salary_greedy.o
	$(CC) $(CFLAGS) is_better.o max_salary_greedy.o -o msg
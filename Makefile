default:
	gcc test.c
compile:
	gcc test.c

run: compile
	./a.out

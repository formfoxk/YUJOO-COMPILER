all:	build

build:
	flex scanner.l
	gcc -I. lex.yy.c -o scanner -ll

clean:
	rm -f lex.yy.c
	rm -f scanner
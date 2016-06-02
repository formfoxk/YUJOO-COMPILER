# 컴파일러 및 라이브러리 정의
CC = gcc
LIBS = -ll -ly
LEX = flex
YACC = bison
# 기본적으로 빌드를 수행할 목록
all : minic
# debug용 minic 파일 빌드
debug : minic.c minic.tab.c minic_ast.c
	$(CC) -g -o $@ $^ $(LIBS)
# minic 파일 빌드
minic : minic.c minic.tab.c minic_ast.c
	$(CC) -o $@ $^ $(LIBS)
minic.tab.c : minic.y
	$(YACC) -d $^
minic.c : minic.l
	$(LEX) -t $^ > $@
# build 후 생성된 파일들 제거:
clean :
	rm -r minic minic.c minic.tab.c minic.tab.h

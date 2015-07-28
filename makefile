phase3exe: driver.c parser.o lexer.o ast.o symbol_table.o semantic_analyzer.o codeGen.o
	gcc -g -w -o phase3exe driver.c parser.o lexer.o ast.o symbol_table.o semantic_analyzer.o codeGen.o
parser.o: parser.c
	gcc -g -w -c parser.c -lm
lexer.o: lexer.c
	gcc -g -w -c lexer.c -lm
ast.o: ast.c
	gcc -g -w -c ast.c -lm
symbol_table.o: symbol_table.c
	gcc -g -w -c symbol_table.c -lm
semantic_analyzer.o: semantic_analyzer.c
	gcc -g -w -c semantic_analyzer.c -lm	
codeGen.o: codeGen.c
	gcc -g -w -c codeGen.c -lm	
clean:
	rm -f driver.o parser.o lexer.o ast.o symbol_table.o semantic_analyzer.o codeGen.o

run: main
		./main

main:	*.o
		g++ -std=c++98 -o main *.o

*.o:	*.cpp
		g++ -std=c++98 -c -w *.cpp
		
c:
		rm *.o main 

cl:
		rm *.aux *.fdb_latexmk *.fls *.log *.synctex.gz
		rm __latexindent_temp.tex
		tm -R .vscode
		rm -R .history
		

tar:
		tar -cvz *.h *.cpp makefile -f u21434159.tar.gz

v:
		make
		valgrind --tool=memcheck --leak-check=yes ./main
		make c

val:
		valgrind --tool=memcheck --leak-check=yes ./main

g:
		make
		gdb ./main
		make c

tar_unzip:
		tar -xzvf u21434159.tar.gz

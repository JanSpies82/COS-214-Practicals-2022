run: main
		./main

main:	*.o
		g++ -std=c++98 -o main *.o

*.o:	*.cpp
		g++ -std=c++98 -c -w *.cpp

debugcpp: debugo
		g++ -std=c++98 -ggdb3 -o main *.o
	
debugo: *.cpp
		g++ -std=c++98 -ggdb3 -c -w *.cpp

c:
		rm *.o main

tar:
		tar -cvz *.h *.cpp makefile -f u21434159.tar.gz

v:
		make debugcpp
		valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-file=valg.txt ./main
		make c

val:
		valgrind --tool=memcheck --leak-check=yes ./main

g:
		make
		gdb ./main
		make c

tar_unzip:
		tar -xzvf u21434159.tar.gz
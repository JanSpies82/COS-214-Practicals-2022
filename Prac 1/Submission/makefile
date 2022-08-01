run: main
		./main

main:	*.o
		g++ -o main *.o

*.o:	*.cpp
		g++ -c -w *.cpp
		
clean:
		rm *.o main 		

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

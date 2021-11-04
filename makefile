basic=basicClassification
adv=advancedClassificationLoop
rec=advancedClassificationRecursion
# to use dynamic write the path of the folder export LD_LIBRARY_PATH=/home/username/foo:$LD_LIBRARY_PATH
all: mains maindrec maindloop loops recursives recursived loopd

#loops will create a static library using the loops option
loops: libclassloops.a
libclassloops.a: $(basic).o $(adv).o
	ar -rcs libclassloops.a $(basic).o $(adv).o
#{ part 1
#recursives will create a static library using the recursion option
recursives: libclassrec.a
libclassrec.a:$(basic).o $(rec).o
	ar -rcs libclassrec.a $(basic).o $(rec).o
#will create a main file using the main.c and the static recursive library
mains: libclassrec.a
	gcc -static -Wall -g main.c -L. -lclassrec -lm -o mains
#}

# creates a dynamic library using basic and recursive
#{ part 2
recursived: libclassrec.so
libclassrec.so: $(basic).o $(rec).o 
	gcc -Wall -shared $(basic).o $(rec).o -o libclassrec.so
maindrec: libclassrec.so main.o
	gcc -Wall main.o ./libclassrec.so -lm -o maindrec
#}

#{ part 3
# creates a dynamic library using 
loopd: libclassloops.so

libclassloops.so: $(basic).o $(adv).o
	gcc -Wall -shared $(basic).o $(adv).o -o libclassloops.so
maindloop: libclassloops.so main.o
	gcc -Wall main.o ./libclassloops.so -lm -o maindloop

#}
$(basic).o:
	gcc -Wall -c $(basic).c
$(rec).o:
	gcc -Wall -c $(rec).c
$(adv).o:
	gcc -Wall -c $(adv).c
main.o:
	gcc -g -Wall -c main.c -o main.o

delete=!(*h|*c|makefile)
.PHONY: 
clean:
	find . -type f ! -name "*.c" ! -name "*.h" ! -name "makefile" ! -name "*.txt" -delete

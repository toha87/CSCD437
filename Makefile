CC = gcc

FLAGS = -c -pedantic -Wall -Wextra -Werror
FINAL = -pedantic -Wall -Wextra -Werror -lcrypt

OBJS = ./functions/fileName.o ./functions/fullName.o ./functions/password.o ./functions/readInt.o ./functions/writeToOutputFile.o

MAIN = defend.c

EXE = ./defend


defend:	${OBJS} ${MAIN}
	${CC} ${OBJS} ${MAIN} ${FINAL} -o ${EXE}


fileName.o:	./functions/fileName.c ./functions/fileName.h
	${CC} ${FLAGS} fileName.c

fullName.o:	./functions/fullName.c ./functions/fullName.h
	${CC} ${FLAGS} fullName.c

password.o:	./functions/password.c ./functions/password.h
	${CC} ${FLAGS} password.c 

readInt.o:	./functions/readInt.c ./functions/readInt.h
	${CC} ${FLAGS} readInt.c

writeToOutputFile.o:	./functions/writeToOutputFile.c ./functions/writeToOutputFile.h
	${CC} ${FLAGS} writeToOutputFile.c


clean:
	rm -rf ./functions/*.o
	rm -rf defend
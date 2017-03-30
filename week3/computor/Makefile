TARGET = a.out
CC	   = gcc
OBJS   = main.o src.o

${TARGET} : ${OBJS}
	${CC}  ${OBJS} -o ${TARGET}

.PHONY:clean
clean:
	rm ${OBJS}  ${TARGET}

TARGET = a.out
CC = gcc
CFLAGS = -g
# 列举当前目录下所有的.c 文件
SRCFILES = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, ${SRCFILES})


${TARGET} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${TARGET} 

%.o : %.c
	${CC} ${CFLAGS} -c  $<

clean:
	@echo "rm project ..."
	-rm -rf ${TARGET} *.o 
	@echo "rm complete ..."

.PHONY:clean

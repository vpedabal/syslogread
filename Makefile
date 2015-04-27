
PROG = bin/prog
BIN_DIR = bin/ 
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = -Iinc/ -I/usr/local/include -I/home/vpedabal/new_ipmiutil/include -I/home/vpedabal/new_ipmiutil/share/ipmiutil
LIB_DIR = -L/usr/lib64 -L/home/vpedabal/new_ipmiutil/lib
EXTRA_LIBS = 
PROG_NAME = prog
CC = gcc

_OBJS = syslog.o util.o main.o 
OBJS = $(patsubst %,$(OBJ_DIR)%,$(_OBJS))

all: DIR $(OBJS)
	$(CC) $(INC_DIR) -o $(PROG) $(OBJS)  $(LIB_DIR) $(EXTRA_LIBS) 


DIR:
	mkdir obj; mkdir bin

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(INC_DIR) -Wall -pedantic -ansi -c -g -o $@ $<$(CFLAGS) 

clean:
	$(RM) -r obj bin *.o


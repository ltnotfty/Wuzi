CC=gcc

CFLAGS= -Wall -g -ggdb



# path for makefile search prerequisite
VPATH=src:build

TARGET=wuzi

# $@ name of target
# $< name of first pre-requisite
# $? name of pre-requesites that are newer than the target
# $^ name of all pre-requisites with spaces between them
OBJS =
OBJS += main.o
OBJS += main_loop.o
OBJS += game_loop.o
OBJS += wuzi_player.o
OBJS += wuzi_board.o





${TARGET}:  $(OBJS)
	$(CC) $(CFLAGS) $? -o $@
build/main.o: main.c 
	$(CC)  $(CFLAGS) -c $? -o $@
build/main_loop.o: main_loop.c
	$(CC)  $(CFLAGS) -c $? -o $@
build/game_loop.o: game_loop.c
	$(CC)  $(CFLAGS) -c $? -o $@
build/wuzi_player.o: wuzi_player.c
	$(CC)  $(CFLAGS) -c $? -o $@
build/wuzi_board.o: wuzi_board.c
	$(CC) $(CFLAGS)  -c $? -o $@


.PHONY: 
	clean 
clean:
	-rm build/*.o ${TARGET}

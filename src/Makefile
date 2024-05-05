DIR_Examples = ./
DIR_BIN      = ./bin

OBJ_C = $(wildcard ${DIR_Examples}/*.c)
OBJ_O = $(patsubst %.c,${DIR_BIN}/%.o,$(notdir ${OBJ_C}))

TARGET = main

USELIB = USE_BCM2835_LIB
DEBUG = -D $(USELIB)
LIB = -lbcm2835 -lm


CC = gcc
MSG = -g -O3 -Wall
CFLAGS += $(MSG) $(DEBUG)

${TARGET}:${OBJ_O}
	$(CC) $(CFLAGS) $(OBJ_O) -o $@ $(LIB)
    
${DIR_BIN}/%.o:$(DIR_Examples)/%.c
	$(CC) $(CFLAGS) -c  $< -o $@
	
clean :
	rm $(DIR_BIN)/*.* 
	rm $(TARGET) 

USELIB = USE_BCM2835_LIB
DEBUG = -D $(USELIB)
LIB = -lbcm2835 -lm

CC = g++
MSG = -g -O3 -Wall
CFLAGS += $(MSG) $(DEBUG)

server:
	$(CC) $(CFLAGS) server.cc -o server $(LIB)

client:
	$(CC) $(CFLAGS) client.cc -o client $(LIB)

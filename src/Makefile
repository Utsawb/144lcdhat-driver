USELIB = USE_BCM2835_LIB
DEBUG = -D $(USELIB)
LIB = -lbcm2835 -lm

CC = g++
MSG = -g -O3 -Wall
CFLAGS += $(MSG) $(DEBUG)

all:
	$(CC) $(CFLAGS) server.cc -o server
	g++ -g -O3 -Wall client.cc -o client

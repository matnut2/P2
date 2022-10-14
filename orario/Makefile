# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o orario.o
	$(CC) $(CFLAGS) -o main main.o orario.o
 
# The main.o target can be written more simply
 
main.o: main.cpp orario.h
	$(CC) $(CFLAGS) -c main.cpp
 
orario.o : orario.h
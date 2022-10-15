# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o telefonata.o
	$(CC) $(CFLAGS) -o main main.o telefonata.o
 
# The main.o target can be written more simply
 
main.o: main.cpp telefonata.o
	$(CC) $(CFLAGS) -c main.cpp
 
orario.o : orario.h
telefonata.o : telefonata.h
#!/bin/bash
g++ -c -o $1.o $1.cpp
g++ -o $1.app $1.o -lboost_system -lboost_filesystem -lcurses -lncurses
rm $1.o

#!/bin/bash

# A build script for C++ project.
# Author: wanghongfei

declare -r CUR_PATH=`pwd`"/"
declare -r SRC_DIR=$CUR_PATH"src/"
declare -r OBJ_DIR=$CUR_PATH"bin/obj/"
declare -r RELEASE_DIR=$CUR_PATH"bin/release/"

# function: check whether last command succeed or not.
check() {
	if [ $? -eq 0 ]; then
		echo "Succeed."
	else
		echo "Failed"
		exit 1
	fi
}

# clean project
if [ -n "$1" ]; then
	if [ "$1" == "clean" ]; then
		rm ${OBJ_DIR}*
		rm ${RELEASE_DIR}*
		echo "done"
		exit 0
	fi
fi

# compiling phase
echo "start building..."
echo -e "\n****************** compiling phase ***********************\n"
cd $SRC_DIR # change working directory

echo ">>> g++ -c LinkedList.cpp -o ${OBJ_DIR}LinkedList.o"
g++ -c LinkedList.cpp -o ${OBJ_DIR}LinkedList.o
echo ">>> g++ -c main.cpp -o ${OBJ_DIR}main.o"
g++ -c main.cpp -o ${OBJ_DIR}main.o

check
cd .. # exit working directory


# linking phase
echo -e "\n******************* linking phase *************************\n"
cd $OBJ_DIR

echo ">>> g++ main.o LinkedList.o -o ${RELEASE_DIR}program"
g++ main.o LinkedList.o -o ${RELEASE_DIR}program

check

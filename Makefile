.PHONY: run build rebuild clean

#The FILE_NAME variable contains the filename
FILE_NAME = My_Array

run: build
	./$(FILE_NAME)

build: $(FILE_NAME)

$(FILE_NAME): $(FILE_NAME).o
	g++ -o $(FILE_NAME) $(FILE_NAME).o

$(FILE_NAME).o: Main.cpp $(FILE_NAME).cpp $(FILE_NAME).h
	g++ -o $(FILE_NAME).o -c Main.cpp

rebuild: clean build

clean: 
	rm -vf $(FILE_NAME).o $(FILE_NAME)
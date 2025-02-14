# the compiler: gcc for C program, define as g++ for C++
  CC = g++
 
  # compiler flags:
  #  -g     - this flag adds debugging information to the executable file
  #  -Wall  - this flag is used to turn on most compiler warnings
  CXXFLAGS  = -I -g -Wall -std=c++17
  
  # The build target 
	TARGET = myprogram
 
  all: $(TARGET)
  
  $(TARGET): main.o
		$(CC) $(CXXFLAGS) -o $(TARGET) main.o
 
  clean:
	$(RM) $(TARGET) *.o

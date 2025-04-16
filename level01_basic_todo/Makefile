
CXX = clang++

CXXFLAGS = -std=c++17 -Wall -O2

TARGET = todos

SRC = todo_list.cpp

$(TARGET):$(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
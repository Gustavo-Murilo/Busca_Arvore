CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = main.exe

# Lista de arquivos a serem compilados
SRCS = main.cpp \
       implementation/tree.cpp \
	   implementation/searchTree.cpp \
	   implementation/doublyLinkedList.cpp

# Objetos a serem gerados a partir dos arquivos fonte
OBJS = $(SRCS:.cpp=.o)

# Regra padrão para compilar o programa
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regra de compilação para cada arquivo fonte
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra de limpeza
clean:
	rm -f $(TARGET) $(OBJS)
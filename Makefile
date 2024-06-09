CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = main.exe

# Lista de arquivos a serem compilados
SRCS = main.cpp \
       implementations/tree.cpp \
       implementations/search_tree.cpp \
       implementations/doubly_linked_list.cpp \
       implementations/time_measure.cpp

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
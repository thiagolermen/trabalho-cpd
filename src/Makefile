# USO
# make main
# ...etc

CXX = g++
# FLAGS do compilador .cpp -> .o
CXXFLAGS = -std=c++11 -g
# FLAGS do linker
LDFLAGS = 

# Comando default: adicione os testes aqui
all: main

# Comando generico de .o
%.o: %.cpp
	$(CXX) -c $^ -o $@ $(CXXFLAGS)

main: BinarySearchTree.o LinearProbing.o SeparateChaining.o TrieTree.o main.o
	$(CXX) $^ -o $@ $(LDFLAGS)


# Limpa os arquivos construidos
clean:
	$(RM) *.o *.exe

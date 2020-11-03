# USO
# make main
# ...etc

CXX = g++
# FLAGS do compilador .cpp -> .o
CXXFLAGS = -std=c++11 -g
# FLAGS do linker
LDFLAGS = 

# Comando default: adicione os testes aqui
all: main.exe Test.exe

# Comando generico de .o
%.o: %.cpp
	$(CXX) -c $^ -o $@ $(CXXFLAGS)

main.exe: BinarySearchTree.o LinearProbing.o SeparateChaining.o TrieTree.o Menu.o AuxiliaryFunctions.o main.o
	$(CXX) $^ -o $@ $(LDFLAGS)

Test.exe: BinarySearchTree.o LinearProbing.o SeparateChaining.o TrieTree.o Menu.o AuxiliaryFunctions.o Test.o
	$(CXX) $^ -o $@ $(LDFLAGS)


# Limpa os arquivos construidos
clear_o:
	$(RM) *.o

# Limpa os arquivos construidos
clear_exe:
	$(RM) *.exe

# Limpa os arquivos construidos
clear_all:
	$(RM) *.o *.exe
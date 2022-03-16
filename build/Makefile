#Variable objetos
OBJECTS = main.o celula.o grid.o muerta.o stateEgg.o stateLarva.o statePupa.o stateAdult.o
#Flags de compilacion
CFLAGS = -c -std=c++17

game: $(OBJECTS)
	g++  $(OBJECTS) -o game
	mv *.o ../objects
	mv game ../bin


main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

celula.o: ../src/celula.cpp ../include/celula.hpp
	g++ $(CFLAGS) ../src/celula.cpp

grid.o: ../src/grid.cpp ../include/grid.hpp
	g++ $(CFLAGS) ../src/grid.cpp
muerta.o: ../src/muerta.cpp ../include/muerta.hpp
	g++ $(CFLAGS) ../src/muerta.cpp
stateEgg.o: ../src/stateEgg.cpp ../include/stateEgg.hpp
	g++ $(CFLAGS) ../src/stateEgg.cpp
stateLarva.o: ../src/stateLarva.cpp ../include/stateLarva.hpp
	g++ $(CFLAGS) ../src/stateLarva.cpp
statePupa.o: ../src/statePupa.cpp ../include/statePupa.hpp
	g++ $(CFLAGS) ../src/statePupa.cpp
stateAdult.o: ../src/stateAdult.cpp ../include/stateAdult.hpp
	g++ $(CFLAGS) ../src/stateAdult.cpp

.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run:
	../bin/game



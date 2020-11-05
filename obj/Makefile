encounterSim:	main.o roll.o action.o entity.o debugger.o
	g++ -o ../encounterSim -I../headers main.o roll.o action.o entity.o debugger.o

main.o:	../src/main.cpp
	g++ -c ../src/main.cpp -I../headers

roll.o:	../src/roll.cpp
	g++ -c ../src/roll.cpp -I../headers

action.o:	../src/action.cpp
	g++ -c ../src/action.cpp -I../headers

entity.o:	../src/entity.cpp
	g++ -c ../src/entity.cpp -I../headers

debugger.o:	../src/debugger.cpp
	g++ -c ../src/debugger.cpp -I../headers

clean:
	rm *.o && rm ../encounterSim

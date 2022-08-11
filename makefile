test:	main.cpp tat_math.cpp
	g++ -g -o test main.cpp tat_math.cpp

clean:
	-rm test

release:	main.cpp tat_math.cpp
	g++ -o test main.cpp tat_math.cpp

debug:	main.cpp tat_math.cpp
	g++ -g -o test_d main.cpp tat_math.cpp

clean:
	-rm test test_d

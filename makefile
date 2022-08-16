SOURCES=main.cpp tat_math.cpp tat_utils.cpp
release:	
	g++ -o test $(SOURCES)

debug:	
	g++ -g -o test_d $(SOURCES)

clean:
	-rm test test_d

EXEC=a.out

$(EXEC): $(wildcard *.cpp)
	c++ -g -Wall -std=c++17 $^ -o $@

run: $(EXEC)
	./$(EXEC)

clean:
	rm $(EXEC)

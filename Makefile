main: hello test window

hello: hello.cpp
	g++ -o hello hello.cpp -lncurses

test: test.cpp
	g++ -o test test.cpp -lncurses

window: Window.cpp
	g++ -o Window Window.cpp -lncurses
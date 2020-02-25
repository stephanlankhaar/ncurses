main: hello test window menu helloWorld testUserMovement

hello: hello.cpp
	g++ -o hello hello.cpp -lncurses

test: test.cpp
	g++ -o test test.cpp -lncurses

window: Window.cpp
	g++ -o Window Window.cpp -lncurses

menu: menu.cpp
	g++ -o menu menu.cpp -lncurses

helloWorld: helloWorld.cpp
	g++ -o helloWorld helloWorld.cpp -lncurses

testUserMovement: testUserMovement.cpp
	g++ -o testUserMovement testUserMovement.cpp -lncurses
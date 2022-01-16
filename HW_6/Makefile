CXXFLAGS = -g -Wall -c -fpic
CLINK = $(CXX)
CXX = g++
RM = rm -rf *.o *.exe
CPPS = ip.cpp field.cpp port.cpp string.cpp
OBJ = ip.o field.o port.o string.o
LIB = libfirewall.so



firewall.exe: $(LIB) $(OBJ) $(CPPS) main.o
	$(CXX)  -g -Wall $(OBJ) main.o -o firewall.exe -L. -lfirewall -L. -linput

libfirewall.so: $(OBJ)
	$(CLINK) -shared $(OBJ) -o $(LIB)

main.o: main.cpp string.h ip.h input.h port.h
		$(CXX) -g -Wall -c -c -fpic main.cpp

field.o: string.cpp  field.cpp field.h
	$(CXX) $(CXXFLAGS) field.cpp

ip.o:  ip.h ip.cpp field.o
	$(CXX) $(CXXFLAGS) ip.cpp
	
port.o: port.cpp port.h field.o
	$(CXX) $(CXXFLAGS) port.cpp

string.o: string.cpp string.h
	$(CXX) $(CXXFLAGS) string.cpp



clean:
	$(RM) $(LIB)

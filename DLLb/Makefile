INC_PATH 	= -I/usr/include
LIB_PATH	= -L/usr/lib
TARGET_PATH	= ../Bin

# for gcc
C++ = g++

# system command
CP = cp -f
RM = rm -f

CFLAGS	= --std=c++11 -fPIC -g -fvisibility=hidden

DLL			= libDLLb.so

DLL_OBJ		= DLLb.o

.SUFFIXES:
.SUFFIXES:	.cpp .o

all: $(DLL)

$(DLL): $(DLL_OBJ)
	$(C++) -shared -o $@ $^ $(LIB_PATH) -lboost_system -lboost_filesystem -ldl
	$(CP) $@ $(TARGET_PATH)

.cpp.o:
	$(C++) $(CFLAGS) $(INC_PATH) -c $<

clean:
	$(RM) *.o $(DLL)

# compiler
CC = gcc

# compiler flags
#  - Wall: 
#  - Werror: Warnings get to errors
#  - Wextra: 
#  - Wpedantic: 
#  - O2:
#  - std=c11: 
#  - flto: 
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -flto

# all object files (uncomment to add files!)
# OBJ = 
SOBJ = $(addprefix src/,$(addsuffix ,$(OBJ)))

# build target executable
TARGET = maincc

$(TARGET): $(SOBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(SOBJ) $(TARGET)
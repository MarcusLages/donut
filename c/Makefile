CC := gcc
CFLAGS := -Wall

# OS definition as CFLAGS
# WIN32 : Windows
# LINUX : Linux
# OSX : MacOS
ifeq ($(OS),Windows_NT)
	CFLAGS += -D WIN32
else
	UNAME := $(shell uname -s)
	ifeq ($(UNAME),Linux)
		CFLAGS += -D LINUX
	endif
	ifeq ($(UNAME),Darwin)
		CFLAGS += -D OSX
	endif
endif

SRC_DIR := src
OBJ_DIR := obj

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
TARGET = donut

all : $(TARGET)

$(TARGET) : $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	.\$(TARGET)

clean :
	rm -rf $(OBJ_DIR) $(TARGET)

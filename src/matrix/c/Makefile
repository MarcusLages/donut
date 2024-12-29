CC := gcc
CFLAGS := -Wall

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

clean :
	rm -rf $(OBJ_DIR) $(TARGET)

CC := gcc
CFLAGS := -std=c99 -Wall -Werror

CFILES_DIR := ./src
CFILES := $(wildcard $(CFILES_DIR)/*.c)

INC_DIR := ./inc
INCLUDES := $(wildcard $(INC_DIR)/*.h)

OBJ_DIR := ./out
OBJECTS := $(CFILES:$(CFILES_DIR)/%.c=$(OBJ_DIR)/%.o)

APP = app.exe

$(APP): $(OBJECTS)
	$(CC) $^ -o $@ -lm

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(CFILES_DIR)/%.c $(INCLUDES) $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -lm

run: $(APP)
	./$^

clean:
	$(RM) $(OBJ_DIR)/*.o
 

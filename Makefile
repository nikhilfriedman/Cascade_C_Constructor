CC = gcc
CFLAGS = -Wall -pedantic -O3 -m64
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
INCLUDES = -I./SDL2/include -I./src/compilation -I./src/files -I./src/graphics
LIBS = -L./SDL2/lib
SRC_DIR = src

SRC = $(wildcard $(SRC_DIR)/*.c) \
      $(wildcard $(SRC_DIR)/compilation/*.c) \
      $(wildcard $(SRC_DIR)/files/*.c) \
      $(wildcard $(SRC_DIR)/graphics/*.c)

OBJ = resources/textures/icon.o
OUTPUT = Cascade

all: $(OUTPUT)

$(OUTPUT): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(OBJ) $(INCLUDES) $(LIBS) $(LDFLAGS) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)

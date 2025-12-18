CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -std=c99 \
         -Iinclude

TARGET_DIR = target
TARGET = $(TARGET_DIR)/engine

SRC = src/main.c src/audio.c src/render.c src/logic.c

LIBDIR = libs
STATIC_LIBS = $(wildcard $(LIBDIR)/*.a)

ASSETS_SRC = assets
ASSETS_DST = $(TARGET_DIR)/assets

# system libs (math REQUIRED)
SYS_LIBS = -lm -ldl -lpthread -lX11

.PHONY: all clean

all:
	@rm -rf $(TARGET_DIR)
	@mkdir -p $(TARGET_DIR)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) \
		-Wl,--start-group $(STATIC_LIBS) -Wl,--end-group \
		$(SYS_LIBS)
	@cp -r $(ASSETS_SRC) $(ASSETS_DST)

clean:
	rm -rf $(TARGET_DIR)
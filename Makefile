BINARY_NAME=app
BUILD_DIR=build

.PHONY: all build run clean test

all: build

build:
	mkdir -p $(BUILD_DIR)
	go build -o $(BUILD_DIR)/${BINARY_NAME} ./src/main.go

run: build
	./$(BUILD_DIR)/${BINARY_NAME}

clean:
	go clean
	rm -rf $(BUILD_DIR)

test:
	go test ./src/...

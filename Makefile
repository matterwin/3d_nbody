SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin

CUDA_SRCS := $(wildcard $(SRC_DIR)/*.cu)
CPP_SRCS  := $(wildcard $(SRC_DIR)/*.cpp)

OBJS := $(patsubst $(SRC_DIR)/%.cu,$(OBJ_DIR)/%.o,$(CUDA_SRCS)) \
        $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CPP_SRCS))

EXEC := $(BIN_DIR)/nbody

INC := $(SRC_DIR)

DEBUG ?= 0
OPTS = -O3 -Wall
ifeq ($(DEBUG),1)
    OPTS += -DDEBUG
endif

$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p $(BIN_DIR))

all: $(EXEC)

# cuda
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cu
	nvcc -c $< -o $@ $(OPTS) -I$(INC)

# mpi/cpp
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mpicxx -c $< -o $@ $(OPTS) -I$(INC)

# linker
$(EXEC): $(OBJS)
	mpicxx $(OBJS) -L/opt/cuda/lib64 -lcudart -o $@

clean:
	rm -f $(OBJS) $(EXEC)


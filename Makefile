SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin

EXEC := $(BIN_DIR)/nbody

NVCC := /opt/cuda/bin/nvcc
CXX  := g++

CUDA_SRCS := $(wildcard $(SRC_DIR)/*.cu)
CPP_SRCS  := $(wildcard $(SRC_DIR)/*.cpp)

CU_OBJS  := $(CUDA_SRCS:$(SRC_DIR)/%.cu=$(OBJ_DIR)/%.o)
CPP_OBJS := $(CPP_SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
OBJS := $(CU_OBJS) $(CPP_OBJS)

INC := -I$(SRC_DIR) -I/opt/cuda/include

NVCCFLAGS := -O2 $(INC)
CXXFLAGS  := -O2 -Wall $(INC)

DEBUG ?= 1
ifeq ($(DEBUG),1)
    NVCCFLAGS += -DDEBUG -g
    CXXFLAGS  += -DDEBUG -g
endif

$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

all: $(EXEC)

# cuda
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cu
	$(NVCC) -c $< -o $@ $(NVCCFLAGS)

# cpp
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# linker
$(EXEC): $(OBJS)
	$(NVCC) $^ -o $@ -lcudart -lpthread

clean:
	rm -f $(OBJ_DIR)/*.o $(EXEC)

.PHONY: all clean


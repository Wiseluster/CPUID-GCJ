.PHONY: all asm test

GCJ = gcj
GCJFLAGS = -g -O2 -Wall -Wpedantic
LDFLAGS = -pthread

all: test

asm: CPUID.cc
	$(GCJ) $(GCJFLAGS) -c $^

test: Test
	./$^

Test: CPUID.cc CPUID.java Test.java
	$(GCJ) $(GCJFLAGS) --main=Test $^ -o $@

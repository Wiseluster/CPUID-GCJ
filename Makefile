.PHONY: all asm test

GCJ = gcj
GCJFLAGS = -g -O2 -Wall -Wpedantic
LDFLAGS = -pthread

all: test

asm: CPUID.cc
	$(GCJ) $(GCJFLAGS) -S $^

test: Test
	./$^

Test: CPUID.cc CPUID.java Test.java
	$(GCJ) $(GCJFLAGS) $(LDFLAGS) --main=Test $^ -o $@

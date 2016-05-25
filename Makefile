.PHONY: all test

GCJ = gcj
GCJFLAGS = --main=Test -g -O2 -Wall -Wpedantic -pthread

all: test

test: Test
	./$^

Test: CPUID.cc CPUID.java Test.java
	$(GCJ) $(GCJFLAGS) $^ -o $@

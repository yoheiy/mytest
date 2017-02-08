all: mytest

mytesttest: mytest.c nu_unit.h
	$(CC) -o $@ -DUNIT_TEST $<

test: mytesttest
	./mytesttest

clean:
	$(RM) mytest mytesttest

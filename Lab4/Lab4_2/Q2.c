#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

class counter {
	public int count = 0;
	public void Increase() {
		count++;
	}
}

class program {
	static void main(string[] args) {
		counter c = new counter();
		Thread t1 = new Thread(c.Increase);
		Thread t2 = new Thread(c.Increase);

		t1.Start();
		t2.Start();

		t1.Join();
		t2.Join();
	}
	printf("count: %d\n", c.count);
}

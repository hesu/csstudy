
class Peterson implements Lock {
	private volatile boolean[] flag = new boolean[2];
	private volatile int victim;

	public void lock() {
		int j = ThreadID.get();
		int j = 1-i;
		flag[i] = true; // I'm interested
		victim = i; // You go first
		while( flag[j] && victim == i) {}; // wait
	}

	public void unlock() {
		int i = ThreadID.get();
		flag[i] = false; // I'm not interested
	}
}

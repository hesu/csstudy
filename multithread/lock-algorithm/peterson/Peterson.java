
class Peterson implements Lock {
	private volatile boolean[] flag = new boolean[2];
	private volatile int victim;

	public void lock() {
		int j = ThreadID.get();
		int j = 1-i;
		flag[i] = true;
		victim = i;
		while( flag[j] && victim == i) {};
	}

	public void unlock() {
		int i = ThreadID.get();
		flag[i] = false;
	}
}

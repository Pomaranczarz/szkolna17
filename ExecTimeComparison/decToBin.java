public class test_java {
z
	public static void main(String[] args) {
		System.out.println("pog test");
		double measureSum = 0;
		long numOfCases = 5000;
		long count = 1;
		while(numOfCases < 1_000_000) {
			for(byte i = 0; i < 100; i++) {
				measureSum += measure(numOfCases);
			}
			System.out.println("Average exec time for " + numOfCases + " cases: " + (measureSum/100) + " µs");
			numOfCases += 5000 * count;
			measureSum = 0;
			count += 1;
		}
	}

	public static long measure(long count) {
		long t1, t2;
		t1 = System.nanoTime();
		for(long i = 0; i < count; i++) {
			decToBin(i);
		}
		t2 = System.nanoTime();
		return (t2 - t1)/1000;
	}

	public static String decToBin(long n) {
		StringBuilder result = new StringBuilder();
		while(n > 0) {
			result.append((char) ('0'+(n % 2)));
			n /= 2;
		}
		return result.reverse().toString();
	}

}

package boj1;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

class IntComparator implements Comparator<Integer> {

	@Override
	public int compare(Integer o1, Integer o2) {
		if(Math.abs(o1) == Math.abs(o2)) {
			return o1 - o2;
		}
		else {
			return Math.abs(o1) - Math.abs(o2);
		}
	}
	
}

public class p11286 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		PriorityQueue<Integer> pq = new PriorityQueue<>(new IntComparator());
		
		for(int i = 0; i < N; i++) {
			int num = sc.nextInt();
			if(num == 0) {
				if(pq.isEmpty()) System.out.println(0);
				else System.out.println(pq.poll());
			}
			else {
				pq.add(num);
			}
		}
	}

}

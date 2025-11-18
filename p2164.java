package boj1;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class p2164 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		Queue<Integer> queue = new LinkedList<>();
		
		for(int i = 1; i <=N; i++) {
			queue.add(i);
		}
		
		while(true) {
			queue.poll();
			if(queue.size() == 1) {
				System.out.print(queue.peek());
				break;
			}
			Integer num = queue.poll();
			queue.add(num);
		}
	}

}

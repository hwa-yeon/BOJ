package boj1;

import java.util.Scanner;

public class p2018 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		int start = 1;
		int end = 1; 
		int sum = 1;
		int count = 1;
		
		while(start != N) {
			if(sum == N) {
				count++;
				end++;
				sum += end;
			}
			else if(sum < N) {
				end++;
				sum += end;
			}
			else {
				sum -= start;
				start++;
			}
		}
		System.out.print(count);
	}

}

package boj1;

import java.util.Scanner;

public class p11659 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		int[] arr = new int[N+1];
		int[] sum = new int[N+1];
		arr[0] = 0;
		sum[0] = 0;
		
		for(int i = 1; i <= N; i++) {
			arr[i] = sc.nextInt();
			sum[i] = sum[i-1] + arr[i];
		}
		
		for(int k = 0; k < M; k++) {
			int i = sc.nextInt();
			int j = sc.nextInt();
			System.out.println(sum[j] - sum[i-1]);
		}
	}
}

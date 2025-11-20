package boj1;

import java.util.Arrays;
import java.util.Scanner;

public class p1920 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int[] A = new int[N];
		for(int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}
		int M = sc.nextInt();
		int[] B = new int[M];
		for(int i = 0; i < M; i++) {
			B[i] = sc.nextInt();
		}
		
		Arrays.sort(A);
		for(int i = 0; i < M; i++) {
			int start = 0;
			int end = N - 1;
			int mid;
			int result = 0;
			while(start <= end) {
				mid = (start + end) / 2;
				if(A[mid] == B[i]) {
					result = 1;
					break;
				}
				else if(A[mid] > B[i]) {
					end = mid - 1;
				}
				else {
					start = mid + 1;
				}
			}
			System.out.println(result);
		}
	}

}

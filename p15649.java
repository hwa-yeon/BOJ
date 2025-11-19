package boj1;

import java.util.Scanner;

public class p15649 {
	
	static int N;
	static int M;
	static int[] arr;
	static boolean[] visited;
	
	static void back(int depth) {
		if(depth == M) {
			for(int num : arr) {
				System.out.print(num + " ");
			}
			System.out.println();
			return;
		}
		
		for(int i = 1; i <= N; i++) {
			if(!visited[i]) {
				visited[i] = true;
				arr[depth] = i;
				back(depth + 1);
				visited[i] = false;
			}
		}
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		arr = new int[M];
		visited = new boolean[N + 1];
		
		back(0);
	}

}

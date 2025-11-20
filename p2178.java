package boj1;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Locate {
	int n;
	int m;
	
	Locate(int n, int m) {
		this.n = n;
		this.m = m;
	}
}

public class p2178 {

	static int[][] maze;
	static boolean[][] visited;
	static int N, M;
	static int[] x = {0, -1, 0, 1};
	static int[] y = {-1, 0, 1, 0};
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		M = sc.nextInt();
		maze = new int[N][M];
		visited = new boolean[N][M];
		for(int i = 0; i < N; i++) {
			String str = sc.next();
			char[] ch = str.toCharArray();
			for(int j = 0; j < M; j++) {
				maze[i][j] = ch[j] - '0';
			}
		}
		BFS(0, 0);
		System.out.print(maze[N-1][M-1]);
	}
	
	static void BFS(int n, int m) {
		Queue<Locate> Q = new LinkedList<>();
		Q.add(new Locate(n , m));
		while(!Q.isEmpty()) {
			Locate locate = Q.poll();
			for(int i = 0; i < 4; i++) {
				if(check(locate.n + y[i], locate.m + x[i])) {
					Q.add(new Locate(locate.n + y[i], locate.m + x[i]));
					visited[locate.n + y[i]][locate.m + x[i]] = true;
					maze[locate.n + y[i]][locate.m + x[i]] = maze[locate.n][locate.m] + 1;
				}
			}
		}
	}
	
	static boolean check(int n, int m) {
		if(n < 0 || n >= N || m < 0 || m >= M) return false;
		if(maze[n][m] == 0) return false;
		if(visited[n][m]) return false;
		return true;
	}

}

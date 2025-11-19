package boj1;

import java.util.ArrayList;
import java.util.Scanner;

public class p11724 {
	
	static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
	static boolean[] visited;
	
	static void addEdge(int a, int b) {
		graph.get(a).add(b);
		graph.get(b).add(a);
	}
	
	static void dfs(int node) {
		visited[node] = true;
		
		for(int next : graph.get(node)) {
			if(!visited[next]) {
				dfs(next);
			}
		}
	}
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		visited = new boolean[N + 1];
		
		for(int i = 0; i <= N; i++) {
			graph.add(new ArrayList<>());
		}
		
		for(int i = 0; i < M; i++) {
			int u = sc.nextInt();
			int v = sc.nextInt();
			addEdge(u, v);
		}
		
		int count = 0;
		for(int i = 1; i <= N; i++) {
			if(!visited[i]) {
				dfs(i);
				count++;
			}
		}
		System.out.print(count);
	}

}

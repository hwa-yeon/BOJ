package boj1;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class p1874 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		int[] input = new int[n];
		for(int i = 0; i < n; i++) {
			input[i] = sc.nextInt();
		}
		
		Stack<Integer> stack = new Stack<>();
		int stackNum = 0;
		
		ArrayList<String> result = new ArrayList<>();
		
		for(int i = 0; i < n; i++) {	
			while(stack.isEmpty() || input[i] > stack.peek()) {
				stackNum++;
				stack.push(stackNum);
				result.add("+");
			}
			
			if(input[i] == stack.peek()) {
				stack.pop();
				result.add("-");
			}
			
		}
		
		if(stack.isEmpty()) {
			for(String r : result) {
				System.out.println(r);
			}
		}
		else {
			System.out.print("NO");
		}
	}

}

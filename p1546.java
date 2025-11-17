package boj1;

import java.util.Scanner;

public class p1546 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		double[] oldScore = new double[n];
		double max = 0;
		for(int i = 0; i < n; i++) {
			oldScore[i] = sc.nextInt();
			
			if(oldScore[i] > max) {
				max = oldScore[i];
			}
		}
		
		double sum = 0;
		for(int i = 0; i < n; i++) {
			sum += oldScore[i] / max * 100;
		}
		System.out.print(sum / n);
	}

}

package boj1;

import java.util.Scanner;

public class p12891 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		int S = sc.nextInt();
		int P = sc.nextInt();
		
		String dna = sc.next();
		char[] dnaChar = dna.toCharArray();
		
		int[] dnaInput = new int[4];
		for(int i = 0; i < 4; i++) {
			dnaInput[i] = sc.nextInt();
		}
		
		int[] dnaCount = new int[4];
		for(int i = 0; i < P; i++) {
			if(dnaChar[i] == 'A') dnaCount[0]++;
			else if(dnaChar[i] == 'C') dnaCount[1]++;
			else if(dnaChar[i] == 'G') dnaCount[2]++;
			else if(dnaChar[i] == 'T') dnaCount[3]++;
		}
		
		int result = 0;
		for(int i = P; i <= S; i++) {
			if(dnaCount[0] >= dnaInput[0] && dnaCount[1] >= dnaInput[1] && dnaCount[2] >= dnaInput[2] && dnaCount[3] >= dnaInput[3]) 
				result++;
			
			if(i == S) break;
			
			if(dnaChar[i - P] == 'A') dnaCount[0]--;
			else if(dnaChar[i - P] == 'C') dnaCount[1]--;
			else if(dnaChar[i - P] == 'G') dnaCount[2]--;
			else if(dnaChar[i - P] == 'T') dnaCount[3]--;
			
			if(dnaChar[i] == 'A') dnaCount[0]++;
			else if(dnaChar[i] == 'C') dnaCount[1]++;
			else if(dnaChar[i] == 'G') dnaCount[2]++;
			else if(dnaChar[i] == 'T') dnaCount[3]++;

		}
		System.out.print(result);
	}

}

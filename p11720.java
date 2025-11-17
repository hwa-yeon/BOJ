package boj1;

import java.util.Scanner;

public class p11720 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		
		String sNum = scanner.next();
		char[] cArray = sNum.toCharArray();
		
		int sum = 0;
		for(int i = 0; i < cArray.length; i++) {
			sum += cArray[i] - '0';
		}
		System.out.println(sum);
	}

}

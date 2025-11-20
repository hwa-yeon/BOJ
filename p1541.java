package boj1;

import java.util.Scanner;

public class p1541 {
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		String str = sc.nextLine();
		String[] strArr = str.split("-");
		
		int answer = 0;
		for(int i = 0; i < strArr.length; i++) {
			int tmp = mySum(strArr[i]);
			
			if(i == 0) answer += tmp;
			else answer -= tmp;
		}
		System.out.print(answer);
	}
	
	private static int mySum(String str) {
		String[] arr = str.split("[+]");
		int result = 0;
		for(int i = 0; i < arr.length; i ++) {
			result += Integer.parseInt(arr[i]);
		}
		return result;
	}

}

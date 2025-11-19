package boj1;

import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class p1427 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		
		char[] chArr = str.toCharArray();
		int[] arr = new int[chArr.length];
		for(int i = 0; i < chArr.length; i++) {
			arr[i] = chArr[i] - '0';
		}
		Arrays.sort(arr);
		for(int i = arr.length - 1; i >= 0; i--) {
			System.out.print(arr[i]);
		}
	}

}

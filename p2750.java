package boj1;

import java.util.Scanner;

public class p2750 {
	
    // 메인 병합정렬 함수
    public static void mergeSort(int[] arr) {
        if (arr.length < 2) return; // 원소가 1개 이하라면 이미 정렬됨

        int mid = arr.length / 2;

        // 왼쪽·오른쪽 배열 나누기
        int[] left = new int[mid];
        int[] right = new int[arr.length - mid];

        for (int i = 0; i < mid; i++) {
            left[i] = arr[i];
        }
        for (int i = mid; i < arr.length; i++) {
            right[i - mid] = arr[i];
        }

        // 재귀 호출
        mergeSort(left);
        mergeSort(right);

        // 병합
        merge(arr, left, right);
    }

    // 두 배열을 병합하여 하나의 배열로 합치는 함수
    public static void merge(int[] arr, int[] left, int[] right) {
        int i = 0, j = 0, k = 0;

        // 작은 값부터 arr에 넣기
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        // 남은 요소 처리
        while (i < left.length) {
            arr[k++] = left[i++];
        }

        while (j < right.length) {
            arr[k++] = right[j++];
        }
    }

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] arr = new int[N];
		for(int i = 0; i < N; i++) {
			arr[i] = sc.nextInt();
		}
		mergeSort(arr);
		for(int i = 0; i < N; i++) {
			System.out.println(arr[i]);
		}
	}

}
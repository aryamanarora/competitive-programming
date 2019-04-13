// Team23
// Problem2
// Intro

import java.util.*;
import java.math.*;

public class Team23Problem2 {

	static Scanner stin = new Scanner(System.in);
	
	static int F(int n, int[] values, int[] weights) {
		int res = 0;
		for (int i = 0; i < n; i++) res += values[i] * weights[i];
		return res;
	}
	
	static double W(int n, int[] values, int[] weights) {
		double inner_product = F(n, values, weights);
		double divisor = 0.0;
		for (int i = 0; i < n; i++) divisor += weights[i];
		return inner_product / divisor;
	}
	
	static boolean menu() {
		System.out.print("Enter q to quit: ");
		String line = stin.nextLine().trim();
		if (line.length() == 0) return true;
		if (line.startsWith("q")) return false;
		Scanner sline = new Scanner(line);
		
		int n = sline.nextInt();
		int[] values = new int[n];
		int[] weights = new int[n];
		
		for (int i = 0; i < n; i++) {
			values[i] = sline.nextInt();
		}
		for (int i = 0; i < n; i++) {
			weights[i] = sline.nextInt();
		}
		
		System.out.print("Average is: ");
		System.out.println(W(n, values, weights));
		return true;
 	}

	public static void main(String[] args) {
		System.out.println("Problem 2: N integer weighted average");
		while (menu());
		System.out.println("Bye");
	}

}
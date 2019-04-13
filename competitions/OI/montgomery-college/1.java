// Team23
// Problem1
// Intro

import java.util.*;
import java.math.*;

public class Team23Problem1 {
	static Scanner stin = new Scanner(System.in);
	
	static int F(int a, int b, int c, int d, int e, int f) {
		return a * d + b * e + c * f;
	}
	
	static double W(int a, int b, int c, int d, int e, int f) {
		double inner_product = F(a, b, c, d, e, f);
		double divisor = d + e + f;
		return inner_product / divisor;
	}
	
	static boolean menu() {
		System.out.print("Enter q to quit: ");
		String line = stin.nextLine().trim();
		if (line.length() == 0) return true;
		if (line.startsWith("q")) return false;
		Scanner sline = new Scanner(line);
		
		int a, b, c, d, e, f;
		a = sline.nextInt();
		b = sline.nextInt();
		c = sline.nextInt();
		d = sline.nextInt();
		e = sline.nextInt();
		f = sline.nextInt();
		
		System.out.print("Average is: ");
		System.out.println(W(a, b, c, d, e, f));
		return true;
 	}

	public static void main(String[] args) {
		System.out.println("Problem 1: 3 integer weighted average");
		while (menu());
		System.out.println("Bye");
	}

}
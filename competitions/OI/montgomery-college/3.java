// Team23
// Problem3
// Intro

import java.util.*;
import java.math.*;

public class Team23Problem3 {

	static Scanner stin = new Scanner(System.in);
	
	static boolean menu() {
		System.out.print("Enter q to quit: ");
		String line = stin.nextLine().trim();
		if (line.length() == 0) return true;
		if (line.startsWith("q")) return false;
		Scanner sline = new Scanner(line);
		
		int n = sline.nextInt();
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				int res = (r * c) % n;
				System.out.printf("%5d", res);
			}
			System.out.println();
		}
		
		return true;
 	}

	public static void main(String[] args) {
		System.out.println("Problem 3: Modulo N multiplication table");
		while (menu());
		System.out.println("Bye");
	}

}
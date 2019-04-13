// Team23
// Problem5
// Intro

import java.util.*;
import java.math.*;

public class Team23Problem5 {

	static Scanner stin = new Scanner(System.in);
	
	static boolean menu() {
		System.out.print("Enter q to quit: ");
		String line = stin.nextLine().trim();
		if (line.length() == 0) return true;
		if (line.startsWith("q")) return false;
		Scanner sline = new Scanner(line);
		
		double w, l, b;
		w = sline.nextInt();
		l = sline.nextInt();
		b = sline.nextInt();
		
		double ans = 0.0;
		ans += l * w;
		ans += 0.5 * (w * b);
		ans += Math.PI * w * w * 0.125;
		System.out.print("Area is: ");
		System.out.println(ans);
		
		return true;
 	}

	public static void main(String[] args) {
		System.out.println("Problem 5: Area of a figure");
		while (menu());
		System.out.println("Bye");
	}

}
// Team23
// Problem6
// Intro

import java.util.*;
import java.math.*;

public class Team23Problem6 {

	static Scanner stin = new Scanner(System.in);
	
	static boolean menu() {
		System.out.print("Enter op {add, sub, mult, div, exp} a and b or q to quit: ");
		String line = stin.nextLine().trim();
		if (line.length() == 0) return true;
		if (line.startsWith("q")) return false;
		Scanner sline = new Scanner(line);
		
		String op = sline.next().trim();
		double a = sline.nextDouble(), b = sline.nextDouble();
		System.out.print("    ");
		System.out.print(a);
		
		double res = 0.0;
		if (op.equals("add")) {
			System.out.print(" + ");
			res = a + b;
		}
		else if (op.equals("sub")) {
			System.out.print(" - ");
			res = a - b;
		}
		else if (op.equals("mult")) {
			System.out.print(" * ");
			res = a * b;
		}
		else if (op.equals("div")) {
			System.out.print(" / ");
			res = a / b;
		}
		else if (op.equals("exp")) {
			System.out.print(" ^ ");
			res = Math.pow(a, b);
		}
		else System.out.print(" illegal operator ");
		System.out.print(b);
		System.out.print(" = ");
		System.out.println(res);
		
		return true;
 	}

	public static void main(String[] args) {
		System.out.println("Problem 6: Simple Arithmetic");
		while (menu());
		System.out.println("Bye");
	}

}
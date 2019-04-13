// Team23
// Problem4
// Intro

import java.util.*;
import java.math.*;

public class Team23Problem4 {

	static Scanner stin = new Scanner(System.in);
	
	static String[] suites = {"H", "S", "D", "C"};
	static String[] cards = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	
	static boolean menu() {
		System.out.print("Enter q to quit: ");
		String line = stin.nextLine().trim();
		if (line.length() == 0) return true;
		if (line.startsWith("q")) return false;
		Scanner sline = new Scanner(line);
		
		int n = sline.nextInt();
		
		ArrayList<String> choice = new ArrayList<String>();
		for (String s : suites) {
			for (String t : cards) choice.add(t.concat(s));
		}
		Collections.shuffle(choice);
		
		for (int i = 0; i < n; i++) {
			System.out.print(choice.get(i));
			System.out.print(" ");
		}
		System.out.println();
		
		return true;
 	}

	public static void main(String[] args) {
		System.out.println("Problem 4: Hand of n cards");
		while (menu());
		System.out.println("Bye");
	}

}
import java.util.Scanner;
import java.lang.Math;

public class Main {
    public static double dist(double x1, double y1, double x2, double y2) {
        return Math.sqrt(Math.abs(x1 - x2) * Math.abs(x1 - x2) + Math.abs(y1 - y2) * Math.abs(y1 - y2));
    }

    public static double binary_search(double x1, double y1, double x2, double y2, double x3) {
        double lo = y1, hi = y2;
        double mid = (lo + hi) / 2.0;
        while (hi - lo >= 1e-10) {
            mid = (lo + hi) / 2.0;
            if (dist(x1, y1, x3, (mid + lo) / 2) + dist(x3, (mid + lo) / 2, x2, y2) < dist(x1, y1, x3, (mid + hi) / 2) + dist(x3, (mid + hi) / 2, x2, y2)) {
                hi = mid;
            }
            else {
                lo = mid;
            }
        }
        return dist(x1, y1, x3, mid) + dist(x3, mid, x2, y2);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            double a = scanner.nextInt();
            double b = scanner.nextInt();
            double c = scanner.nextInt();
            double x = scanner.nextInt();
            x = x / 100.0;

            double ans = 0.0;
            ans = ans + binary_search(0.0, 0.0, b, a, b + c);
            ans = ans + dist(0.0, 0.0, b * x, a * x);
            ans = ans + binary_search(b * x, a * x, b, a, b + c);

            System.out.println(ans);
        }
    }
}
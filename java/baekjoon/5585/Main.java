import java.util.*;
import java.io.*;

class Main {
    public static void solve(int testcase) throws IOException {

    }
    
    public static void solve() throws IOException {
        int[] coins = {500, 100, 50, 10, 5, 1};
        int money = 1000 - Reader.nextInt();
        int answer = 0;
        for (int i = 0; i < coins.length; ++i) {
            answer += money / coins[i];
            money %= coins[i];
        }
        Printer.print(answer);
    }

	public static void main (String[] args) throws IOException {
        solve();
        Printer.close();
	}

    static class Reader {
        public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        public static StringTokenizer st = new StringTokenizer("");

        public static boolean hasNextLine() throws IOException {
            return in.ready();
        }

        public static String nextLine() throws IOException {
            st = new StringTokenizer("");
            return in.readLine();
        }

        public static String next() throws IOException {
            while (!st.hasMoreTokens()) {
                st = new StringTokenizer(in.readLine());
            }
            return st.nextToken();
        }

        public static int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        
        public static long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public static double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }

    static class Printer {
        public static PrintWriter out = new PrintWriter(System.out);

        public static void print(Object object) {
            out.println(object);
        }

        public static void close() throws IOException {
            out.close();
        }
    }
}
import java.util.*;
import java.io.*;

class Main {
    public static final long MOD = 998244353;

    public static long getValueFromStringBuilder(StringBuilder sb) {
        long result = 0;
        for (long i = sb.length() - 1, cur10 = 1; i >= 0; --i, cur10 = (cur10 * 10l) % MOD) {
            result = (result + (cur10 * (sb.charAt((int)i) - '0')) % MOD) % MOD;
        }
        return result;
    }
    
    public static void solve() throws IOException {
        int n = Reader.nextInt();
        StringBuilder a = new StringBuilder(Reader.next());
        StringBuilder b = new StringBuilder(Reader.next());

        for (int i = 0; i < n; ++i) {
            if (a.charAt(i) > b.charAt(i)) {
                char temp = a.charAt(i);
                a.setCharAt(i, b.charAt(i));
                b.setCharAt(i, temp);
            }
        }
        long aValue = getValueFromStringBuilder(a);
        long bValue = getValueFromStringBuilder(b);
        long ans = (aValue * bValue) % MOD;
        Printer.print(ans);
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
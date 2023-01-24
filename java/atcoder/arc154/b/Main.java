import java.util.*;
import java.io.*;

class Main {
    public static boolean isSameLetterCount(StringBuilder s, StringBuilder t) {
        int[] sCount = new int[26];
        int[] tCount = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++sCount[s.charAt(i) - 'a'];
            ++tCount[t.charAt(i) - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (sCount[i] != tCount[i]) {
                return false;
            }
        }
        return true;
    }

    public static void solve() throws IOException {
        int n = Reader.nextInt();
        StringBuilder s = new StringBuilder(Reader.next());
        StringBuilder t = new StringBuilder(Reader.next());

        if (isSameLetterCount(s, t) == false) {
            Printer.print(-1);
            return;
        }

        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int si = mid;
            int ti = 0;
            while (si < n && ti < n) {
                if (s.charAt(si) == t.charAt(ti)) {
                    ++si;
                }
                ++ti;
            }

            if (si == n) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        Printer.print(high + 1);
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
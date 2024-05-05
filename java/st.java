import java.util.StringTokenizer;

public class st {
    public static void main (String[] args) {
        StringTokenizer str = new StringTokenizer("Hello how are you?");
        while (str.hasMoreTokens()) {
            System.out.println(str.nextToken());
        }
    } 
}
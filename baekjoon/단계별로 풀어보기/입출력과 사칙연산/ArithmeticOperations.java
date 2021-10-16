import java.util.*;

public class ArithmeticOperations {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 나머지 연산을 위해 double 형으로 선언
        double A = sc.nextDouble();
        double B = sc.nextDouble();

        System.out.println((int)(A+B));
        System.out.println((int)(A-B));
        System.out.println((int)(A*B));
        System.out.println((int)(A/B));
        System.out.println((int)(A%B));
    }
}
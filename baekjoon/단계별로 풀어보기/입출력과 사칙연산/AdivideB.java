import java.util.*;

public class AdivideB {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double A = sc.nextDouble(); // integer로 입력받을 시 소수점 이하를 버리고 계산
        double B = sc.nextDouble();

        System.out.print(A / B);
    }
}
import java.util.*;
import java.io.*;

public class AplusB {
    public static void main(String[] args) throws IOException {
        int A = System.in.read() - 48; // 아스키코드로 반환하기 때문에 48(아스키코드로 0)을 빼준다
        System.in.read(); // 빈칸
        int B = System.in.read() - 48;
        System.in.read(); // 개행문자

        System.out.print(A + B);
    }
}
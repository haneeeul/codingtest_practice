import java.util.*;
// import java.util.ArrayList;
// import java.util.Arrays;
// import java.util.Comparator;
// import java.util.HashMap;

class Solution {
    public boolean solution(String[] phone_book) {
        // Comparator 클래스란?
        // 정렬 가능한 클래스(== Comparable 이 구현된 클래스)들의 기본 정렬 기준과는 다른 방식으로 정렬하고 싶을 때 사용하는 클래스
        // 주로 익명 클래스로 사용된다. new Comparator<String>() {...}
        Arrays.sort(phone_book, new Comparator<String>() {
            // 내부에 compare() 메서드를 원하는 정렬 기준대로 구현하여 사용한다.
            public int compare(String o1, String o2) {
                return o2.length() - o1.length();
            }
        });

        HashMap<String, String> hm = new HashMap<>();
        for (String str : phone_book) {
            if (hm.get(str) != null) {
                return false;
            }
            for (int i = 1, len = str.length() ; i <= len; i++) {
                hm.put(str.substring(0, i), "");
            }
        };
        return true;
    }
}

// boolean startsWith(String prefix) 사용
/* 
class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        for (int i = 0; i < phone_book.length; ++i) {
            for (int j = i + 1; j < phone_book.length; ++j) {
                if (phone_book[j].startsWith(phone_book[i])) {
                    answer = false;
                    break;
                }
            }
            if (!answer) break;
        }
        return answer;
    }
}

// 결과 : 성공
// 효율성은 통과 안됨.
*/
import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        boolean find = false;
        
        Arrays.sort(participant);
        Arrays.sort(completion);

        /*
        primitive type 배열은
        Dual Pivot Quick Sort를 하고
        시간복잡도 nlogn을 기대할 수 있지만, 최악의 경우 n^2.
        -> primitive type은 comaprator를 지정할 수 없음.

        그 외에 객체, 제네릭 타입들은 comparator를 지정하거나, null인 경우
        Merge sort 또는 TimSort 방법을 사용.
        이는 최악의 경우에도 nlogn을 기대할 수 있다.
        */
        
        for (int i = 0; i < completion.length; ++i) {
            if (!completion[i].equals(participant[i])) {
                answer = participant[i];
                find = true;
                break;
            }
        }
        
        if (!find) answer = participant[participant.length - 1];
        
        return answer;
    }
}
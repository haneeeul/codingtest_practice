import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        ArrayList<Integer> temp = new ArrayList<Integer>();
        int post = arr[0];
        temp.add(post);
        
        for (int i = 1; i < arr.length; ++i) {
            if (post == arr[i]) {
                continue;
            }
            else {
                temp.add(arr[i]);
                post = arr[i];
            }
        }

        int[] answer = temp.stream().mapToInt(i -> i).toArray();

        return answer;
    }
}
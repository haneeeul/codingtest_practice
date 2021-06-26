class Solution {
    public String solution(String phone_number) {
        String answer = "";
        String[] temp = phone_number.split("");
        
        for (int i = 0; i < phone_number.length(); ++i) {
            if (i < phone_number.length() - 4) {
                answer += "*";
            }
            else {
                answer += temp[i];
            }
        }
        
        return answer;
    }
}
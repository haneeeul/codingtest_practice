class Solution {
    public String solution(String s, int n) {
        String answer = "";
        char[] temp = s.toCharArray();
        
        for (int i = 0; i < s.length(); ++i) {
            if (65 <= temp[i] && temp[i] <= 90) {
                if (temp[i] + n > 90) {
                    answer += (char)(temp[i] + n - 26);
                }
                else {
                    answer += (char)(temp[i] + n);
                }
            }
            else if (97 <= temp[i] && temp[i] <= 122) {
                if (temp[i] + n > 122) {
                    answer += (char)(temp[i] + n - 26);
                }
                else {
                    answer += (char)(temp[i] + n);
                }
            }
            else {
                answer += (char)(temp[i]);
            }
        }
        
        return answer;
    }
}

/* 
    n = n % 26;
    for (int i = 0; i < s.length(); i++) {
      char ch = s.charAt(i);
      if (Character.isLowerCase(ch)) {
        ch = (char) ((ch - 'a' + n) % 26 + 'a');
      } 
      else if (Character.isUpperCase(ch)) {
        ch = (char) ((ch - 'A' + n) % 26 + 'A');
      }
      result += ch;
    }

*/

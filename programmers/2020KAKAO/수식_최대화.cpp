import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public long operation(String op, long a, long b) {
        if(op.equals("*"))
            return a*b;
        else if(op.equals("+"))
            return a+b;
        return a-b;
    }

    public long solution(String expression) {
        long answer = 0;
        String[] order = {"*-+","*+-","-+*","-*+","+-*","+*-"};
        ArrayList<String> oprt = new ArrayList<>();
        ArrayList<String> oprd = new ArrayList<>();
        String[] n = expression.split("\\*|\\+|-");
        Collections.addAll(oprt, n);
        
        for(int i=0; i<expression.length(); i++) {
            if('0' > expression.charAt(i) || expression.charAt(i) > '9'){
                oprd.add(expression.substring(i, i+1));
            }
        }
        
        ArrayList<String> n_oprt = new ArrayList<>();
        ArrayList<String> n_oprd = new ArrayList<>();
        
        for(int i=0; i<6; i++) {
            n_oprt.clear();
            n_oprd.clear();
            n_oprt.addAll(oprt);
            n_oprd.addAll(oprd);
            for(int j=0; j<n_oprd.size(); j++) {
                if(n_oprd.get(j).charAt(0) == order[i].charAt(0)) {
                    long temp = operation(n_oprd.get(j), Long.parseLong(n_oprt.get(j)), Long.parseLong(n_oprt.get(j+1)));
                    n_oprd.remove(j);
                    n_oprt.remove(j);
                    n_oprt.add(j, String.valueOf(temp));
                    n_oprt.remove(j+1);
                    j--;
                }
            }
            for(int j=0; j<n_oprd.size(); j++) {
                if(n_oprd.get(j).charAt(0) == order[i].charAt(1)) {
                    long temp = operation(n_oprd.get(j), Long.parseLong(n_oprt.get(j)), Long.parseLong(n_oprt.get(j+1)));
                    n_oprd.remove(j);
                    n_oprt.remove(j);
                    n_oprt.add(j, String.valueOf(temp));
                    n_oprt.remove(j+1);
                    j--;
                }
            }
            for(int j=0; j<n_oprd.size(); j++) {
                if(n_oprd.get(j).charAt(0) == order[i].charAt(2)) {
                    long temp = operation(n_oprd.get(j), Long.parseLong(n_oprt.get(j)), Long.parseLong(n_oprt.get(j+1)));
                    n_oprd.remove(j);
                    n_oprt.remove(j);
                    n_oprt.add(j, String.valueOf(temp));
                    n_oprt.remove(j+1);
                    j--;
                }
            }
            if(answer < Math.abs(Long.parseLong(n_oprt.get(0))))
                answer = Math.abs(Long.parseLong(n_oprt.get(0)));
        }
        
        return answer;
    }
}

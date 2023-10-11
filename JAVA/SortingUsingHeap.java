public class HeapSol {
    public String frequencySort(String s) {
        HashMap<Character, Integer> map=new HashMap<>();
        for(int i=0; i<s.length(); i++){
            if(map.containsKey(s.charAt(i))){
                map.put(s.charAt(i),map.get(s.charAt(i))+1);
            }else{
                map.put(s.charAt(i),1);
            }            
        }
        String ans="";
        PriorityQueue<Character> pq=new PriorityQueue<>((a,b)->(map.get(b)-map.get(a)));
        pq.addAll(map.keySet());
        while(!pq.isEmpty()){
           char ch=pq.poll();
           for(int i=0; i<map.get(ch); i++){
               ans+=ch+"";
           }
        }
        return ans;
    }
}

class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        List<String> res = new ArrayList<String>();
        HashMap<String,Integer> map = new HashMap<String,Integer>();
        for(int i=0;i<cpdomains.length;i++){
            int times = Integer.parseInt(cpdomains[i].split(" ")[0]);
            String[] arr = cpdomains[i].split(" ")[1].split("\\.");
//            System.out.println(arr.length);
            String tmp = arr[arr.length-1];
            for(int j=arr.length-2;j>=0;j--){
                if(map.keySet().contains(tmp)){
                    int k = map.get(tmp);
                    k += times;
                    map.put(tmp,k);
                }else{
                    map.put(tmp,times);
                }
//                System.out.println(j);
                tmp = arr[j] + "." + tmp;
            }
            if(map.keySet().contains(tmp)){
                int k = map.get(tmp);
                k += times;
                map.put(tmp,k);
            }else{
                map.put(tmp,times);
            }
        }
        Iterator<String> it = map.keySet().iterator();
        while(it.hasNext()){
            String k = it.next();
            int p = map.get(k);
            String r = p + " " + k;
            res.add(r);
        }
        return res;
    }
}

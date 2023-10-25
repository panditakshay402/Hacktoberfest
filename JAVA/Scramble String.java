class Solution {
    private final Map<String, Boolean> cache = new HashMap<>();

    public boolean isScramble(String s1, String s2) {
        // Check if this combination is already validated
        // Note that given the nature of problem, separator is not required in key
        final var key1 = s1+s2;
        if (cache.containsKey(key1)) {
            return cache.get(key1);
        }

        // Single character
        if(s1.length() == 1 && s1.equals(s2)) {
            return true;
        }

        // String is already same
        if(s1.equals(s2)){
            return true;
        }

        // Double characters but reversed
        if(s1.length() == 2) {
            return s1.charAt(0) == s2.charAt(1) && s1.charAt(1) == s2.charAt(0);
        }

        // One to one forward comparison
        final var list11 = new int[26];
        final var list21 = new int[26];

        // One to one diagonal comparison
        final var list12 = new int[26];
        final var list22 = new int[26];

        final var key2 = s2+s1;
        for(int i=0; i<s1.length()-1; i++) {
            list11[s1.charAt(i)-'a']++;
            list21[s2.charAt(i)-'a']++;

            list12[s1.charAt(s1.length()-i-1) - 'a']++;
            list22[s2.charAt(s2.length()-i-1) - 'a']++;

            // If forward split is match
            if(Arrays.equals(list11, list21)
                    && isScramble(s1.substring(0, i+1), s2.substring(0, i+1))
                    && isScramble(s1.substring(i+1), s2.substring(i+1))
            ) {
                // Update the forward and reverse map combination
                cache.put(key1, true);
                cache.put(key2, true);
                return true;
            }

            // If diagonal split is match
            if((Arrays.equals(list11, list22) || Arrays.equals(list12, list21))
                    && isScramble(s1.substring(0, i+1), s2.substring(s2.length()-i-1))
                    && isScramble(s1.substring(i+1), s2.substring(0, s2.length()-i-1))
            ) {
                // Update the forward and reverse map combination
                cache.put(key1, true);
                cache.put(key2, true);
                return true;
            }

            // Check for further matches if previous one failed
        }

        // Update the forward and reverse map combination
        cache.put(key1, false);
        cache.put(key2, false);
        return false;
    }
}
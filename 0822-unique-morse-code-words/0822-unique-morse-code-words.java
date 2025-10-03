class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        final String[] morse = {
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
            "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
            "..-", "...-", ".--", "-..-", "-.--", "--.."
        };

        Set<String> transformations = new HashSet<>();
        
        for (final String word : words) {
            StringBuilder transformation = new StringBuilder();
            for (final char c : word.toCharArray()) {
                int index = c - 'a';
                transformation.append(morse[index]);
            }
            transformations.add(transformation.toString());
        }

        return transformations.size();
    }
}
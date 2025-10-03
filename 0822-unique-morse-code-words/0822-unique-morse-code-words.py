class Solution(object):
    def uniqueMorseRepresentations(self, words):
        morse_codes = [
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
            "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
            "..-","...-",".--","-..-","-.--","--.."
        ]
        
        unique_transformations = set()
        
        for word in words:
            full_transformation = "".join(morse_codes[ord(char) - ord('a')] for char in word)
            unique_transformations.add(full_transformation)
            
        return len(unique_transformations)
        
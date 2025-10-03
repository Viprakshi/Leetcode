class Solution(object):
    def carPooling(self, trips, capacity):
         # Max location is 1000. Array of size 1001 to cover indices 0 to 1000.
        timeline = [0] * 1001
        
        for num, start, end in trips:
            timeline[start] += num
            if end <= 1000:
                timeline[end] -= num
        
        current_passengers = 0
        
        for change in timeline:
            current_passengers += change
            if current_passengers > capacity:
                return False
                
        return True
        """
        :type trips: List[List[int]]
        :type capacity: int
        :rtype: bool
        """
        
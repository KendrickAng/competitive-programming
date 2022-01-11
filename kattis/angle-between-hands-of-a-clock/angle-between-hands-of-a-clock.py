class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        hourToAngle = {}
        minToAngle = {}

        # fill hour to angle
        for h in range(1, 13):
            hourToAngle[h] = h * (360 // 12)
        hourToAngle[12] = 0
                
        # fill min to angle
        for minute in range(60):
            minToAngle[minute] = minute * (360 // 60)
            
        # calculate angle of hour hand
        angleHour = hourToAngle[hour]
        angleMin = minToAngle[minutes]
        #print(f"angleHour {angleHour} angleMin {angleMin}")
        
        # add movement of hour hand based on minute
        angleHour += (minutes / 60) * (360 / 12)

        angle1 = abs(angleHour - angleMin)
        angle2 = 360 - angle1

        return min(angle1, angle2)    
"""

make a number to angle dict
make a minutes to angle dict
calc offset of hours hand based on proportion of minute hand to 60
propeoriton based on 360 degrees / 12 
know angle

hourToAngle = {}
minToAngle = {}

# fill hour to angle
for hour in range(1, 13):
    hourToAngle[hour] = hour * (360 / 12)

# fill min to angle
for minute in range(1, 60):
    minToAngle[minute] = minute * (360 / 60)

# calculate angle of hour hand
angleHour = hourToAngle[hour]
angleMin = minToAngle[minutes]

# add movement of hour hand based on minute
angleHour += (minutes / 60) * (360 / 12)

angle1 = abs(angleHour - angleMin)
angle2 = 360 - angle1

return min(angle1, angle2)
"""
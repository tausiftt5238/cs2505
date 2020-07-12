#include <stdio.h>

const int secondsPerMinute = 60;
const int minutesPerHour   = 60;

void sumTimes() {

   int sumOfSeconds = 0;
   int minutes;
   int seconds;
   
   while ( scanf("%d:%d\n", &minutes, &seconds) == 2 ) {        //scanf returns numbers of input it read, so if it doesn't read 2 integers, it's going to stop.
      sumOfSeconds += seconds + secondsPerMinute*minutes;
   }
   
   // This is just simple time calculation
   int totalSeconds = sumOfSeconds % secondsPerMinute;
   sumOfSeconds /= secondsPerMinute;
   int totalMinutes = sumOfSeconds % minutesPerHour;
   int totalHours = sumOfSeconds / minutesPerHour;
   
   printf("Total time: %d:%02d:%02d\n", totalHours, totalMinutes, totalSeconds);
}

int main(){
    sumTimes();
    return 0;
}
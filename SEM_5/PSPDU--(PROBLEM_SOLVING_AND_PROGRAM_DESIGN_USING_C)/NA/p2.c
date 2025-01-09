#include <stdio.h>

char get_grade(float average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'P';
}

int main() {
    float score1, score2, score3, average, highest, lowest;

    printf("Enter the scores for Laboratory Skills, Report Quality, and Project Execution (out of 100):\n");
    scanf("%f %f %f", &score1, &score2, &score3);

    average = (score1 + score2 + score3) / 3;
    highest = (score1 > score2) ? ((score1 > score3) ? score1 : score3) : ((score2 > score3) ? score2 : score3);
    lowest = (score1 < score2) ? ((score1 < score3) ? score1 : score3) : ((score2 < score3) ? score2 : score3);

    printf("\nLab Performance Summary:\n");
    printf("Average Score: %.2f\n", average);
    printf("Highest Score: %.2f\n", highest);
    printf("Lowest Score: %.2f\n", lowest);
    printf("Lab Performance Grade: %c\n", get_grade(average));

    return 0;
}

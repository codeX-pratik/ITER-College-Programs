#include <stdio.h>

int main() {
    int id, num_projects, worker_count = 0;
    float project_rate, total_payroll = 0.0;

    printf("Enter worker details (Enter -1 as Worker ID to stop):\n");

    while (1) {
        printf("\nWorker ID: ");
        scanf("%d", &id);
        if (id == -1) break;

        printf("Project Rate: ");
        scanf("%f", &project_rate);

        printf("Projects Completed: ");
        scanf("%d", &num_projects);

        float earnings = project_rate * num_projects;
        if (num_projects > 10) {
            earnings += 0.2 * project_rate * (num_projects - 10);
        }

        float net_pay = earnings - (0.07 * earnings);
        printf("Worker ID: %d, Net Pay: %.2f\n", id, net_pay);

        total_payroll += net_pay;
        worker_count++;
    }

    if (worker_count > 0) {
        printf("\nTotal Payroll: %.2f\n", total_payroll);
        printf("Average Payment: %.2f\n", total_payroll / worker_count);
    } else {
        printf("No workers entered.\n");
    }

    return 0;
}

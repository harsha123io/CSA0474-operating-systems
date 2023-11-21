#include <stdio.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10
int available[MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int nProcesses, nResources;
int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &nProcesses);

    printf("Enter the number of resources: ");
    scanf("%d", &nResources);

    printf("Enter the available resources for each type:\n");
    for (int i = 0; i < nResources; i++) {
        printf("Resource %d: ", i + 1);
        scanf("%d", &available[i]);
    }
    printf("Enter the maximum resources needed by each process:\n");
    for (int i = 0; i < nProcesses; i++) {
        printf("For process %d:\n", i + 1);
        for (int j = 0; j < nResources; j++) {
            printf("Resource %d: ", j + 1);
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocated resources for each process:\n");
    for (int i = 0; i < nProcesses; i++) {
        printf("For process %d:\n", i + 1);
        for (int j = 0; j < nResources; j++) {
            printf("Resource %d: ", j + 1);
            scanf("%d", &allocation[i][j]);

            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int work[MAX_RESOURCES];
    for (int i = 0; i < nResources; i++) {
        work[i] = available[i];
    }

    int finish[MAX_PROCESSES] = {0};
    int safeSequence[MAX_PROCESSES];
    int count = 0;

    while (count < nProcesses) {
        int found = 0;
        for (int i = 0; i < nProcesses; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < nResources; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == nResources) {
                    for (int k = 0; k < nResources; k++) {
                        work[k] += allocation[i][k];
                    }
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("The system is in an unsafe state!\n");
            return 0;
        }
    }

    printf("The system is in a safe state. Safe sequence: ");
    for (int i = 0; i < nProcesses; i++) {
        printf("%d ", safeSequence[i] + 1);
    }
    printf("\n");

    return 0;
}
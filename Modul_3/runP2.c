#include <stdio.h>
#include <conio.h>

int main() {
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp; // Deklarasi array dan variabel
    float wtavg, tatavg; // Variabel untuk rata-rata waiting time dan turnaround time

    // Meminta user untuk memasukkan jumlah proses
    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    // Loop untuk memasukkan burst time untuk setiap proses
    for (i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    // Sorting burst time dengan metode bubble sort (ascending) agar sesuai dengan algoritma SJF
    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (bt[i] > bt[k]) { // jika burst time ke-i lebih besar dari burst time ke-k
                // Tukar burst time
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Tukar juga nomor proses agar tetap sesuai dengan burst time
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    // Inisialisasi waktu tunggu (wt) dan turnaround time (tat) untuk proses pertama
    wt[0] = wtavg = 0; // Proses pertama tidak memiliki waktu tunggu
    tat[0] = tatavg = bt[0]; // Turnaround time untuk proses pertama sama dengan burst time-nya

    // Loop untuk menghitung waktu tunggu dan turnaround time untuk proses lainnya
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1]; // Waktu tunggu dihitung berdasarkan waktu tunggu dan burst time proses sebelumnya
        tat[i] = tat[i - 1] + bt[i]; // Total turnaround time
        wtavg = wtavg + wt[i]; // Total waktu tunggu untuk rata-rata
        tatavg = tatavg + tat[i]; // Total turnaround time untuk rata-rata
    }

    // Output tabel hasil: menampilkan proses, burst time, waiting time, dan turnaround time
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for (i = 0; i < n; i++) {
        printf("\nP%d\t\t%d\t\t%d\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    // Menampilkan rata-rata waktu tunggu dan turnaround time
    printf("\n\nAverage Waiting Time -- %f", wtavg / n);
    printf("\nAverage Turnaround Time -- %f", tatavg / n);

    getch();
}

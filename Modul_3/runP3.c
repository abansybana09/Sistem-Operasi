#include <stdio.h>

int main() {
    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], max;
    float awt = 0, att = 0, temp = 0;

    // Meminta input jumlah proses 
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Meminta input burst time untuk setiap proses
    for (i = 0; i < n; i++) {
        printf("\nEnter Burst Time for process %d: ", i + 1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i]; // Salin burst time ke array ct untuk nanti
    }

    // Meminta input time slice
    printf("\nEnter the size of time slice: ");
    scanf("%d", &t);

    // Mencari burst time maksimum
    max = bu[0];
    for (i = 1; i < n; i++) {
        if (max < bu[i]) {
            max = bu[i];
        }
    }
// Proses Round Robin
while (1) {
    int done = 1; // Penanda apakah semua proses selesai

    for (i = 0; i < n; i++) {
        if (bu[i] > 0) { // Jika ada proses yang masih memiliki burst time, loop harus lanjut
            done = 0;

            if (bu[i] > t) { // Jika burst time lebih besar dari time slice
                temp += t; // Tambah waktu dengan time slice
                bu[i] -= t; // Kurangi burst time
            } else { // Jika burst time lebih kecil atau sama dengan time slice
                temp += bu[i]; // Tambah waktu dengan sisa burst time
                tat[i] = temp; // Hitung turnaround time
                bu[i] = 0; // Proses selesai
            }
        }
    }

    if (done == 1) // Jika semua proses selesai, keluar dari loop
        break;
}

// Menghitung waiting time dan turnaround time untuk masing-masing proses
for (i = 0; i < n; i++) {
    wa[i] = tat[i] - ct[i]; // Waktu tunggu = turnaround time - burst time asli
    att += tat[i]; // Total turnaround time
    awt += wa[i]; // Total waiting time
}

// Output hasil
printf("\nThe Average Turnaround time is: %f", att / n);
printf("\nThe Average Waiting time is: %f", awt / n);
printf("\n\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");

// Tampilkan detail setiap proses
for (i = 0; i < n; i++) {
    printf("\t%d\t%d\t\t%d\t\t%d\n", i + 1, ct[i], wa[i], tat[i]);
}

return 0;
}

#include <stdio.h>
#include <string.h>
#include <time.h>

struct Salah {
    char name[15];
    char status;
    char time[10];
};
 void displaySummary(struct Salah salahs[],int size){
    int onTime = 0, late = 0, missed = 0;

    printf ("\nDaily Salah Summary\n");
    for (int i=0; i<size; i++) {
    printf ("%s (%s):" , salahs[i].name,salahs[i].time);
    if (salahs[i].status=='T') {
        printf("Performed on Time\n");
        onTime++;
    }
    else if (salahs[i].status=='L') {
        printf ("Performed Late\n");
        late++;
    }
    else if (salahs[i].status=='M') {
        printf ("Missed\n");
        missed++;
    }
    else {
        printf ("Invalid status\n");
    }
}
    printf("\nTotal:\n");
    printf ("On time: %d\n",onTime);
    printf ("Late:%d\n", late);
    printf ("Missed:%d\n",missed);
}
void convertTo24HourFormat (char time12[],int *hour, int *min) {
char period[3];
sscanf(time12,"%d:%d %s",hour,min,period);
if (strcmp(period,"PM")==0 && *hour !=12) *hour +=12;
if (strcmp(period,"AM")==0 && *hour==12) *hour=0;
}
void displayQuote() {
    printf("\nWelldone!\n");
    printf("\nSalah is the key to Jannah.\n");
}
void checkUpcomingSalahs(struct Salah salahs[], int size) {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    int currentHour = local->tm_hour;
    int currentMin = local->tm_min;

    printf("\nUpcoming Salah Reminders\n");
    int found = 0;

    for (int i = 0; i < size; i++) {
        int salahHour, salahMin;
        convertTo24HourFormat(salahs[i].time, &salahHour, &salahMin);

        if (salahHour > currentHour || (salahHour == currentHour && salahMin > currentMin)) {
            printf("Reminder: %s at %s.\n", salahs[i].name, salahs[i].time);
            found = 1;
        }
    }

    if (!found) printf("All Salahs for today are completed.\n");
}

int main() {
    char userName[50];
    struct Salah salahs[5] = {
        {"Fajr", ' ', "05:30 AM"},
        {"Zuhr", ' ', "12:30 PM"},
        {"Asr", ' ', "03:45 PM"},
        {"Maghrib", ' ', "06:20 PM"},
        {"Isha", ' ', "07:45 PM"}
    };

    printf("Enter your name: ");
    scanf("%s", userName);


    printf("\nEnter Salah status:\n");
    printf("T - Performed on time, L - Performed late, M - Missed\n");
    for (int i = 0; i < 5; i++) {
        printf("%s (%s): ", salahs[i].name, salahs[i].time);
        scanf(" %c", &salahs[i].status);
    }

    displaySummary(salahs, 5);
    displayQuote ();
    checkUpcomingSalahs(salahs, 5);

    return 0;
}

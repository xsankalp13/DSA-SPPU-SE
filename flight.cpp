#include <iostream>
#include <cstring>
using namespace std;
int am[10][10]; char city_index[10][10];
void initialize(int am[10][10], char city_index[10][10]) {
for (int i = 0; i < 10; i++) {
strcpy(city_index[i], "xx");
for (int j = 0; j < 10; j++) {
am[i][j] = 0;
}
}
}
int create(int am[10][10], char city_index[10][10]) {
int city_count = 0, j, si, di, wt;
char s[10], d[10], c;
do {
cout << "\n\tEnter Source City : ";
cin >> s;
cout << "\n\tEnter Destination City : ";
cin >> d;
for (j = 0; j < 10; j++) {
if (strcmp(city_index[j], s) == 0)
break;
}
if (j == 10) {
strcpy(city_index[city_count], s);
city_count++;
}
for (j = 0; j < 10; j++) {
if (strcmp(city_index[j], d) == 0)
break;
}
if (j == 10) {
strcpy(city_index[city_count], d);
city_count++;
}
cout << "\n\tEnter Distance From " << s << " To " << d << ": ";
cin >> wt;
for (j = 0; j < 10; j++) {
if (strcmp(city_index[j], s) == 0)
si = j;
if (strcmp(city_index[j], d) == 0)
di = j;
}
am[si][di] = wt;
cout << "\n\tDo you want to add more cities? (y/n): ";
cin >> c;
} while (c == 'y' || c == 'Y');
return city_count;
}
void display(int am[][10], char city_index[][10], int city_count) {
int i, j;
cout << "\n\tDisplaying Adjacency Matrix:\n\t";
for (i = 0; i < city_count; i++) {
cout << "\t" << city_index[i];
}
cout << "\n";
for (i = 0; i < city_count; i++) {
cout << "\t" << city_index[i];
for (j = 0; j < city_count; j++) {
cout << "\t" << am[i][j];
}
cout << "\n";
}
}
int main() {
int am[10][10];
char city_index[10][10];
int n, city_count;
char c;
initialize(am, city_index);
do {
cout << "\n\t*** Flight Main Menu *****";
cout << "\n\t1. Create \n\t2. Adjacency Matrix\n\t3. Exit";
cout << "\n\t.....Enter your choice: ";
cin >> n;
switch (n) {
case 1:
city_count = create(am, city_index);
break;
case 2:
display(am, city_index, city_count);
break;
case 3:
return 0;
}
cout << "Do you want to continue :";
cin >> c;
}
while(c=='y'||c=='Y');
}
#define INF 1000000007
#include <cstdio>
#include <cstring>
#include <windows.h>

int main() {
	char nama[1000];
	char nim[3];
	int bykPeserta;
	printf("Nama Anda                   : "); gets(nama);
	printf("Dua Digit Terakhir Nim Anda : "); scanf("%s", nim);
	printf("Banyak Peserta dalam Kelas  : "); scanf("%d", &bykPeserta);
	
	printf("\nTerdiri dari Karakter Huruf :\n");
	for (int i = 0; i < strlen(nama); i++) {
		if (isalpha(nama[i])) 
			printf("%c ", nama[i]);
	}
	printf("\n");
	
	strcpy(nama, strupr(nama));
	printf("Penjumlahan Nilai ASCII Karakter Huruf :\n");
	printf("(");
	int alphaCounter = 0;
	int total = 0;
	for (int i = 0; i < strlen(nama); i++) {
		if (isalpha(nama[i])) {
			if (alphaCounter > 0) printf("+ ");
			int value = (int)(nama[i]-'A'+1);
			printf("%d ", value);
			alphaCounter++;
			total += value;
		}
	}
	int nim_i = atoi(nim);
	printf(") = %d * %s = %d mod %d = %d", total, nim, total*nim_i, bykPeserta, (total*nim_i) % bykPeserta);
	
	return 0;
}

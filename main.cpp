#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;

int file_size_from_path(const char *path){

	if(path == NULL) return -1;

	FILE *text;
	text = fopen(path, "r");

	int count = 0;
	int i;
	while(i != EOF){
		i = fgetc(text);
		count++;
	}

	fclose(text);
	return count;
}

int file_size_from_file(FILE *f){

	int count = 0;
	int check;
	int i;
	for(i = 0; ; i++){
	fseek(f, i, 0);
	check = fgetc(f);
	if(check == EOF) break;
	}
	count = ftell(f);
	return count;
}

int main() {

	char path[30];
	char *p = path;
	printf("Podaj nazwe pliku");
	scanf("%29s", path);

	FILE *fp;
	fp = fopen(path, "r");

	if(fp == NULL){
		printf("Error");
		exit(1);
		return 1;
	}

	int count1 = file_size_from_path(p);
	int count2 = file_size_from_file(fp);
	if(count1 == count2){
		printf("Rozmiar pliku wynosi %d bajtow", count1);
	}

	ofstream zapis("log.txt");
	zapis<<count1 << " " << count2;
	zapis.close();

	fclose(fp);
	return 0;
}

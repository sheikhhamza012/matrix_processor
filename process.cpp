#include <stdio.h>
#include <stdlib.h.>
#include<ctype.h>
#include<Windows.h>
#define clr(){system("cls");head();}
int power(int x, int y){
	int ans;
	if (y == 1)
		return x;
	return(x * power(x, y - 1));

}
float* invrs(int *, int);
int *adjoint(int *, int, int);
int *minor(int *, int, int);
int det(int*, int, int);
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void inrc(int*r, int*c){
	char size[100];;
	printf("enter row and column(rxc)in exact format for matrix: ");
	scanf("%s", size);
	sscanf(size, "%dx%d", r, c);
	fflush(stdin);

}
void printmat(int *, int, int);
void inmat(int *, int, int);
void writef(int *, int, int, int);
int* readf(int, int*, int*, int*);
int lastid();
int *transpose(int*, int*, int*);
int *bopp(int *, int, int, int*, int, int, char);
int* smul(int*, int, int);
void head();
int *carr(int, int);
void linear();
int main(){
	int choice, r1 = 0, r = 0, c = 0, c1 = 0, r2 = 0, c2 = 0, *mat1, *mat2, *mat3; char size[100]; float *o;
	head();
	printf("what do you wanna do?(enter the coresponding number)\n\n1)Addition between two matrices\n\n2)subtraction between two\n\n3)transpose of a matrix\n\n4)Multiplication between two matrices\n\n5)multiplication of a matrix and a scalar number\n\n6)Determinant of a matrix\n\n7)inverse of a matrix\n\n8)solving the linear equation\n\n9)History ");
	printf("\n+----------------+\n| Insert:\t |\n+----------------+");
	gotoxy(10, 23);
	scanf("%d", &choice);
	clr();
	if (choice == 1){
		printf("\nADDITION BETWEEN MATRICES\n------------------------------\n");
		inrc(&r1, &c1);
		mat1 = carr(r1, c1);
		inmat(mat1, r1, c1);
		printf("\nMatrix 1 is: \n\n"); printmat(mat1, r1, c1);
		inrc(&r2, &c2);
		mat2 = carr(r2, c2);
		inmat(mat2, r2, c2);
		printf("\nMatrix 2 is: \n\n"); printmat(mat2, r2, c2);
		mat3 = bopp(mat1, r1, c1, mat2, r2, c2, '+');
		clr();
		printf("\nADDITION BETWEEN MATRICES\n------------------------------\n");
		printmat(mat1, r1, c1); printf("\n\t+\n\n"); printmat(mat2, r2, c2); printf("\n\t=\n\n"); printmat(mat3, r1, c1);
		r = r1; c = c1;
		writef(mat3, r, c, choice);
		free(mat1);	free(mat2);	free(mat3);

	}
	else if (choice == 2){
		printf("\nSUBTRACTION BETWEEN MATRICES\n------------------------------\n");
		inrc(&r1, &c1);
		mat1 = carr(r1, c1);
		inmat(mat1, r1, c1);
		printf("\nMatrix 1 is: \n\n"); printmat(mat1, r1, c1);
		inrc(&r2, &c2);
		mat2 = carr(r2, c2);
		inmat(mat2, r2, c2);
		printf("\nMatrix 2 is: \n\n"); printmat(mat2, r2, c2);
		mat3 = bopp(mat1, r1, c1, mat2, r2, c2, '-');
		clr();
		printf("\nADDITION BETWEEN MATRICES\n------------------------------\n");
		printmat(mat1, r1, c1); printf("\n\t-\n\n"); printmat(mat2, r2, c2); printf("\n\t=\n\n"); printmat(mat3, r1, c1);
		r = r1; c = c1;
		writef(mat3, r, c, choice);
		free(mat1);	free(mat2);	free(mat3);

	}
	else if (choice == 3){
		printf("\TRANSPOSE OF MATRIX\n");
		inrc(&r1, &c1);
		mat1 = carr(r1, c1);
		inmat(mat1, r1, c1);
		printf("\nMatrix 1 is: \n\n"); printmat(mat1, r1, c1); printf("\n\nTranspose of matrix: \n\n");
		mat3 = transpose(mat1, &r1, &c1); printmat(mat3, r1, c1);
		r = r1; c = c1;
		writef(mat3, r, c, choice);
		free(mat1); free(mat3);

	}
	else if (choice == 4){
		printf("\nMULTIPLICATION BETWEEN MATRICES\n------------------------------\n");
		inrc(&r1, &c1);
		mat1 = carr(r1, c1);
		inmat(mat1, r1, c1);
		printf("\nMatrix 1 is: \n\n"); printmat(mat1, r1, c1);
		inrc(&r2, &c2);
		mat2 = carr(r2, c2);
		inmat(mat2, r2, c2);
		printf("\nMatrix 2 is: \n\n"); printmat(mat2, r2, c2);
		mat3 = bopp(mat1, r1, c1, mat2, r2, c2, '*');
		clr();
		printf("\MULTIPLICATION BETWEEN MATRICES\n------------------------------\n");
		printmat(mat1, r1, c1); printf("\n\t*\n\n"); printmat(mat2, r2, c2); printf("\n\t=\n\n"); printmat(mat3, r1, c2);
		r = r1; c = c2;
		writef(mat3, r, c, choice);
		free(mat1);	free(mat2);	free(mat3);

	}
	else if (choice == 5){
		int k = 0;
		printf("\nSCALAR MULTIPLICATION\n------------------------------\n");
		inrc(&r1, &c1);
		mat1 = carr(r1, c1);
		inmat(mat1, r1, c1);
		printf("\nMatrix 1 is: \n\n"); printmat(mat1, r1, c1);
		printf("\nEnter a number 'k': "); scanf("%d", &k); fflush(stdin);
		mat3 = smul(mat1, r1*c1, k);
		clr(); printf("\nSCALAR MULTIPLICATION\n------------------------------\n");
		printf("MATRIX : \n\n"); printmat(mat1, r1, c1); printf("\n\t*\n"); printf("\t%d\n\t=\n\n", k);
		printmat(mat3, r1, c1);
		r = r1; c = c1;
		writef(mat3, r, c, choice);
		free(mat1); free(mat3);
	}
	else if (choice == 6){
		printf("\nDETERMINANT OF MRICEX\n------------------------------\n");
		inrc(&r1, &c1);
		mat1 = carr(r1, c1);
		inmat(mat1, r1, c1);
		clr();
		printf("\nDETERMINANT OF MRICEX\n------------------------------\n");
		printf("\nMatrix is: \n\n"); printmat(mat1, r1, c1); printf("\n\Deteminent of matrix: \n\n");
		int d = det(mat1, r1, c1); printf("%d\n", d);
		r = r1; c = c1;
		writef(mat1, r, c, choice);
		free(mat1);
	}
	else if (choice == 7){
		printf("\nINVERSE OF MATRIX\n------------------------------\n");
		inrc(&r1, &c1);
		mat1 = carr(r1, c1);
		inmat(mat1, r1, c1);
		clr();		printf("\nINVERSE OF MATRIX\n------------------------------\n");
		printf("\nMatrix is: \n\n"); printmat(mat1, r1, c1); printf("\n\Inverse of matrix: \n\n");
		o = invrs(mat1, c1);
		r = r1; c = c1;
		for (int i = 0; i < c; i++){
			printf("\n");
			for (int j = 0; j < c; j++){
				printf("%8.2f", o[i*c + j]);
			}
		}
		writef(mat1, r, c, choice);
		free(mat1); free(o);
	}
	else if (choice == 8){
		printf("\nSOLUTION OF LINEAR EQUATIONS\n------------------------------\n");
		linear();
	}
	else if (choice == 9){
		printf("\nHistory(ansers)\n------------------------------\n");
		int *p, n = lastid(), id, row, col, cho;
		printf("Enter a value from(1-%d) dont get out of limit: ", n);
		scanf("%d", &id);
		fflush(stdin);
		p = readf(id, &row, &col, &cho);
		clr();
		printf("\nHistory(ansers)\n------------------------------\n");
		printf("\noperation peerformed was '%dth' in the list: \n", cho);
		printmat(p, row, col);
		if (cho == 6){
			printf("\nans was(determinant) : %d\n", det(p, row, col));
		}
		else if (cho == 7){
			printf("iverse was: \n\n");
			o = invrs(p, col);
			for (int i = 0; i < col; i++){
				printf("\n");

				for (int j = 0; j < col; j++){
					printf("%7.2f ", o[i*col + j]);
				}
				//printf("\n\t\t");
			}free(o);
		}
		free(p);
	}
	else{
		printf("\nnot a valid value\n");
	}

	printf("\nwanna do calculations again (y for yes)?");
	fflush(stdin);
	while (getchar() == 'y' || getchar() == 'Y'){
		system("cls");
		main();
	}
	exit(0);
}
void printmat(int *p, int r, int c){
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			printf("%7d", p[i*c + j]);
		}
		printf("\n");
	}
}
void inmat(int *p, int c, int r){
	for (int i = 0; i < (r*c); i++){
		scanf("%d", &p[i]);
		fflush(stdin);
	}
}
int lastid(){
	int id = 0; char ln[500];
	FILE *fr = fopen("matrix.txt", "r");
	while (!feof(fr)){
		fgets(ln, sizeof(ln), fr);
		sscanf(ln, "ID: %d", &id);
	}
	fclose(fr);
	return id;
}
void writef(int *p, int r, int c, int choice){
	FILE *fa = fopen("matrix.txt", "a"); int id = lastid();
	if (fa == NULL){
		printf("\nfile not found\n");
		exit(-1);
	}
	fprintf(fa, "ID: %d\nORDER: %dx%d\nCHOICE: %d\nVAL: ", ++id, r, c, choice);
	for (int i = 0; i < r*c; i++){
		fprintf(fa, "%d ", p[i]);
	}
	fprintf(fa, "\n");
	fclose(fa);
}
int* readf(int id, int* r, int* c, int* choice){
	FILE*fr = fopen("matrix.txt", "r");
	char ln[500], *tok; int k = 0, pi = 0, *p, chk = 0;
	if (fr == NULL){
		printf("\ninternal err: file not found\n");
		system("pause");
		exit(-2);
	}
	while (!feof(fr)){
		fgets(ln, sizeof(ln), fr);
		sscanf(ln, "ID: %d\n", &k);
		memset(ln, 0, sizeof(ln));
		if (k == id){
			printf("found\n");
			fscanf(fr, "ORDER: %dx%d\n", r, c);
			fscanf(fr, "CHOICE: %d\n", choice);
			fgets(ln, sizeof(ln), fr);
			chk = 1;
			break;
		}
	}
	if (chk == 0){
		printf("\ninternal error: id did not match with database give the right key\n");
		system("pause");
		exit(-5);
	}
	p = (int*)calloc(sizeof(int), sizeof(int)*(*r)*(*c));
	printf("\n");
	tok = strtok(ln, " ");
	tok = strtok(NULL, " ");
	while (tok != NULL){
		p[pi++] = atoi(tok);
		tok = strtok(NULL, " ");
	}
	fclose(fr);
	return p;
}
int *bopp(int *p, int r1, int c1, int* q, int r2, int c2, char opp){
	int *a = (int*)calloc(sizeof(int), sizeof(int)*r1*c1);
	if (opp == '+' || opp == '-'){
		if (r1 == r2&&c1 == c2){
			for (int i = 0; i < r1*c1; i++)
				opp == '+' ? a[i] = p[i] + q[i] : a[i] = p[i] - q[i];
		}
		else{
			printf("matrices not eligible to have '%c' performed on them\n", opp);
			system("pause");
			exit(-3);
		}
	}
	else if (opp == '*'){
		if (c1 == r2){
			int sum = 0;
			for (int i = 0; i < r1; i++){
				for (int j = 0; j < c2; j++){
					sum = 0;
					for (int k = 0; k < r2; k++)
						sum = sum + p[i * c1 + k] * q[k * c2 + j];
					a[i * c2 + j] = sum;
				}
			}
		}
		else{
			printf("matrices not eligible to have '%c' performed on them\n", opp);
			system("pause");
			exit(-4);
		}
	}

	return a;
}
int* smul(int*p, int a, int k){
	int*q = (int*)calloc(sizeof(int), sizeof(p));
	for (int i = 0; i <a; i++)
		q[i] = p[i] * k;
	return q;
}
int* transpose(int*p, int *r, int *c){
	int *a = (int*)calloc(sizeof(int), sizeof(p)), k;
	for (int i = 0; i < *c; i++){
		for (int j = 0; j < *r; j++){
			a[i*(*r) + j] = p[i + j*(*c)];
		}
	}
	int s = 0;
	s = *r; *r = *c; *c = s;
	return a;


}
int *carr(int r, int c){
	int *p = (int*)calloc(2, sizeof(int)*(r)*(c));
	return p;
	free(p);
}
void head(){
	char dec[] = "----------------------------------------------------------------------------";
	printf("+%s+\n|\t\t\t\tMatrix processor\t\t\t     |\n+%s+\n", dec, dec);
}
int *minor(int *p, int a, int c){
	int *q = (int*)calloc(sizeof(int), sizeof(int)*(c - 1)*(c - 1));
	for (int i = 0, b = 0; i, b < c; i++, b++){
		for (int k = 0; k < c; k++){
			if (a == (i)*c + k){
				b++;
				break;
			}
		}
		for (int j = 0, k = 0; j, k < c; j++, k++){
			if (a%c == k){
				j--;
				continue;
			}
			q[(i)*(c - 1) + (j)] = p[(b)*c + (k)];
		}
	}
	return q;
}
int det(int*p, int c, int r){
	int d = 0;
	if (c != r){
		printf("\ndeterminant is only valid on squar matrices\n");
		system("pause");
		exit(-5);
	}
	if (c == 2){
		return ((p[0] * p[3]) - (p[1] * p[2]));

	}
	for (int i = 0; i < c; i++)
		d += power(-1, i + 2)*p[i] * det(minor(p, i, c), c - 1, r - 1);
	return d;
}
int *adjoint(int *p, int r, int c){
	if (r != c){
		printf("\nsorry take adjoint of a sq matrix\n");
		system("pause");
		exit(-6);
	}
	int *l = (int *)calloc(sizeof(int), sizeof(int)*r*c), *q = (int *)calloc(sizeof(int), sizeof(int)*r*c);
	if (r == 2 && c == 2){
		q[0] = p[3]; q[1] = (-1 * p[1]); q[2] = (-1 * p[2]); q[3] = p[0];
		return q;
	}
	for (int i = 0; i < r*c; i++){
		q[i] = power(-1, i + 2)*det(minor(p, i, c), c - 1, c - 1);
	}
	for (int i = 0; i < c; i++){
		for (int j = 0; j < r; j++){
			l[i*(r)+j] = q[i + j*(c)];
		}
	}
	free(q);
	return l;
}
float* invrs(int *p, int c){
	float d; int *q; float *ans = (float*)calloc(sizeof(int), sizeof(int)*c*c);
	q = adjoint(p, c, c);
	d = det(p, c, c);
	if (d==0){
		printf("\ninverse of this matrix doesnt exist\n");
		system("pause");
		exit(-6);
	}
	d = 1 / d;
	for (int i = 0; i < c; i++){
		printf("\t");
		for (int j = 0; j < c; j++){
			ans[i*c + j] = q[i*c + j] * d;
		}
	}
	return ans;
}
void linear(){
	int   x, m = 1, n = 6, a[9]; float *o, b[3], w[3], sum = 0, d;
	for (int i = 0; i < 3; i++){
		printf("(      )x + (      )y + (      )z = (      )\n");
		for (int j = 0; j < 4; j++){
			gotoxy(m, n + i);
			scanf("%d", &x);
			if (j<3){
				a[i*3 + j] = x;
			}
			else if (j >= 3 && j < 4){
				b[i] =(float) x;
			}
			m += 12;
		}
		//n += 1;
		m = 1;
	}
	o = invrs(a, 3);
	printf("\nmatrix A: \n");
	printmat(a, 3, 3);
	printf("\nMatrix B: \n");
	for (int i = 0; i < 3; i++){
			printf("%7.0f ", b[i]);
		printf("\n");
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 1; j++){
			sum = 0;
			for (int k = 0; k < 3; k++){
				sum = sum + o[i * 3 + k] * b[k];
			}
			w[i] = sum;
		}
	}
	printf("\n");
	printf("Matrix X: \n");
	for (int i = 0; i < 3; i++){
			printf("%7.2f ", w[i]);
		printf("\n");
	}
	printf("\n +----------------------------------------------+\n | x: %7.2f  ||  y:%7.2f  ||  z:%7.2f     |\n +----------------------------------------------+\n",w[0],w[1],w[2]);
}
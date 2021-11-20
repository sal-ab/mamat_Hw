#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void fill_hist(int hist [][10], int student_num,FILE *grades);
int cal_median(int hist [][10], int students_mid);
int count_students (int hist [][10], FILE *grades,FILE *stats);
double cal_pass_rate (int hist[][10], int student_num);
int cal_max (int hist [][10]);
int cal_min (int hist[][10]);
double grades_avg (int hist[][10] , int student_num);




int main(int argc, char *argv[]) {
    if (argc < 1) {
        fprintf(stderr, "Error\n");
        return 1;
    }

   FILE *grades;
   FILE *stats;
   grades = fopen (argv[1],"r");
   stats = fopen(argv[2],"w");

   if ((stats == NULL)||(grades == NULL)){
   return 1;
   }
   
   
   
   int hist [10][10] = {{0}};
   int student_num = count_students(hist,grades,stats);
   fill_hist(hist,student_num,grades);
   double avg = grades_avg (hist,student_num);
   int median = cal_median(hist,(student_num+1)/2);
   int min_grade = cal_min(hist);
   int max_grade = cal_max(hist);
   double pass_rate = cal_pass_rate (hist,student_num);
   

   fprintf (stats, "num of students = %d\n",student_num);
   fprintf (stats, "avg = %.3f\n",avg);
   fprintf (stats, "the median is - %d\n",median);
   fprintf (stats, "max grade = %d, min grade = %d\n",max_grade,min_grade);
   fprintf (stats, "pass rate = %.2f%%\n",pass_rate);

   int i=0,j=0;
   for (i = 0; i<10;i++){
	   fprintf (stats,"%d", hist[i][0]);
	   for (j=1; j<10;j++){
		   fprintf (stats," %d", hist [i][j]);
	   }
        fprintf (stats,"\n");
        
        
      }  
        
   fclose(stats);
   fclose(grades);
    return 0;

}





double grades_avg (int hist[][10] , int student_num){
	int i=0, j=0,sum=0;
	for (i = 0; i<10;i++){
		for (j=0; j<10;j++){
			if (hist[i][j] > 0){
				if (j==9) {
					sum = sum+ (i+1)*10*(hist[i][j]);
				}
				else{
					sum = sum + (i*10+j+1)*(hist[i][j]);
		}

	}
	
}

}
return (((double)sum)/student_num);
}





int cal_median(int hist [][10], int students_mid){
	int i=0,j=0,counter=0;
	for (i = 0; i<10;i++){
			for (j=0; j<10;j++){
				counter = counter + hist[i][j];
				if (counter >= students_mid){
					if (j==0) {
						return (i+1)*10;
					}
					else{
						return (i*10+j+1);
					}
                }
			}
		}
	return 0;
}









int cal_min (int hist[][10]){
	int i=0,j=0;
	for (i = 0; i<10;i++){
			for (j=0; j<10;j++){
				if (hist[i][j]>0){
					if (j==0) {
						return (i+1)*10;
					}
					else{
						return (i*10+j+1);
					}
                }
			}
		}
	return 0;
}






int cal_max (int hist [][10]){
	int i=0,j=0,max=0;
	for (i = 0; i<10;i++){
			for (j=0; j<10;j++){
				if (hist[i][j] > 0){
					if (j==9) {
						max = (i+1)*10;
					}
					else{
						max =(i*10+j+1);
					}
                }
			}
		}
	return max;
}







double cal_pass_rate (int hist[][10], int student_num){
	int i=0,j=0,count=0;
	for (i = 5; i<10;i++){
		for (j=0; j<10;j++){
			count = count + hist[i][j];
		}
	}
	count = count + hist[4][4]+hist[4][5]+hist[4][6]+hist[4][7]+hist[4][8]+hist[4][9];
	return (((double)count)/student_num)*100;
}









int count_students (int hist [10][10], FILE *grades ,FILE *stats){
        char num;
        int student_num=0;
		for (num = getc(grades); num != EOF; num = getc(grades)){
        if (num == '\n'){
		student_num = student_num + 1;}	
	}
		
	return student_num;

}






void fill_hist(int hist [10][10], int student_num,FILE *grades){
    int i=0,n=0;
    int *arr;
    arr = (int*)malloc(sizeof(int)*student_num);
    fseek (grades, 0 ,SEEK_SET);
    for (i=0; i<student_num;i++){
    	fscanf(grades, "%d",arr+i);
    	}
    	for (i=0; i<student_num;i++){
    	n=arr[i];
    		if (n%10==0){
			hist[n/10-1][9]++;
		}else {
			hist [n/10][n%10-1]++;
	    }
	    }
	    free(arr);
	}
    
 





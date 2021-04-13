#include <stdio.h>
#include <string.h>

typedef struct CVaccount{
    char name[50];
    float experience;
    char university[50];
    float uniCGPA;
    char school[30];
    float schlCGPA;
    char major[20];
    float weight;
}acc;


void bestNofCandidates(acc x[]);
void displayAllCandidates(int n, acc x[]);

float updateWeightForUniversity(char x[]);
float updateWeightForUniversityCGPA(float gpa);
float updateWeightForHighSchoolCGPA(float gpa);
float updateWeightForExperience(float y);


int main(){

    int n;

    printf("========Welcome to HR Organiser========\n\nHow may applicants' info do you want to input?: ");
    scanf("%d",&n);

    acc acclist[n];

    for(int i=0;i<n;i++)
        acclist[i].weight = 0;

    for(int i=0;i<n;i++){
        printf("%d applicant data input:\n\n",i+1);

        printf("Enter Name: ");
        scanf("%s",&acclist[i].name);

        printf("Enter University: ");
        scanf("%s",&acclist[i].university);

        acclist[i].weight += updateWeightForUniversity(acclist[i].university);

        printf("Enter University CGPA: ");
        scanf("%f",&acclist[i].uniCGPA);

        acclist[i].weight += updateWeightForUniversityCGPA(acclist[i].uniCGPA);

        printf("Enter Degree Major:");
        scanf("%s",&acclist[i].major);

        printf("Enter HighSchool: ");
        scanf("%s",&acclist[i].school);

        printf("Enter HighSchool CGPA: ");
        scanf("%f",&acclist[i].schlCGPA);

        acclist[i].weight += updateWeightForHighSchoolCGPA(acclist[i].schlCGPA);

        printf("Enter Experience in years:");
        scanf("%d",&acclist[i].experience);

        acclist[i].weight += updateWeightForExperience(acclist[i].experience);
    }


    int check;
    printf("DO YOU WANT TO DISPLAY BEST CANDIDATES(0) OR ALL CANDIDATES(1)?");
    scanf("%d",&check);
    if(check)
        displayAllCandidates(n,acclist);
    else
        bestNofCandidates(acclist);

return 0;
}








float updateWeightForUniversity(char x[]){
        float weight;
        if((strcmp(x,"University of Dhaka")==0) || (strcmp(x,"Bangladesh University of Engineering and Technology")==0) || (strcmp(x,"DU"==0)) || (strcmp(x,"BUET")==0))
            weight=3;
        else if((strcmp(x,"Military Institute of Science and Technology")==0) || (strcmp(x,"Ahsanullah University of Science and Technology")==0) || (strcmp(x,"Jahangirnagar University")==0) || (strcmp(x,"Rajshahi University of Engineering and Technology")==0) || (strcmp(x,"Khulna University of Engineering and Technology")==0) || (strcmp(x,"Chittagong University of Engineering and Technology")==0) || (strcmp(x,"MIST")==0) || (strcmp(x,"AUST")==0) || (strcmp(x,"JU")==0) || (strcmp(x,"RUET")==0) || (strcmp(x,"KUET")==0) || ((strcmp(x,"CUET")==0)))
            weight=2.5;
        else if((strcmp(x,"North South University")==0) || (strcmp(x,"BRAC University")==0) || (strcmp(x,"NSU"==0)|| strcmp(x,"BRAC U"==0)))
            weight=2;
        else if((strcmp(x,"Independent University of Bangladesh")==0) || (strcmp(x,"American Independent University of Bangladesh")==0) || (strcmp(x,"IUB")==0 || strcmp(x,"AIUB")==0))
            weight=1.5;
        else
            weight=1;

return weight;
}



float updateWeightForUniversityCGPA(float gpa){
    float weight;
    return weight = gpa*(3/5.0);
}


float updateWeightForHighSchoolCGPA(float gpa){
        float weight;
       return weight = gpa*(1/5.0);
}


float updateWeightForExperience(float y){
        float weight;

        if(y>0 && y<=1)
            weight= 0.5;
        else if(y>1 && y<=2)
            weight= 1;
        else if(y>2 && y<=3)
            weight= 1.5;
        else if(y>3 && y<=4)
            weight= 2;
        else if(y>4 && y<=5)
            weight= 2.5;
        else if(y>5)
            weight= 3;
        else
            weight=0;

return weight;
}




void bestNofCandidates(acc x[]){
    int a;
    acc temp;
    printf("How many candidates do you want?:");
    scanf("%d",&x);

    FILE *fp;
    fp = fopen("best_candidates.txt","w");

    for(int i=1;i<a;++i){
		for(int j=0;j<(a-i);++j){
			if(x[j].weight>x[j+1].weight)
			{
				temp=x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
			}
		}
    }

    if(fp!=NULL){
        for(int i=0;i<a;i++)
            fprintf(fp,"%d. Name: %s, Major: %s, Experience: %f, University: %s, UniCGPA: %0.2f, School: %s, SchoolCGPA: %f \n", i+1, x[i].name, x[i].major, x[i].experience, x[i].university, x[i].uniCGPA, x[i].school, x[i].schlCGPA);
    }

    printf("\n\nBest Candidates' Info are saved in the best_candidates.txt file. in this folder.");
    fclose(fp);
}





void displayAllCandidates(int n, acc x[]){

    FILE *fp;
    fp = fopen("all_candidates.txt","w");

    if(fp!=NULL){
        for(int i=0;i<n;i++)
            fprintf(fp,"%d. Name: %s, Major: %s, Experience: %f, University: %s, UniCGPA: %0.2f, School: %s, SchoolCGPA: %f \n", i+1, x[i].name, x[i].major, x[i].experience, x[i].university, x[i].uniCGPA, x[i].school, x[i].schlCGPA);
    }


    printf("\n\nAll Candidates' Info are saved in the all_candidates.txt file. in this folder.");
    fclose(fp);
}



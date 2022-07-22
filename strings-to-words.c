

#include <stdio.h>
#include <string.h>

int main()
{   int word_count,char_count,j,i;
    char s[200],s2[199][199],temp[199];
    fgets(s,200,stdin);
    s[strcspn(s,"\n")]='\0';
    i=0;
    word_count=0;
    while (s[i]!='\0'){
        if ((s[i]>=65 && s[i]<=90)||(s[i]>=97&&s[i]<=122)){
            char_count+=1;
        }
        else{
            if (((s[i-1]>=65 && s[i-1]<=90)||(s[i-1]>=97&&s[i-1]<=122))){
            word_count+=1;
            for (j=char_count;j>0;j--){
                s2[word_count][char_count-j]=s[i-j];
            }
            char_count=0;
            }
        }
        i++;
        if(s[i]=='\0'&&((s[i-1]>=65 && s[i-1]<=90)||(s[i-1]>=97&&s[i-1]<=122))){
            word_count+=1;
            for (j=char_count;j>0;j--){
                s2[word_count][char_count-j]=s[i-j];
            }
            char_count=0;
        }
    }
    for(i=0;i<=word_count;i++)
      for(j=i+1;j<=word_count;j++){
         if(strcmp(s2[i],s2[j])>0){
            strcpy(temp,s2[i]);
            strcpy(s2[i],s2[j]);
            strcpy(s2[j],temp);
         }
      }
    for (i=1;i<word_count;i++){
        printf("%s\n",s2[i]);
    }
    printf("%s",s2[word_count]);

    return 0;
}

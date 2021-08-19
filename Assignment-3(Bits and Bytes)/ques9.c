/*
 * Solution to Question-9 in C
 * @Harshit Sharma , 1910990073
 * Resources: Hackerrank discussions
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void transfer(char trans){
    if(trans <= 25){
        printf("%c",trans+65);
    }
    else if(trans <= 51){
        printf("%c",trans+71);
    }
    else if(trans <= 61){
        printf("%c",trans-4);
    }
    else if(trans == 62){
        printf("+");
    }
    else printf("/");
}

int main() {
    int n,m;
    scanf("%d",&n);
    getchar();
    for(m = 0; m < n; m++){
        char str[200];
        int i = 0;
        char c[4];
        scanf("%c",&c[0]);
        for(i = 0; i < 200; i++) str[i] = 0;
        i = 0;
        while(c[0]!='\n'){
            if(c[0] >= 'A' && c[0] <= 'Z') {c[0]-=65;}
            else if(c[0] == '=') {c[0] = 0;}
            else c[0]-=24;
            /*Load the first part*/
            int tmp = 5*i;
            int tsh;
            if(tmp%8 <= 3) str[tmp/8] = str[tmp/8]|(c[0]<<(3-tmp%8));
            else{
                str[tmp/8] = str[tmp/8]|(c[0]>>((tmp%8)-3));
                str[(tmp/8)+1] = c[0]<<(8-(tmp%8-3));
            }
            i++;
            scanf("%c",&c[0]);
            if(c[0] >= 'A' && c[0] <= 'Z');
            else if(c[0] == '=');
            else if(c[0] >= '2' && c[0] <= '9');
            else c[0] = '\n';
        }
        for(i = 0; i < (strlen(str)/3); i++){
            char d[3];
            char trans;
            d[0] = str[3*i];
            d[1] = str[3*i+1];
            d[2] = str[3*i+2];
            trans = 0;
            trans = d[0] >> 2;
            transfer(trans);
            trans = 0;
            trans = ((d[0] << 4) | (d[1] >> 4)) & 0x3F;
            transfer(trans);
            trans = 0;
            trans = ((d[1]<<2) | (d[2]>>6)) & 0x3F;
            transfer(trans);
            trans = d[2] & 0x3F;
            transfer(trans);
        }
        if(strlen(str)%3 != 0){
            char d[3];
            char trans;
            d[0] = str[3*i];
            d[1] = str[3*i+1];
            d[2] = str[3*i+2];
            trans = 0;
            trans = d[0] >> 2;
            transfer(trans);
            trans = 0;
            trans = ((d[0] << 4) | (d[1] >> 4)) & 0x3F;
            transfer(trans);
            trans = 0;
            if(d[1] == '\0'){
                printf("==");
            }
            else{
                trans = ((d[1]<<2) | (d[2]>>6)) & 0x3F;
                transfer(trans);
                if(d[2] == '\0') printf("=");
                else{
                    trans = d[2] & 0x3F;
                    transfer(trans);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
